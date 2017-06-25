#pragma once
#include "maszyna_s.h"

class zetor : public maszyna_s
{
public:
	zetor();
	virtual ~zetor();
	char nazwa [20];
	char marka[20];
	char model[20];
	float rocznik;
	float moc;
	int stan;
};

