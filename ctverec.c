#include<stdio.h>
#include<stdlib.h>

int main() {

	int velikost;
	char znak = "*";

	printf("Zadejte velikost ctverce: ");
	scanf_s("%d", &velikost);

	//te� pot�ebujeme cyklus pro jednak ��dek a jednak "sloupec"

	//prvn� ��dek:
	for (int i = 1; i <= velikost; i++) {
		printf("*");
		
	
	}

	printf("\n");

	//prost�edn� ��dky:
	
	for (int i = 1; i <= velikost - 2; i++) {
		printf("*");
		for (int i = 1; i <= velikost - 2; i++) {
			printf(" ");
			
		}
		printf("*\n");

	}

	//posledn� ��dek
	for (int i = 1; i <= velikost; i++) {
		printf("*");
		

	}
	printf("\n");


	system("pause");
	return 0;



}