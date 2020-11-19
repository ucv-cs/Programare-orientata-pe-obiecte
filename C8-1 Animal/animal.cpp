/**
 * C8-1. Sa se implementeze urmatoarea ierarhie de clase: Animal(nume),
 * Mamifer(nume, perioadaGestatie), AnimalZburator(nume, altitudineZbor),
 * Liliac(nume, periodaGestatie, altitudineZbor). Numele se va retine ca un sir
 * de caractere alocat dinamic (char *). Sa se implementeze constructorii de
 * copiere si sa se supraincarce operatorul de atribuire pentru aceste clase.
 */
#include <string.h>	 // strcpy(), old C-strings

#include <iostream>
using namespace std;

class Animal {
   protected:
	char* nume;

   public:
	Animal(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		// FIXME: ISO C++ forbids converting a string constant to 'char*'
		// [-Wwrite-strings]
		// v. https://en.cppreference.com/w/cpp/language/string_literal
		strcpy(this->nume, nume);
		cout << "\t[Animal] constructor\n";
	}

	Animal(const Animal& animal) {
		this->nume = new char[strlen(animal.nume) + 1];
		strcpy(this->nume, animal.nume);
		cout << "\t[Animal] constructor de copiere\n ";
	}

	~Animal() {
		delete[] nume;
		cout << "\t[Animal] destructor\n";
	}

	Animal& operator=(const Animal& animal) {
		if (this != &animal) {
			delete[] nume;
			this->nume = new char[strlen(animal.nume) + 1];
			strcpy(this->nume, animal.nume);
		}
		cout << "\t[Animal] operator=\n";
		return *this;
	}

	void afiseaza() {
		cout << "[Animal] nume: " << nume << endl;
	}
};

class AnimalZburator : virtual public Animal {
   protected:
	unsigned altitudineZbor;

   public:
	AnimalZburator(char* nume, unsigned altitudineZbor) : Animal(nume) {
		this->altitudineZbor = altitudineZbor;
		cout << "\t[AnimalZburator] constructor\n";
	}

	AnimalZburator(const AnimalZburator& animal) : Animal(animal) {
		// this->nume = new char[strlen(animal.nume) + 1];
		// strcpy(this->nume, animal.nume);
		this->altitudineZbor = animal.altitudineZbor;
		cout << "\t[AnimalZburator] constructor de copiere\n ";
	}

	~AnimalZburator() {
		delete[] nume;
		cout << "\t[AnimalZburator] destructor\n";
	}

	AnimalZburator& operator=(const AnimalZburator& animal) {
		if (this != &animal) {
			Animal::operator=(animal);
			this->altitudineZbor = animal.altitudineZbor;
		}
		cout << "\t[AnimalZburator] operator=\n";
		return *this;
	}

	void afiseaza() {
		cout << "[AnimalZburator] altitudineZbor: " << altitudineZbor << endl;
	}
};

class Mamifer : virtual public Animal {
   protected:
	unsigned perioadaGestatie;

   public:
	Mamifer(char* nume, unsigned perioadaGestatie) : Animal(nume) {
		this->perioadaGestatie = perioadaGestatie;
		cout << "\t[Mamifer] constructor\n";
	}

	Mamifer(const Mamifer& mamifer) : Animal(mamifer) {
		this->perioadaGestatie = mamifer.perioadaGestatie;
		cout << "\t[Mamifer] constructor de copiere\n";
	}

	~Mamifer() {
		cout << "\t[Mamifer] destructor\n";
	}

	Mamifer& operator=(const Mamifer& mamifer) {
		if (this != &mamifer) {
			Animal::operator=(mamifer);
			this->perioadaGestatie = perioadaGestatie;
		}
		cout << "\t[Mamifer] operator=\n";
		return *this;
	}

	void afiseaza() {
		cout << "[Mamifer] perioadaGestatie: " << perioadaGestatie << endl;
	}
};

class Liliac : public AnimalZburator, public Mamifer {
   public:
	Liliac(char* nume, unsigned perioadaGestatie, unsigned altitudineZbor)
		: Animal(nume),
		  AnimalZburator(nume, altitudineZbor),
		  Mamifer(nume, perioadaGestatie) {
		cout << "\t[Liliac] constructor\n";
	}

	Liliac(const Liliac& liliac)
		: Animal(liliac), Mamifer(liliac), AnimalZburator(liliac) {
		cout << "\t[Liliac] constructor de copiere\n ";
	}

	Liliac& operator=(const Liliac& liliac) {
		if (this != &liliac) {
			Animal::operator=(liliac);
			AnimalZburator::operator=(liliac);
			Mamifer::operator=(liliac);
		}
		cout << "\t[Liliac] operator=\n";
		return *this;
	}

	void afiseaza() {
		cout << "\n****[Liliac]****\n";
		Animal::afiseaza();
		AnimalZburator::afiseaza();
		Mamifer::afiseaza();
	}
};

int main() {
	Liliac liliac1("Wuhan Bat", 6, 100);
	liliac1.afiseaza();

	Liliac liliac2 = liliac1;
	liliac2.afiseaza();

	liliac1 = liliac2;
	liliac1.afiseaza();

	getchar();
	return 0;
}