
#include "DistribParametree.h"

DistribParametree::DistribParametree()
{
	nbrepas = 0;
	for (int i = 0; i <= 4 ; i++)
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
		const char* nbrepas1; // variable temporaire
		const char* ration;
		string horaire, h, min;
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement()->NextSiblingElement();

		nbrepas1 = elem->GetText(); // reccuperation du nombre de repas en string
		nbrepas = atoi(nbrepas1); // attribut de la classe a partir de la variable temp string

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
			tabRepas[i].nbRation = atoi(ration);//attribut en int depuis string
			elem = elem->NextSiblingElement();//itteration
			i++;
			
		}
		return true;
	}
	
	
}

bool DistribParametree::ComparerHeure(int heureParam, int  minuteParam)
{
	time_t t;
	time(&t); // t contient la date et l'heure courante
	struct tm *newTime1;
	newTime1 = localtime(&t);
	int heure = newTime1->tm_hour;		// Les heures sont dans "heures"
	int minute = newTime1->tm_min;		// Les minutes sont dans "minutes"
	
	if (heureParam == heure)
		if (minuteParam == minute)
			return true;
		else return false;
}

void DistribParametree::EcrireLog(bool PresenceErreur, int ration)
{
	log = new TiXmlDocument("Log.xml");
	log->LoadFile();

	time_t t;
	time(&t); // t contient la date et l'heure courante
	struct tm *newTime1;
	newTime1 = localtime(&t);
	int heure = newTime1->tm_hour;		// Les heures sont dans "heures"
	int minute = newTime1->tm_min;		// Les minutes sont dans "minutes"

	char  h[3];
	char m[3];
	itoa(heure, h, 10); 
	itoa(minute, m, 10); //on transforme les entiers heure et minute en char h et m
	string he(h), mi(m); //on transfmorme les char h et m en string he et mi 
	//h = to_string(heure); //pas supporté sur raspberry
	//m = to_string(minute);
	string hor = he + ':' + mi;

	const char * horaire = hor.c_str(); // on transforme la string hor en char* horaire


	char nbRation[2];
	itoa(ration, nbRation, 10);

	if (PresenceErreur == true)//il y a eu une erreur lors de la distribution
	{
		TiXmlElement* f = log->FirstChildElement();

		TiXmlElement element("Horaire");
		TiXmlText * text = new TiXmlText(horaire);
		element.LinkEndChild(text);
		f->InsertEndChild(element);

		TiXmlElement element2("Ration");
		TiXmlText * text2 = new TiXmlText("Echec");
		element2.LinkEndChild(text2);
		f->InsertEndChild(element2);

	}
	else
	{
		TiXmlElement* f = log->FirstChildElement();

		TiXmlElement element("Horaire");
		TiXmlText * text = new TiXmlText(horaire);
		element.LinkEndChild(text);
		f->InsertEndChild(element);

		TiXmlElement element2("Ration");
		TiXmlText * text2 = new TiXmlText(nbRation);
		element2.LinkEndChild(text2);
		f->InsertEndChild(element2);
	}

	log->SaveFile("Log.xml");
	delete log;
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
