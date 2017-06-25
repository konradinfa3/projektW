#pragma once
#include "ziemia.h"

class pole : public ziemia
{
public:
	pole();
	virtual ~pole();
	float powierzchnia;
	float nrdzialki;
	char uprawa[20];
	int stan;
};

