/*int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela.
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.*/
#include <stdio.h>
#include<stdlib.h>

int** podijeli(int* niz, int n)
{
	int** pp;
	int j = 0;
	int len1 = n / 2;
	int len2 = n - len1;
	int* niz1 = (int*)malloc(sizeof(int) * len1);
	if (!niz1) return NULL;
	int* niz2 = (int*)malloc(sizeof(int) * len2);
	if (!niz2) return NULL;
	pp = (int**)malloc(sizeof(int*) * 2);
	if (!pp) return NULL;
	for (int i = 0; i < n; i++, j++){
		while (i < len1){
			niz1[i] = niz[i];
			i++;
		}
		niz2[j] = niz[i];
	}
	pp[0] = niz1;
	pp[1] = niz2;
	printf("\n");
	return pp;
}

int main()
{
	int niz[] = { 22, 1, 7, 12, 13, 21, 24, 27, 32, 41, 57};
	int n = sizeof(niz) / sizeof(niz[0]);
	int** pp = podijeli(niz, n);
	for (int i = 0; i < 2; i++) {
		printf("%d\n", pp[i]);
		free(pp[i]);
	}
	free(pp);
}

