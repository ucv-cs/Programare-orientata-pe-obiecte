/** C2-1_NumarRational.cpp
 * Implementati clasa NumarRational.
 */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

/**
 * Reprezentarea unui numar rational. Se bazeaza pe float (insa putea fi si
 * double).
 */
class NumarRational {
	private:
	float valoare;

	public:

	// obtine numarul rational de la utilizator
	void citire() {
		printf("Scrie un numar rational: q = ");
		if (scanf("%f", &valoare) == 0) {
			printf("Valoarea introdusa este gresita. Mai incearca!\n");
			cin.clear(); // curata bufferul de input
			cin.ignore(100, '\n');
			this->citire();
		}

	}

	// afiseaza numarul rational, in forma zecimala
	void afisare() {
		printf("\nq = %f", valoare);
	}

	// returneaza modulul numarului
	float modul() {
		return abs(valoare);
	}
};

int main() {
	cout << "C2.1: Implementati clasa NumarRational.\n\n";
	NumarRational numar;
	numar.citire();
	numar.afisare();
	printf("\n|q| = %f", numar.modul());
	getch();
	return 0;
}