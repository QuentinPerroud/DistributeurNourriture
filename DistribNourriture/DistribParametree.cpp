
#include "DistribParametree.h"

DistribParametree::DistribParametree()
{
	nbrepas = 0;
	for (int i = 0; i <= 5; i++)
	{
		tabRepas[i].horaire.heure = 0;
		tabRepas[i].horaire.minute = 0;
		tabRepas[i].nbRation = 0;
	}
}

DistribParametree::~DistribParametree()
{
}

bool DistribParametree::TraitementFichier()
{
	if (doc == 0) //si le fichier n'est pas chargé, impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier a été chargé au préalable
	{
		string nbrepas1, horaire, ration, h, min; // variable temporaire

		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement()->NextSiblingElement();
		nbrepas1 = elem->GetText(); // reccuperation du nombre de repas en string
		nbrepas = stoi(nbrepas1, NULL, 10); // attribut de la classe a partir de la variable temp string
		elem = elem->NextSiblingElement();//itteration
		int i = 0;

		while (elem) {

			horaire = elem->GetText();//string
			h = horaire.substr(0, 2);//on recupere l'heure a partir des 2 premier char de la string horaire
			min = horaire.substr(2, 2);//on recupere les minutes avec les deux dernier char
			const char* he = h.c_str();
			const char* mi = min.c_str();
			tabRepas[i].horaire.heure = atoi(he);//conversion et stockage dans la classe
			tabRepas[i].horaire.minute = atoi(mi);//conversion et stockage dans la classe
															 //traiter la string en 2 : 2 premier char = heure, 2 dernier = minute
			elem = elem->NextSiblingElement();//itteration

			ration = elem->GetText();//string
			const char* ra = ration.c_str();
			tabRepas[i].nbRation = atoi(ra);//attribut en int depuis string
			elem = elem->NextSiblingElement();//itteration
			i++;
			
		}
		return true;
	}
	
	
}


////////////////////////////////////////////accesseur//////////////////////////////////

int DistribParametree::GetNbRepas()
{
	return nbrepas;
}

Repas DistribParametree::GetTabRepas(int i)
{
	return tabRepas[i];
}