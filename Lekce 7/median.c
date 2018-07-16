#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void serad_pole(int[], int);

//Vraci 1, pokud je cislo sude
int sudy_p(int);

double median(int[], int);

int main(int argc, char *argv[]) {

	FILE *fr;
	if ((fr = fopen(argv[1], "r")) == NULL) {
		printf("Vstupni soubor se nepodarilo otevrit.\n");
		return 1;
	}

	int *pole;
	pole = (int *)malloc(1 * sizeof(int));

	
	fseek(fr, 0L, SEEK_SET);
	int i = 0;
	while (fscanf(fr, " %d", &pole[i]) != EOF) {
		++i;
		pole[i] = (int *)malloc(1 * sizeof(int));
	}

	/*
	printf("Zadej cisla: ");
	for (int i = 0; i < velikost_pole; i++) {
		scanf_s("%d", &pole[i]);
	}
	serad_pole(pole, velikost_pole);
	printf("Serazeno:\n");
	for (int i = 0; i < velikost_pole; i++) {
		printf("%ld ", pole[i]);
	}*/

	printf("Median je : %lf \n", median(pole, i));

	if (fclose(fr) == EOF) {
		printf("Soubor se nepodarilo uzavrit.\n");
		return 1;
	}


	return 0;

}

void serad_pole(int pole[], int velikost_pole) {
	int vetsi;

	for (int i = 0; i < (velikost_pole - 1); i++) {
		for (int k = 0; k < velikost_pole - i - 1; k++) {
			if (pole[k] > pole[k + 1]) {
				vetsi = pole[k];
				pole[k] = pole[k + 1];
				pole[k + 1] = vetsi;
			}
		}
	}
}

int sudy_p(int cislo) {
	return !(cislo % 2);
}

double median(int pole[], int velikost_pole) {
	serad_pole(pole, velikost_pole);
	if (!sudy_p(velikost_pole)) {
		return pole[(velikost_pole - 1) / 2];
	}
	else {
		//(Vyssi prostredni prvek plus nizsi prostredni prvek) / 2;
		return ((double)pole[velikost_pole / 2] + (double)pole[(velikost_pole / 2) - 1]) / 2;
	}

}