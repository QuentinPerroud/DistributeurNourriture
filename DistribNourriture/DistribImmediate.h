#ifndef DISTRIBIMMEDIATE_H
#define DISTRIBIMMEDIATE_H

#include "Header.h"
#include "DistribRepas.h"

class DistribImmediate : public DistribRepas
{
public:

	DistribImmediate();
	~DistribImmediate();

	//Traite un fichier texte pour en extraire les donn�es qu'il contient : nb de repas, Horaires, nb de rations
	//parametre de sortie : true si succes, false si echec
	bool TraitementFichier();
	int GetNbRation();

private:

	int nbRation;
	

	
};

#endif