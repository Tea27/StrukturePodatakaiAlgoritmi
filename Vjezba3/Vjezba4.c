/*•	presjek_jedan_sortiran(skupA, skupB) – funkcija računa presjek dva skupa, gdje je skupB sortirani
niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije (iz stdlib.h)*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
void print(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}


int* presjek(int* skupA, int* skupB, int n1, int n2, int* n3) {
	int* presjek;
	int k = 0;

	*n3 = max(n1, n2);

	presjek = (int*)malloc(sizeof(int) * (*n3));
	
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (skupA[i] == skupB[j]) {
				presjek[k] = skupA[i];
				k++;
			}
		}
	}

	presjek = (int*)realloc(presjek, k * sizeof(int));
	*n3 = k;

	return presjek;
}

int comparator(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* presjek_jedan_sortiran(int* skupA,int* skupB, int n1, int n2, int* n3) {
	int* presjek, pItem;
	int k = 0;

	*n3 = max(n1, n2);

	presjek = (int*)malloc(sizeof(int) * (*n3));

	qsort(skupB, n2, sizeof(skupB[0]), comparator);
	
	for (int i = 0; i < n1; i++) {
		pItem = (int*)(bsearch(&skupA[i], skupB, n2, sizeof(int), comparator));
		if(pItem != NULL) {
			presjek[k] = skupA[i];
			k++;
		}
	}

	presjek = (int*)realloc(presjek, k * sizeof(int));
	*n3 = k;

	return presjek;
}

int* presjek_oba_sortirana(int* skupA, int* skupB, int n1, int n2, int* n3) {
	int* presjek, pItem;
	int i, j, k;
	
	*n3 = max(n1, n2);

	presjek = (int*)malloc(sizeof(int) * (*n3));

	qsort(skupB, n2, sizeof(skupB[0]), comparator);
	qsort(skupA, n2, sizeof(skupA[0]), comparator);

	i = j = k = 0;
	while (i < n1 && j < n2) {
		if (skupA[i] == skupB[j]) {
			presjek[k] = skupA[i];
			k++;
			i++;
			j++;
		}
		else if (skupA[i] > skupB[j]) {
			j++;
		}
		else{
			i++;
		}
	}
	
	presjek = (int*)realloc(presjek, k * sizeof(int));
	*n3 = k;

	return presjek;
}

void main() {
	srand(time(NULL));
	clock_t time_req;
	int n0 = 30000000, n1 = 0, n2 = 0, n3 = 0;

	int* niz1 = generiraj(n0);
	shuffle(niz1, n0);

	int* niz2 = generiraj(n0);
	shuffle(niz2, n0);

	time_req = clock();
	int* niz3 = presjek(niz1, niz2, n0, n0, &n1);
	free(niz3);
	time_req = clock() - time_req;
	printf("Processor time taken presjek: %f", (double)time_req / CLOCKS_PER_SEC, " seconds");
	printf("\n");

	time_req = clock();
	int* niz4 = presjek_jedan_sortiran(niz1, niz2, n0, n0, &n2);
	free(niz4);
	time_req = clock() - time_req;
	printf("Processor time taken jedan sortiran: %f", (double)time_req / CLOCKS_PER_SEC, " seconds");
	printf("\n");

	time_req = clock();
	int* niz5 = presjek_oba_sortirana(niz1, niz2, n0, n0, &n3);
	free(niz5);
	time_req = clock() - time_req;
	printf("Processor time taken oba sortirana: %f", (double)time_req / CLOCKS_PER_SEC, " seconds");
	printf("\n");
}