#include "traktor_z.h"
#include "zetor.h"


maszyna_s* traktor_z::zbuduj()
{
	return new zetor();
}