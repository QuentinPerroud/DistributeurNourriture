#ifndef DISTRIBIMMEDIATE_H
#define DISTRIBIMMEDIATE_H

#include "Header.h"
#include "DistribRepas.h"

class DistribImmediate : public DistribRepas
{
public:

	DistribImmediate();
	~DistribImmediate();

	//Traite un fichier texte pour en extraire les données qu'il contient : nb de repas, Horaires, nb de rations
	//parametre de sortie : true si succes, false si echec
	bool TraitementFichier();
	
	int GetNbRation();

	//ecrit dans le fichier log si la distribution immediate à reussi ou non, à quelle heure et le nombre de ration envoyés bla bla
	void EcrireLog(bool PasErreur, int ration);

private:

	int nbRation;
	

	
};

#endif