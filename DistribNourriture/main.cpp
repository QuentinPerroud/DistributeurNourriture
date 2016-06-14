
#include "DistribParametree.h"
#include "DistribImmediate.h"

int main()
{

#ifndef TESTWINDOWS
	wiringPiSetup();
	pinMode(7, OUTPUT);
	cout << "pin initialisee" << endl;
#endif
	DistribImmediate Rim; 
	DistribParametree Param; // initialisation des objets qui vont geré les distribution
	Repas tabRepas[5]; //initialisation d'un tableau de repas
	while (1)//boucle toujurs vraie
	{
		cout << "debut de la boucle" << endl;
//////////////////////////////////////////////Distribution Immediate//////////////////////////////////////////////////////
		if (Rim.ChargerFichier("FichierRationIm.xml"))//on charge le fichier xml dans l'objet Rim
		{
			if (Rim.VerifDate())//on verifie si la date ecrite au debut du fichier xml est plus recente que la date en attribut de l'objet 
			{
				if (Rim.TraitementFichier())//si le fichier est récent, on le traite pour recuperer les données qu'il contient
				{
					
					cout << "Nouveau fichier de distrib Immediate detecte" << endl;
					int Ration = Rim.GetNbRation(); // on recupere le nombre de ration à distribuer
					Rim.EcrireLog(Rim.DistribNourriture(Ration), Ration);//on apelle la methode qui ecrit les logs avec en parametre la valeur de retour de la methode chargé de distribuer la nourriture et le nombre de ration 
					cout << "distrib imediate envoyee" << endl;
					cout << "log immediat ecrit" << endl;

				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////
		delay(1000);
		////////////////////////////////Distribution parametrée//////////////////////////////////////////////////////////
		if (Param.ChargerFichier("FichierParametresXML.xml"))//on charge le fichier xml dans l'objet Param
		{
			if (Param.VerifDate())//on verifie si la date ecrite au debut du fichier xml est plus recente que la date en attribut de l'objet 
			{
				if (Param.TraitementFichier()) //si le fichier est récent, on le traite pour recuperer les données qu'il contient
				{
					cout << "Nouveau fichier de distrib parametrée detecte" << endl;
					const int nbRepas = Param.GetNbRepas();

					for (int i = 0; i < 5; i++)//on recupere dans le tableau de repas du main le tableau de repas contenu dans Param
					{
						tabRepas[i] = Param.GetTabRepas(i);
					}

				}
			}
		}
		//////////////////////////////////Distribution de la nourriture aux horaires voulu////////////////////////////////////////////
		delay(1000);
		//////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 5; i++)
		{
			bool ok = Param.ComparerHeure(tabRepas[i].horaire.heure, tabRepas[i].horaire.minute);//la maethode compare l'heure donnée en parametre avec l'heure du systeme
			if (ok == true)
			{
				Param.EcrireLog(Param.DistribNourriture(tabRepas[i].nbRation), tabRepas[i].nbRation);//distribution de la nourriture avec l'ecriture des logs
				cout << "distrib parametree envoye" << endl;
				cout << "log distri parametree" << endl;
			}
		}

		delay(30000);
	}
}
	
	
