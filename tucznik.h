#pragma once
#include "obsada.h"

class tucznik : public obsada
{
public:
	tucznik();
	virtual ~tucznik();
	
	char nazwa[20];
	char rasa[20];
	char plec[20];
	float wiek;
	float masa;
	int stan;
};

