#include "DistribRepas.h"



DistribRepas::DistribRepas()
{
	doc = 0;
	DateDerniereModif = "00-00-00 00:00:00";
}


DistribRepas::~DistribRepas()
{
	delete doc;
}

bool DistribRepas::VerifDate()
{
	if (doc == 0) //si le fichier n'est pas chargé, impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier a été chargé au préalable
	{
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement();
		string dateFichier = elem->GetText();

		if (dateFichier > DateDerniereModif)
		{
			DateDerniereModif = dateFichier;
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool DistribRepas::DistribNourriture(int ration)
{
	while (ration != 0)
	{
		digitalWrite(4, 1);
		delay(1000);
		digitalWrite(4, 0);
		ration--;
	}
	return false;
}

bool DistribRepas::ChargerFichier(const char * Nomfichier)
{
	doc = new TiXmlDocument(Nomfichier);

	if (!doc->LoadFile())
	{
		return false;
	}
	else
	{
		return true;
	}
}
