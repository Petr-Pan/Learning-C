#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void serad_pole(int[], int);
int sudy_p(int);
double median(int[], int);
int nacti_pole(FILE *, int *);

int main(int argc, char *argv[]) {

	FILE *fr;
	if ((fr = fopen(argv[1], "r")) == NULL) {
		printf("Vstupni soubor se nepodarilo otevrit.\n");
		return 1;
	}

	int *pole;
	pole = (int *)malloc(1 * sizeof(int));
	int velikost_pole = nacti_pole(fr, pole);

	printf("Median je : %lf \n", median(pole, velikost_pole));

	if (fclose(fr) == EOF) {
		printf("Soubor se nepodarilo uzavrit.\n");
		return 1;
	}

	return 0;
}

/* Seradi pole vzestupne */
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

/* Vraci 1, pokud je cislo sude */
int sudy_p(int cislo) {
	return !(cislo % 2);
}

/* Vraci median zadaneho pole */
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

/* Nacte pole cisel ze souboru a vrati pocet nactenych cisel*/
int nacti_pole(FILE *fr, int *pole) {
	int i = 0;
	for (i = 0; fscanf(fr, " %d", &pole[i]) != EOF; i++) {
		if (pole[i + 1] == EOF) break;
		else pole[i + 1] = (int *)malloc(1 * sizeof(int));
	}
	return i;
}