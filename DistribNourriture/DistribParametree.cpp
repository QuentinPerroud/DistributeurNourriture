
#include "DistribParametree.h"
//constructeur, initialise tout les attributs � 0
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
	if (doc == 0) //si le fichier n'est pas charg�, impossible de le traiter, return false
	{
		return false;
	}
	else //le fichier a �t� charg� au pr�alable
	{
		const char* nbrepas1; // variable temporaire
		const char* ration;
		string horaire, h, min;
		TiXmlElement *elem = doc->FirstChildElement()->FirstChildElement()->NextSiblingElement();//on se positionne apres la ligne correspondant � la date de derniere modif

		nbrepas1 = elem->GetText(); // reccuperation du nombre de repas en string
		nbrepas = atoi(nbrepas1); // l'attribut de la classe est un int. conversion de la string nbrepas1 en int //cet attribut n'est plus utilis� mais on a d�cid� de le laisser au cas o� on en ait besoin.

		elem = elem->NextSiblingElement();//itteration
		
		int i = 0;
		while (elem) {
			if( i < 5)
			{
				horaire = elem->GetText();//string
				h = horaire.substr(0, 2);//on recupere l'heure a partir des 2 premier char de la string horaire
				min = horaire.substr(2, 2);//on recupere les minutes avec les deux dernier char
				const char* he = h.c_str();
				const char* mi = min.c_str();//conversion des string en const char*
				tabRepas[i].horaire.heure = atoi(he);//conversion en int et stockage dans la classe
				tabRepas[i].horaire.minute = atoi(mi);//conversion en int et stockage dans la classe
																 //traiter la string en 2 : 2 premier char = heure, 2 dernier = minute
				elem = elem->NextSiblingElement();//itteration

				ration = elem->GetText();//string
				tabRepas[i].nbRation = atoi(ration);//attribut en int depuis string
				elem = elem->NextSiblingElement();//itteration
				i++;
			}
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
	{
	
		if (minuteParam == minute) 
		{
			cout << "comparerHeure : vrai" << endl;
			delay(1000);
			return true;
		}
		else
		{
			cout << "comparerHeure : faux" << endl;
			delay(1000);
			return false;
		}
	}
	else
	{
		cout << "comparerHeure : faux" << endl;
		delay(1000);
		return false;
	}
}

void DistribParametree::EcrireLog(bool PasErreur, int ration)
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
	mois++;
	//on recupere toute les informations concernant la date et l'heure dans des int
	stringstream ss1, ss2, ss3, ss4, rat;

	ss1 << heure;
	ss2 << minute;
	ss3 << jourmois;
	ss4 << mois;
	

	string he = ss1.str(); 
	string mi = ss2.str();
	string daymonth = ss3.str();
	string month = ss4.str();//on met les int dans des string pour faciliter la manipulatin des chaines de charactere

	
	string hor = daymonth + '/' + month + ' ' + he + ':' + mi;

	const char * horaire = hor.c_str(); // on transforme la string hor en char* horaire


	
	rat << ration;
	string rati = rat.str();
	const char * nbRation = rati.c_str();//De la meme fa�on que au dessus. on convertit ration qui est un int en const char*

	if (PasErreur == false)//il y a eu une erreur lors de la distribution
	{
		TiXmlElement* f = log->FirstChildElement();//ecriture des logs � la fin du fichier

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
		TiXmlElement* f = log->FirstChildElement();//ecriture des logs � la fin du fichier

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
