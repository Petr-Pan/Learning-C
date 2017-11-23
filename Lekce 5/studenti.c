#include<stdio.h>
#include<stdlib.h>

// Porovná vìk dvou studentù užitím funkce a vlastních strukturovaných datových typù, následnì vypíše
// Zadání - http://jazykc.inf.upol.cz/strukturovane-datove-typy/index.htm


typedef struct {
	char Den, Mesic; short Rok;
} Datum;


typedef struct {
	char jmeno[20], prijmeni[20]; Datum narozen;
} student;

int porovnej_vek(student s1, student s2) {
	/* Pokud je s1 starší, vrátí hodnotu 1. Pokud je s2 starší, vrátí hodnotu -1.
	U shodného vìku vrátí hodnotu 0.*/
	if (s1.narozen.Rok < s2.narozen.Rok)
		return 1;

	else if (s1.narozen.Rok == s2.narozen.Rok)
		if (s1.narozen.Mesic < s2.narozen.Mesic)
			return 1;
		else if (s1.narozen.Mesic == s2.narozen.Mesic)
			if (s1.narozen.Den < s2.narozen.Den)
				return 1;
			else if (s1.narozen.Den == s2.narozen.Den)
				return 0;
			else
				return -1;
		else
			return -1;
	else
		return -1;

};

int porovnanyvek = 2;

int printstarsiho(student s1, student s2, int porovnanyvek) {
	/* Vytiskne porovnání vìkù dvou studentù.*/
	switch (porovnanyvek) {
	case 1:
		printf("%s %s je starsi nez %s %s.\n", s1.jmeno, s1.prijmeni, s2.jmeno, s2.prijmeni);
		break;
	case -1:
		printf("%s %s je mladsi nez %s %s.\n", s1.jmeno, s1.prijmeni, s2.jmeno, s2.prijmeni);
		break;
	case 0:
		printf("%s %s je stejne stary jako %s %s.\n", s1.jmeno, s1.prijmeni, s2.jmeno, s2.prijmeni);
		break;
	}
	return 0;
};


int main() {
	student s3;
	s3.jmeno[20] = "Erich";
	s3.prijmeni[20] = "Fiedler";
	//s3.narozen = {12, 11, 1960}; //Nefunkèní pokus o deklaraci celého podtypu naráz

	s3.narozen.Den = 12;
	s3.narozen.Mesic = 12;
	s3.narozen.Rok = 1960;

	student s1 = { "Doktor", "Zaba",  7, 7, 1960 };
	student s2 = { "Kuzma", "Kuzmic", 11, 12, 1960 };
	student s4 = { "Varel", "Fristensky", 20, 12, 1960 }; //Pro testování rùzných variant
	
	printstarsiho(s4, s1, porovnej_vek(s4, s1));

	//Všechno smìrem dolù pokusy o debug

	
	system("pause");
	return 0;
}
