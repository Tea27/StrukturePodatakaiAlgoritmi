#include "dictionary.h"
#include <stdio.h>

Dictionary create() {
	Dictionary myDictionary = (Word*)malloc(sizeof(Word));
	if (myDictionary == NULL) {
		printf("alokacija novog rjecnika nije uspjela\n");
		return;
	}
	myDictionary->count = 0;
	myDictionary->word = NULL;
	myDictionary->next = NULL;
}
void add(Dictionary dict, char* str) {
	Word* word = (Word*)malloc(sizeof(Word));

	if (!word) {
		printf("alokacija nove rijeci nije uspjela\n");
		return;
	}

	word->word = _strdup(str);

	while (dict->next != NULL) {
		if (strcmp(dict->next->word, str) == 0) { 
			dict->next->count += 1;
			free(word->word);
			free(word);
			return;
		}
		else if(strcmp(dict->next->word, str) > 0){ //ako je postojeca rijec leksikografski veca od nove
			word->next = dict->next;   
			dict->next = word;
			word->count = 1;
			return;
		}
		dict = dict->next;
	}
	dict->next = word; //ako je postojeca rijec leksikografski manja od nove, novu dodajemo na kraj 
	word->next = NULL;
	word->count = 1;
}
void print(Dictionary dict) {
	Dictionary temp = dict->next;

	while (temp != NULL)
	{
		printf("%s se ponavlja %d puta\n", temp->word, temp->count);
		temp = temp->next;
	}
}
void destroy(Dictionary dict) {
	Dictionary toErase = dict;
	while (dict->next != NULL) {
		dict = dict->next;
		free(toErase->word);
		free(toErase);
		toErase = dict;
	}
}

int filter(Word* w) {
	return((w->count > 5) && (w->count < 10) && (strlen(w->word) > 3));
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w)) {
	Dictionary tmp = indict;

	while (tmp->next != NULL) {
		if (!filter(tmp->next)) {
			Dictionary del = tmp->next;
			tmp->next = tmp->next->next;
			free(del->word);
			free(del);
		}
		else {
			tmp = tmp->next;
		}
	}
	return indict;
}