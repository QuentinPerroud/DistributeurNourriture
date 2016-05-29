
#include "DistribParametree.h"
#include "DistribImmediate.h"

int main()
{
	
//date_derniere_modif = 1/01/1980 1:00:00
	// tant que infini
	//		attendre une seconde
	//		charger fichier
	//		si date_modif_fichier plus recente que date_derniere_modif (la date est ecrite dans le fichier XML)
	//			date_derniere_modif = date_modif_fichier
	//			traiter fichier

	
	wiringPiSetup();
	pinMode(7, OUTPUT);
	cout << "pin initialee" << endl;
	DistribImmediate Rim;
	DistribParametree Param;
	Repas tabRepas[5];
	while (1)
	{
		cout << "dans la boucle" << endl;
		if (Rim.ChargerFichier("FichierRationIm.xml"))
		{
			cout << "fichiercharge" << endl;
			if (Rim.VerifDate())
			{
				//cout << "verfidate" << endl ;
				if (Rim.TraitementFichier())
				{
					cout << "traitefichier" << endl;
					int Ration = Rim.GetNbRation();
					Rim.DistribNourriture(Ration);
					cout <<"fin"<<endl;
				}
			}
		}
		delay(1000);
		if (Param.ChargerFichier("FichierParametresXML.xml"))
		{
			if (Param.VerifDate())
			{
				if (Param.TraitementFichier())
				{
					const int nbRepas = Param.GetNbRepas();
					
					for (int i = 0; i < 5; i++)
					{
						tabRepas[i] = Param.GetTabRepas(i);
					}
									
				}
			}
		}
		delay(1000);

		for (int i = 0; i < 5; i++)
		{
			if (Param.ComparerHeure(tabRepas[i].horaire.heure, tabRepas[i].horaire.minute))
			{
				Param.DistribNourriture(tabRepas[i].nbRation);
			}
		}


	}
	
	
	
}

