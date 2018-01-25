#include <stdlib.h>
#include <stdio.h>

int deleni(int a, int b, int *r) {
	int mezivypocet = a;
	int vysledek = 0;

	while (a - b >= 0) {
		a = a - b;
		vysledek++;		
	}

	*r = a - (b * vysledek); //r by mělo vracet zbytek po dělení. Nevrací
	return vysledek;
}


int main() {
	
	int zbytek = 0;
	int *zb = &zbytek;

	
	printf("Vysledek 5/4 je %d. Zbytek je %d.\n", deleni(5, 4, zb), *zb);
	printf("Vysledek 8/2 je %d. Zbytek je %d.\n", deleni(8, 2, zb), *zb);
	printf("Vysledek 11/3 je %d. Zbytek je %d.\n", deleni(11, 3, zb), *zb);
	printf("Vysledek 9/4 je %d. Zbytek je %d.\n", deleni(9, 4, zb), *zb);
	

	system("pause");
	return 0;

}
