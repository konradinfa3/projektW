#pragma once
#include <iostream>
#include <process.h>
using namespace std;

class obsada
{
public:
	obsada();
	virtual ~obsada();
	char nazwa[20];
	char rasa[20];
	char plec[20];
	float wiek;
	float masa;
	int stan;
};

