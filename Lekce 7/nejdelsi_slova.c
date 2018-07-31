#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_DELKA_SLOV 100

void serad_pole(char **, int);

int main(int argc, char *argv[]) {

	FILE *fr;
	if ((fr = fopen(argv[1], "r")) == NULL) {
		//if ((fr = fopen("vstup.txt", "r")) == NULL) {
		printf("Vstupni soubor se nepodarilo otevrit.\n");
		return 1;
	}

	int delkaslov = 100, pocetslov = atoi(argv[2]), i = 0;

	char **arr = (char **)malloc(pocetslov * sizeof(char *));
	for (i = 0; i < pocetslov; i++)
		arr[i] = (char *)malloc(MAX_DELKA_SLOV * sizeof(char));


	//Na�teno prvn�ch X slov
	for (i = 0; i < pocetslov; i++) fscanf(fr, " %s", *(arr + i));

	//Pot�eba funkci na se�azen� pole
	char *mensi = (char *)malloc(MAX_DELKA_SLOV * sizeof(char));

	serad_pole(arr, pocetslov);

	for (i = 0; i < pocetslov; i++) printf("%s\n", *(arr + i));


	if (fclose(fr) == EOF) {
		printf("Soubor se nepodarilo uzavrit.\n");
		return 1;
	}

	return 0;
}

void serad_pole(char **arr, int pocetslov) {
	char *mensi = (char *)malloc(MAX_DELKA_SLOV * sizeof(char));


	for (int i = 0; i < (pocetslov - 1); i++) {
		for (int k = 0; k < pocetslov - i - 1; k++) {
			if (strlen(*(arr + k)) < strlen(*(arr + k + 1))) {
				strcpy(mensi, *(arr + k));
				strcpy(*(arr + k), *(arr + k + 1));
				strcpy(*(arr + k + 1), mensi);

			}
		}
	}
}