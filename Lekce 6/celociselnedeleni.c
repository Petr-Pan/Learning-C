#include <stdlib.h>
#include <stdio.h>

int deleni(int a, int b, int *r) {
	int mezivypocet = a;
	int vysledek = 0;

	while (a - b >= 0) {
		a = a - b;
		vysledek++;		
	}

	*r = a;
	return vysledek;
}


int main() {
	
	int zbytek = 0;
	
	printf("Vysledek 5/4 je %d. ", deleni(5, 4, &zbytek));
	printf("Zbytek je %d.\n", zbytek);

	printf("Vysledek 8/2 je %d. ", deleni(8, 2, &zbytek));
	printf("Zbytek je %d.\n", zbytek);

	printf("Vysledek 11/3 je %d. ", deleni(11, 3, &zbytek));
	printf("Zbytek je %d.\n", zbytek);

	printf("Vysledek 9/4 je %d. ", deleni(9, 4, &zbytek));
	printf("Zbytek je %d.\n", zbytek);

	system("pause");
	return 0;

}