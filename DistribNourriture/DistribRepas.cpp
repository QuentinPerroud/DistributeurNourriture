#include "DistribRepas.h"
#include <string>

using namespace std;


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
	/*if (doc == 0) //si le fichier n'est pas charge impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier */
 
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement();
		string dateFichier = elem->GetText();


	if (DateDerniereModif < dateFichier )
		{
			DateDerniereModif = dateFichier;
			
			return true;
		}
		else
		{
	
			return false;
		}

}

bool DistribRepas::DistribNourriture(int ration)
{
	while (ration != 0)
	{
		#ifndef TESTWINDOWS
		digitalWrite(7, 1);
		delay(1000);
		digitalWrite(7, 0);
		delay(1000);
#else
		cout << "distribution dune ration" << endl;
#endif
		ration--;
	}
	return true;
}

bool DistribRepas::ChargerFichier(const char * Nomfichier)
{
	doc = new TiXmlDocument(Nomfichier);

	if (!doc->LoadFile())
	{
		cout << "fichier pas charge"<<endl;
		return false;
	}
	else
	{
		return true;
	}
}
