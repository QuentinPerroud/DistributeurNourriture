#ifndef DISTRIBREPAS_H
#define DISTRIBREPAS_H
#include "Header.h"

class DistribRepas
{
public:


	DistribRepas();
	~DistribRepas();
	virtual bool TraitementFichier() = 0;

	bool VerifDate();
	void DistribNourriture(int ration);
	//Charge un fichier xml dans un objet de type TiXmlDocument
	//parametre d'entr�e : Nom du fichier XML
	//Parametre de sortie : l'objet TiXmlDocument
	bool ChargerFichier(const char * Nomfichier);
protected : 
	TiXmlDocument *doc;
	string DateDerniereModif;

	
	
};

#endif