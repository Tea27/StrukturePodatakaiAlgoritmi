#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>

typedef struct {
	float x, y, z;
} Vrh;

typedef struct {
	Vrh normala, vrh1, vrh2, vrh3;
	unsigned short boja;
} Trokut;

typedef struct {
	Trokut* nizTrokuta;
	int brojTrokuta;
} Objekt3D;

Objekt3D* vratiObjekt();
void zapisiTekstualnu(Objekt3D* objekt);
void zapisiBinarnu(Objekt3D* objekt);
void izbrisi(Objekt3D* objekt);