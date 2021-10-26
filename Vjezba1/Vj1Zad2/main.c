/*int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz koji sadrži brojeve iz originalnog niza koji su manji od th.
Originalni niz ima dužinu n. Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. */
#include <stdlib.h>
#include <stdio.h>

int* filtriraj(int* niz, int n, int th, int* nth)
{
    int brojac = 0, i, j;
    for (i = 0; i < n; i++)
    {
        if (niz[i] < th) brojac++;
    }
    *nth = brojac;

    int* noviNiz = (int*)malloc(sizeof(int) * (*nth));
    if (!noviNiz) return NULL;

    for (i = 0, j = 0; i < n; i++)
    {
        if (niz[i] < th)
        {
            noviNiz[j] = niz[i];
            j++;
        }
    }
    return noviNiz;
}

int main(void)
{
    int niz[] = { 22, 21, 2, 3, 5, 33, 27, 44, 47, 1};
    int nsz, n, th, i;
    th = 22;
    n = sizeof(niz) / sizeof(niz[0]);
    int* noviNiz = filtriraj(niz, n, th, &nsz);
    for (i = 0; i < nsz; i++) {
        printf("%d ", noviNiz[i]);
    }
    free(noviNiz);
}

