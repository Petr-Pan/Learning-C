#include <stdlib.h>
#include <stdio.h>


char *spojeni(char *t1, char *t2) {
	int size_t1 = (&*t1)[1] - *t1;
	int size_t2 = (&*t2)[1] - *t2;
	const int size_total = size_t1 + size_t2;

	char spojene[size_total]= "\0";
	int i = 0;
	while (*t1 != "\0") {
		char spojene[i] = *t1;
		i++;
		t1++;
		}
	while (*t2 != "\0") {
		char spojene[i] = *t2;
		i++;
		t2++;
	}
	
	return spojene;
}

int main() {
	char str1[] = "Vetinari";
	char str2[] = "Rufus";
	char *t1 = str1;
	char *t2 = str2;
	
	printf(*spojeni(t1, t2));

	system("pause");
	return 0;

}