#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
		arr[i] = (char *)malloc(delkaslov * sizeof(char));

	for (i = 0; i < pocetslov; i++) fscanf(fr, " %s", *(arr+i));

	for (i = 0; i < pocetslov; i++) printf("%s\n", *(arr+i));

	

	if (fclose(fr) == EOF) {
		printf("Soubor se nepodarilo uzavrit.\n");
		return 1;
	}

	return 0;
}

