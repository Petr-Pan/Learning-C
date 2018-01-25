#include <stdlib.h>
#include <stdio.h>


char *spojeni(char *t1, char *t2) {
	int size_t1 = (&*t1)[1] - *t1;
	int size_t2 = (&*t2)[1] - *t2;
	char *spojene = (char *)malloc(sizeof(size_t1 + size_t2));
	int i = 0;

	for (i = 0; i < size_t1; i++) {
		spojene[i] = *t1;
		t1++;
		}
	for (i = 0; i < size_t2; i++) {
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
	
	printf(spojeni(t1, t2));

	/*char merged = spojeni(t1, t2);
	printf(merged);*/

	system("pause");
	return 0;

}