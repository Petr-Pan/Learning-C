#include <stdlib.h>
#include <stdio.h>

typedef struct { int *zasobnik; int data; } prvek;

prvek *pridej(prvek* zasobnik, int data) {

}

int vrchol(prvek* zasobnik) {

}

prvek *odeber(prvek* zasobnik) {

}




int main() {
	prvek* z = NULL;
	int i;

	for (i = 1; i<11; i++)
		z = pridej(z, i);

	while (z != NULL) {
		printf("%i\n", vrchol(z));
		z = odeber(z);
	}

	system("pause");
	return 0;

}