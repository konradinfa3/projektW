#pragma once
#include "maszyna_z.h"

class podorywkowy : public maszyna_z
{
public:
	podorywkowy();
	virtual ~podorywkowy();
	char nazwa[20];
	char marka[20];
	char model[20];
	char funkcja[20];
	int stan;
};

