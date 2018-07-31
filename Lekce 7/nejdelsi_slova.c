#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_DELKA_SLOV 100

void porovnej_pole_se_souborem(char **, int, FILE*);
void serad_pole(char **, int);
void znic_interpunkci(char *);

int main(int argc, char *argv[]) {

	FILE *fr;
	if ((fr = fopen(argv[1], "r")) == NULL) {
		printf("Vstupni soubor se nepodarilo otevrit.\n");
		return 1;
	}
	
	int pocetslov = atoi(argv[2]);

	//Vytvoreni pole pro praci
	char **arr;
	if ((arr = (char **)malloc(pocetslov * sizeof(char *))) == NULL) {
		printf("Neuspesna alokace pameti pro vstupni pole.");
		return 1;
	}
	for (int i = 0; i < pocetslov; i++)
		if ((arr[i] = (char *)malloc(MAX_DELKA_SLOV * sizeof(char))) == NULL) {
			printf("Neuspesna alokace pameti pro radky vstupniho pole.");
			return 1;
		}

	//Nacteni prvnich X slov pro nasledne porovnavani
	for (int i = 0; i < pocetslov; i++) {
		fscanf(fr, " %s", *(arr + i));
		znic_interpunkci(*(arr + i));
	}

	serad_pole(arr, pocetslov);
	porovnej_pole_se_souborem(arr, pocetslov, fr);

	//Vytiskne vysledne pole
	for (int i = 0; i < pocetslov; i++) printf("%s\n", *(arr + i));


	if (fclose(fr) == EOF) {
		printf("Soubor se nepodarilo uzavrit.\n");
		return 1;
	}

	return 0;
}

/* Nacte slova v souboru a ulozi do zadaneho pole X nejdelsich slov */
void porovnej_pole_se_souborem(char **arr, int pocetslov, FILE *fr) {
	char *nacten;
	if ((nacten = (char *)malloc(MAX_DELKA_SLOV * sizeof(char))) == NULL) {
		printf("Neuspesna alokace pameti pro srovnavaci retezec.");
		exit(1);
	}
	
	while (fscanf(fr, " %s", nacten) != EOF) {
		znic_interpunkci(nacten);
		if (strlen(*(arr + pocetslov - 1)) < strlen(nacten)) {
			strcpy(*(arr + pocetslov - 1), nacten);
			serad_pole(arr, pocetslov);
		}
	}
	free(nacten);
}

/* Seradi slova v poli podle velikosti */
void serad_pole(char **arr, int pocetslov) {
	char *mensi;
	if ((mensi = (char *)malloc(MAX_DELKA_SLOV * sizeof(char))) == NULL) {
		printf("Neuspesna alokace pameti pro dummy retezec.");
		exit(1);
	}
	
	for (int i = 0; i < (pocetslov - 1); i++) {
		for (int k = 0; k < pocetslov - i - 1; k++) {
			if (strlen(*(arr + k)) < strlen(*(arr + k + 1))) {
				strcpy(mensi, *(arr + k));
				strcpy(*(arr + k), *(arr + k + 1));
				strcpy(*(arr + k + 1), mensi);

			}
		}
	}
	free(mensi);
}

/* Odstrani interpunkci z retezce na danem pointeru*/
void znic_interpunkci(char *str) {
	int i = 0;
	int j = 0;
	unsigned char c = 0;

	while ((c = *(str+i)) != '\0') {
		if (isalnum(c)) {
			*(str+j) = c;
			j++;
		}
		i++;
	}
	
	*(str+j) = '\0';
}