#pragma once
#include "maszyna_s.h"

class producent_s
{
public:
	virtual maszyna_s* zbuduj()=0;
	virtual ~producent_s(){}
};

