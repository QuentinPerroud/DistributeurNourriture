
#include "DistribParametree.h"
#include "DistribImmediate.h"

int main()
{

#ifndef TESTWINDOWS
	wiringPiSetup();
	pinMode(7, OUTPUT);
	cout << "pin initialee" << endl;
#endif
	DistribImmediate Rim;
	DistribParametree Param;
	Repas tabRepas[5];
	while (1)
	{
		cout << "dans la boucle" << endl;
		if (Rim.ChargerFichier("FichierRationIm.xml"))
		{
			if (Rim.VerifDate())
			{
				if (Rim.TraitementFichier())
				{
					cout << "Nouveau fichier de distrib Immediate detecte" << endl;
					int Ration = Rim.GetNbRation();
					Rim.EcrireLog(Rim.DistribNourriture(Ration), Ration);
					cout << "distrib imediate envoyee" << endl;
					cout << "log immediat ecrit" << endl;

				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////
		delay(1000);
		//////////////////////////////////////////////////////////////////////////////
		if (Param.ChargerFichier("FichierParametresXML.xml"))
		{
			if (Param.VerifDate())
			{
				if (Param.TraitementFichier())
				{
					cout << "Nouveau fichier de distrib parametrée detecte" << endl;
					const int nbRepas = Param.GetNbRepas();

					for (int i = 0; i < 5; i++)
					{
						tabRepas[i] = Param.GetTabRepas(i);
					}

				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////
		delay(1000);
		//////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 5; i++)
		{
			bool ok = Param.ComparerHeure(tabRepas[i].horaire.heure, tabRepas[i].horaire.minute);
			if (ok == true)
			{
				Param.EcrireLog(Param.DistribNourriture(tabRepas[i].nbRation), tabRepas[i].nbRation);
				cout << "distrib parametree envoye" << endl;
				cout << "log distri parametree" << endl;
			}
		}

		delay(30000);
	}
}
	
	
