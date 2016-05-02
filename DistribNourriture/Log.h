#pragma once
#include "Header.h"
class Log
{
	TiXmlDocument *doc;
public:

	Log();
	~Log();
	bool ChargerFichier(const char * Nomfichier);
	void EcrireLogParam(bool presenceErreur);
	void EcrireLogImmediat(bool presenceErreur);
};

