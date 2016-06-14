#pragma once
#include "Header.h"
#include "DistribRepas.h"


struct Horaire
{
	int heure;
	int minute;
};

struct Repas
{
	int nbRation;
	Horaire horaire;
};

class DistribParametree : public DistribRepas
{
public:

	DistribParametree();
	
	~DistribParametree();

	//Traite un fichier texte pour en extraire les données qu'il contient : nb de repas, Horaires, nb de rations
	//parametre de sortie : true si succes, false si echec
	bool TraitementFichier();

	bool ComparerHeure(int heureParam, int minuteParam);
	void EcrireLog(bool PasErreur, int ration);
	///////////////////////////////////Methodes d'acces//////////////////////////////////

	//Retourne la valeur NbRepas
	int GetNbRepas();
	
	//retourne le repas correspondant a l'indexe i
	Repas GetTabRepas(int i);
	
private:

	int nbrepas;
	Repas tabRepas[5]; // creation d'un tableau de repas

	
};


