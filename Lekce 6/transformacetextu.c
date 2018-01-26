#include <stdlib.h>
#include <stdio.h>

int set(char* in, char** out) {
	int size_in;
	for (size_in = 0; in[size_in] != '\0'; size_in++);
	
	int pocet_zmenenych = 0;
	int posun = 'a' - 'A';
	*out = (char *)malloc(size_in * sizeof(char));

	for (int i = 0; i < size_in; i++) {
		if (in[i] >= 'a' && in[i] <= 'z') {
			(*out)[i] = in[i] - posun;
			pocet_zmenenych++;
		}
		else if (in[i] >= 'A' && in[i] <= 'Z') {
			(*out)[i] = in[i] + posun;
			pocet_zmenenych++;
		}
		else (*out)[i] = in[i];
	
	}
	return pocet_zmenenych;

}

int main() {
	char str1[] = "cHICh24";
	char str2[] = "\0";
	char *p_str2 = &str2;

	
	set(&str1, &p_str2);

	printf("Puvodni text je %s.\n", str1);
	printf("Zmeneny text je %s.", p_str2);

	system("pause");
	return 0;

}