#pragma once
#include <iostream>
using namespace std;

class maszyna_s
{
public:
	maszyna_s();
	virtual ~maszyna_s();
	char nazwa[20];
	char marka[20];
	char model[20];
	float rocznik;
	float moc;
	int stan;
};

