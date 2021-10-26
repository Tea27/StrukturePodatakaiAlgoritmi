/*int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.*/
#include <stdio.h>
#include<stdlib.h>

int* podniz(int* niz, int start, int stop)
{
    int i;
    int n = stop - start;
    int* noviNiz = (int*)malloc(sizeof(int) * (n));
    if (!noviNiz){
        return NULL;
    }
    for (i = 0; i < n; start++, i++){
        noviNiz[i] = niz[start];
    }
    return noviNiz;
}

int main()
{
    int i;
    int niz[] = { 10, 11, 22, 43, 23, 27, 1 , 7, 18, 78, 3};
    int* noviNiz = podniz(niz, 2, 8);
    if (!noviNiz) return -1;

    for (i = 0; i < 6; i++)
    {
        printf("%d ", noviNiz[i]);
    }
    free(noviNiz);
    return 0;
}
