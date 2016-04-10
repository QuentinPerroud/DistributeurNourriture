#pragma once
#include "Header.h"

class DistribRepas
{
public:


	DistribRepas();
	~DistribRepas();
	virtual bool TraitementFichier() = 0;

	bool VerifDate();
	bool DistribNourriture(int ration);
	//Charge un fichier xml dans un objet de type TiXmlDocument
	//parametre d'entrée : Nom du fichier XML
	//Parametre de sortie : l'objet TiXmlDocument
	bool ChargerFichier(const char * Nomfichier);
protected : 
	TiXmlDocument *doc;
	string DateDerniereModif;

	
	
};
