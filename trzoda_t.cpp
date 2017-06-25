#include "trzoda_t.h"
#include "tucznik.h"


obsada* trzoda_t::produkuj()
{
	return new tucznik();
}
