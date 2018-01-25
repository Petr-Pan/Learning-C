#include <stdlib.h>
#include <stdio.h>

int deleni(int a, int b, int *r) {
	int mezivypocet = a;
	int vysledek = 0;

	while (mezivypocet > 0) {
		mezivypocet = a - b;
		vysledek++;
	}
	*r = mezivypocet;
	return vysledek;
}


int main() {
	
	int zbytek = 0;
	int *zb = zbytek;

	deleni(4, 2, zb);
	/*printf("Vysledek je %d", deleni(9, 4, zb));
	printf("/n");
	printf("Zbytek je %d", *zb);*/

	system("pause");
	return 0;

}