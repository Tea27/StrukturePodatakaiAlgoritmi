#include <stdlib.h>
#include "myObject.h"

int main()
{
	Objekt3D* objekt = vratiObjekt();
    zapisiBinarnu(objekt);
    zapisiTekstualnu(objekt);
    izbrisi(objekt);
    return 0;
}

