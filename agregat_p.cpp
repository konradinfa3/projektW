#include "agregat_p.h"
#include "podorywkowy.h"


maszyna_z* agregat_p::zabuduj()
{
	return new podorywkowy();
}