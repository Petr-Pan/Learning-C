#include<stdlib.h>
#include<stdio.h>

int porovnej(char *t1, char *t2) {
	/*Pokud je øetìzec t1 > t2, vrátí 1, pokud t1 < t2 vrátí -1, u shody vrátí 0.*/
	while (*t1 != '\0') {
		if (*t2 == '\0') return 1;
		else if (*t1 > *t2) return 1;
		else if (*t1 < *t2)	return -1;
		t1++;
		t2++;
	}
	return 0;

}

int porovnej_slovne(char *t1, char *t2, int vysledek_porovnej) {
	/*Vytiskne slovne vysledek funkce porovnej.*/
	switch (vysledek_porovnej) {
	case 1: 
		printf("Slovo %s je vetsi nez slovo %s.", *t1, *t2);
		break;
	case -1: 
		printf("Slovo %s je mensi nez slovo %s.", *t1, *t2);
		break;
	case 0:  
		printf("Slovo %s se shoduje se slovem %s.", *t1, *t2);
		break;
		
	}
	return 0;
}



int main() {
	char str1[] = "Kacenka";
	char str2[] = "Kacanka";
	char *st1 = str1;
	char *st2 = str2;
	
	//porovnej_slovne(*t1, *t2, porovnej(*t1, *t2));
	printf(porovnej(*st1, *st2));
	

	system("pause");
	return 0;
}