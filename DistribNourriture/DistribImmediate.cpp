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

void DistribImmediate::EcrireLog(bool PasErreur, int ration)
{
	log = new TiXmlDocument("Log.xml");
	log->LoadFile();

	time_t t;
	time(&t); // t contient la date et l'heure courante
	struct tm *newTime1;
	newTime1 = localtime(&t);
	int heure = newTime1->tm_hour;		// Les heures sont dans "heures"
	int minute = newTime1->tm_min;		// Les minutes sont dans "minutes"
	int joursemaine = newTime1->tm_wday; //a transformer en chaine de charactere
	int jourmois = newTime1->tm_mday;
	int mois = newTime1->tm_mon;

	stringstream ss1, ss2,ss3,ss4, rat;

	ss1 << heure;
	ss2 << minute;
	ss3 << jourmois;
	ss4 << mois;
	//itoa(heure, h, 10); 
	//	itoa(minute, m, 10); //on transforme les entiers heure et minute en char h et m
	
	string he = ss1.str(); //on transfmorme les char h et m en string he et mi 
	string mi = ss2.str();
	string daymonth = ss3.str();
	string month = ss4.str();
	
	//h = to_string(heure); //pas supporté sur raspberry
	//m = to_string(minute);
	string hor = daymonth + '/' + month +' ' + he + ':' + mi;

	const char * horaire = hor.c_str(); // on transforme la string hor en char* horaire


	rat << ration;
	string rati = rat.str();
	const char * nbRation = rati.c_str();

	if (PasErreur == false)//il y a eu une erreur lors de la distribution
	{
		TiXmlElement* f = log->FirstChildElement();

		TiXmlElement element("HoraireIm");
		TiXmlText * text = new TiXmlText(horaire);
		element.LinkEndChild(text);
		f->InsertEndChild(element);

		TiXmlElement element2("RationIm");
		TiXmlText * text2 = new TiXmlText("Echec");
		element2.LinkEndChild(text2);
		f->InsertEndChild(element2);

	}
	else
	{
		TiXmlElement* f = log->FirstChildElement();

		TiXmlElement element("HoraireIm");
		TiXmlText * text = new TiXmlText(horaire);
		element.LinkEndChild(text);
		f->InsertEndChild(element);

		TiXmlElement element2("RationIm");
		TiXmlText * text2 = new TiXmlText(nbRation);
		element2.LinkEndChild(text2);
		f->InsertEndChild(element2);
	}

	log->SaveFile("Log.xml");
	delete log;
}

