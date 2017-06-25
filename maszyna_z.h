#pragma once
#include <iostream>
using namespace std;

class maszyna_z
{
public:
	maszyna_z();
	virtual ~maszyna_z();
	char nazwa[20];
	char marka[20];
	char model[20];
	char funkcja[20];
	int stan;
};

