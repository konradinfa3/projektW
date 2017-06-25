#pragma once
#include "maszyna_z.h"

class producent_z
{
public:
	virtual maszyna_z* zabuduj()=0;
	virtual ~producent_z(){}
};

