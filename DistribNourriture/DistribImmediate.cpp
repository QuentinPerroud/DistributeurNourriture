#include "DistribImmediate.h"



DistribImmediate::DistribImmediate()
{
}


DistribImmediate::~DistribImmediate()
{
}

bool DistribImmediate::TraitementFichier()
{
	if (doc == 0) //si le fichier n'est pas chargé, impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier a été chargé au préalable
	{
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement()->NextSiblingElement();
		const char* ra = elem->GetText();
		nbRation = atoi(ra);
		return true;
		cout << nbRation << endl;
	}
}

int DistribImmediate::GetNbRation() 
{
	return nbRation;
}

