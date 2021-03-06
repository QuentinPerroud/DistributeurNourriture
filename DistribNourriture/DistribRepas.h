#ifndef DISTRIBREPAS_H
#define DISTRIBREPAS_H
#include "Header.h"

class DistribRepas
{
public:


	DistribRepas();
	~DistribRepas();
	
	virtual bool TraitementFichier() = 0;

	virtual void EcrireLog(bool PasErreur, int ration) = 0;

	//Verifie la date contenu au debut du fichier xml avec la DateDerniereModif en attribut de l'objet. permet de verifier si le fichier trait� est r�cent ou non
	//retourne vrai si le fichier est recent, faux si il ne l'est pas.
	bool VerifDate();

	//distribue la nourriture pour x nombres de ration en parametre
	bool DistribNourriture(int ration);

	//Charge un fichier xml dans un objet de type TiXmlDocument
	//parametre d'entr�e : Nom du fichier XML
	//Parametre de sortie : l'objet TiXmlDocument
	bool ChargerFichier(const char * Nomfichier);
	
protected : 
	TiXmlDocument* doc;
	TiXmlDocument*	log;
	string DateDerniereModif;

	
	
};

#endif