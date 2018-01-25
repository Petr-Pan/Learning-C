#include <stdlib.h>
#include <stdio.h>


char *spojeni(char *t1, char *t2) {
	int size_t1 = 8;
	int size_t2 = 5;
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
	char *t1 = str1;
	char *t2 = str2;
	
	printf("Spojeni slov %s a %s je %s.\n", str1, str2, spojeni(t1, t2));

	/*int size = (&*t1)[1] - *t1;
	printf(size);*/
	/*char merged = spojeni(t1, t2);
	printf(merged);*/

	system("pause");
	return 0;

}