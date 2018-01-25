#include <stdlib.h>
#include <stdio.h>

int set(char* in, char** out) {
	int i = 0;
	int pocet_zmenenych = 0;
	const char posun = 'a' - 'A';

	while (in != '\0') {
		if (in >= 'a' && in <= 'z') {
			out = in - posun;
			pocet_zmenenych++;
		}
		else if (in >= 'A' && in <= 'Z') {
			out = in + posun;
			pocet_zmenenych++;
		}
		else out = in;
		in++;
		out++;
	}
	return pocet_zmenenych;

}

int main() {
	char str1[] = "cHICH";
	char str2[] = "";
	char *t1 = str1;
	char *t2 = str2;
	
	printf(set(t1, &t2));

	system("pause");
	return 0;

}