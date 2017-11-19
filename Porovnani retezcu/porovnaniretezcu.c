#include<stdlib.h>
#include<stdio.h>

int porovnej(char *t1, char *t2) {
	/*Pokud je �et�zec t1 > t2, vr�t� 1, pokud t1 < t2 vr�t� -1, u shody vr�t� 0.*/
	int i = 0;
	while (*t1 != "\0") {
		if (*t2 == "\0") return 1;
		else if (*t1 > *t2) return 1;
		else if (*t1 < *t2)	return -1;

		i++;
	}
	

}

int porovnej_slovne(char *t1, char *t2, int vysledek_porovnej) {
	/*Vytiskne slovne vysledek funkce porovnej.*/
	switch (vysledek_porovnej) {
	case 1: printf("S�ovo %s je vetsi nez slovo %s.", *t1, *t2);
	case -1: printf("S�ovo %s je mensi nez slovo %s.", *t1, *t2);
	case 0:  printf("S�ovo %s se shoduje se slovem %s.", *t1, *t2);

	}


}



int main() {
	char *t1 = "Kacenka";
	char *t2 = "Kacanka";
	
	porovnej_slovne(*t1, *t2, porovnej(*t1, *t2));
	


	system("pause");
	return 0;
}