/*Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). Deklarirati strukturu Poligon koja se
sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima:
Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y koordinata i stvara novi poligon koji će 
kao vrhove imati parove brojeva iz nizova. Nizovi su dužine n (≥ 3).
Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na vrhove poligona kojima su obje koordinate pozitivne.
Broj elemenata u nizu će biti spremljen u np parametar.*/

#include <stdlib.h>
#include <stdio.h>
typedef struct {
    float x;
    float y;
}Tocka;

typedef struct {
    Tocka* vrh;
    int n;
}Polygon;

Polygon* novi_poligon(float* niz_x, float* niz_y, int n)
{
    Polygon* myPoly = (Polygon*)malloc(sizeof(Polygon));
    if (!myPoly) return NULL;

    myPoly->vrh = (Tocka*)malloc(n * sizeof(Tocka));
    if (!myPoly->vrh) return NULL;

    for (int i = 0; i < n; i++)
    {
        myPoly->vrh[i].x = niz_x[i];
        myPoly->vrh[i].y = niz_y[i];
    }

    return myPoly;
}
Tocka** pozitivni(Polygon* p, int* np)
{
    int brojac = 0;

    for (int i = 0; i < (p->n); i++){
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0)) brojac++;
    }

    Tocka** pt = (Tocka**)malloc(sizeof(Tocka*) * brojac);
    if (!pt) return NULL;

    for (int i = 0, j = 0; i < (p->n); i++)
    {
        if ((p->vrh[i].x > 0) && (p->vrh[i].y > 0)) {
            pt[j] = &(p->vrh[i]);
            j++;
        }
    }

    *np = brojac;
    return pt;
}

int main()
{
    float nizX[] = { 2.1, -4.2, 6.4, 8.6 };
    float nizY[] = { 1.2, 2.4, 4.6, 6.8 };
    int n = sizeof(nizX) / sizeof(nizX[0]);
    int nn;
    Tocka** pt;
    Polygon* myPoly = novi_poligon(nizX, nizY, n);
    myPoly->n = n;

    printf("Koordinate poligona:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, %d\n", &myPoly->vrh[i].x, &myPoly->vrh[i].y);
        printf("x: %0.2f, y: %0.2f\n", myPoly->vrh[i].x, myPoly->vrh[i].y);
    }

    pt = pozitivni(myPoly, &nn);
    for (int i = 0; i < nn; i++)
    {
        printf("%d \n", pt[i]);
    }

    free(pt);
    free(myPoly->vrh);
    free(myPoly);
    return 0;
}
