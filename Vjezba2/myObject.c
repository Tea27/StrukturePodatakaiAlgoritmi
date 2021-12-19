#include <stdio.h>
#include <stdlib.h>
#include "myObject.h"

Objekt3D* vratiObjekt() {
    int n = 0;
    FILE* fp = fopen("primjerbin.stl", "rb");
    if (!fp) {
        perror("greska!");
        return NULL;
    }

    fseek(fp, 80, SEEK_SET);
    fread(&n, sizeof(int), 1, fp);

    Objekt3D* noviObjekt = (Objekt3D*)malloc(sizeof(Objekt3D));
    noviObjekt->brojTrokuta = n;

    Trokut* niz = (Trokut*)malloc(noviObjekt->brojTrokuta * sizeof(Trokut));

    for (int i = 0;i < (noviObjekt->brojTrokuta);i++){
        fread(&(niz[i]), 50, 1, fp);
    }

    noviObjekt->nizTrokuta = niz;
    fclose(fp);

    return noviObjekt;
}

void zapisiTekstualnu(Objekt3D* objekt)
{
    FILE* fp = fopen("tekstualna.stl", "wt");
    if (!fp){
        perror("greska");
        return;
    }

    fprintf(fp, "solid \n");
    for (int i = 0;i < (objekt->brojTrokuta);i++)
    {
        fprintf(fp, "facet normal %f %f %f\n", objekt->nizTrokuta[i].normala.x, objekt->nizTrokuta[i].normala.y, objekt->nizTrokuta[i].normala.z);
        fprintf(fp, "   outer loop\n");
        fprintf(fp, "       vertex %f %f %f\n", objekt->nizTrokuta[i].vrh1.x, objekt->nizTrokuta[i].vrh1.y, objekt->nizTrokuta[i].vrh1.z);
        fprintf(fp, "       vertex %f %f %f\n", objekt->nizTrokuta[i].vrh2.x, objekt->nizTrokuta[i].vrh2.y, objekt->nizTrokuta[i].vrh2.z);
        fprintf(fp, "       vertex %f %f %f\n", objekt->nizTrokuta[i].vrh3.x, objekt->nizTrokuta[i].vrh3.y, objekt->nizTrokuta[i].vrh3.z);
        fprintf(fp, "   endloop\n");
        fprintf(fp, "endfacet\n");
    }
    fprintf(fp, "endsolid \n");
    fclose(fp);
}
void zapisiBinarnu(Objekt3D* objekt)
{
    char buffer[80] = { 0 };
    FILE* fp = fopen("binarna.stl", "wb");
    if (!fp){
        perror("greska");
        return;
    }

    fwrite(buffer, sizeof(char), 80, fp);
    fwrite(&(objekt->brojTrokuta), sizeof(int), 1, fp);

    for (int i = 0;i < objekt->brojTrokuta;i++){
        fwrite(&(objekt->nizTrokuta[i]), 50, 1, fp);
    }
    fclose(fp);
}

void izbrisi(Objekt3D* objekt)
{
    free(objekt->nizTrokuta);
    free(objekt);
}

