#include "DistribImmediate.h"



DistribImmediate::DistribImmediate()
{
nbRation = 0;
}


DistribImmediate::~DistribImmediate()
{
}

bool DistribImmediate::TraitementFichier()
{
	if (doc == 0) //si le fichier n'est pas charg�, impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier a �t� charg� au pr�alable
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

void DistribImmediate::EcrireLog(bool PresenceErreur)
{
}

