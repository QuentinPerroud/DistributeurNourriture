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
 
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement();
		string dateFichier = elem->GetText();//on recupere la date contenue dans le fichier


	if (DateDerniereModif < dateFichier )//on compare la date avec celle en attribut de la classe
		{
			DateDerniereModif = dateFichier; // si la date lu est plus recente, la date contenue dans la classe prends cette valeur
			
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
		digitalWrite(7, 1);//envoi d'un signal au relai
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
