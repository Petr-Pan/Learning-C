#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable:4996)

char *spojeni(char *t1, char *t2) {
	int size_t1, size_t2;
	for (size_t1 = 0; t1[size_t1] != '\0'; size_t1++);
	for (size_t2 = 0; t2[size_t2] != '\0'; size_t2++);

	char *spojene = (char *)malloc((size_t1 + size_t2) * sizeof(char));

	for (int i = 0; i < size_t1; i++) {
		spojene[i] = *t1;
		t1++;
	}
	for (int i = size_t1; i < size_t1 + size_t2 + 1; i++) {
		spojene[i] = *t2;
		t2++;
	}
	return spojene;
}

int main() {
	char str1[] = "Vetinari";
	char str2[] = "Rufus";
	
	/*Pro testy
	scanf("%s", &str1);
	fflush(stdin);
	scanf("%s", &str2);*/


	char *t1 = str1;
	char *t2 = str2;
	
	printf("Spojeni slov '%s' a '%s' je '%s'.\n", str1, str2, spojeni(&str1, &str2));


	system("pause");
	return 0;

}