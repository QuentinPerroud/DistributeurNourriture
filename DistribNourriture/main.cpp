
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
	pinMode(4, OUTPUT);
	DistribImmediate Rim;
	DistribParametree Param;
	while (true)
	{
		
		if (Rim.ChargerFichier("FichierRationIm.xml"))
		{
			if (Rim.VerifDate())
			{
				if (Rim.TraitementFichier())
				{
					int Ration = Rim.GetNbRation();
					Rim.DistribNourriture(Ration);
				}
			}
		}
		//delay(1000);
		if (Param.ChargerFichier("FichierParametresXML.xml"))
		{
			if (Param.VerifDate())
			{
				if (Param.TraitementFichier())
				{
					const int nbRepas = Param.GetNbRepas();
					Repas tabRepas[5];
					for (int i = 0; i < 5; i++)
					{
						tabRepas[i] = Param.GetTabRepas(i);
					}
					//appelle fonction de comparaison d'heure
					//si return true, appelle distrib nourriture avec nb ration correspondant				
				}
			}
		}
		//delay(1000);
	}
	
	
	
	

	

	
	
	
}

