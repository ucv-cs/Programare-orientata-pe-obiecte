/**
 * C9-2. Implementati clasa Stiva implementata sub forma unui tablou alocat
 * dinamic. Gestionati exceptiile ce pot aparea.
 */
#include <iostream>

using namespace std;

// daca se incearca adaugarea unui element peste capacitatea stivei
class SupraCapacitate {
   public:
	const char* mesaj;
	SupraCapacitate(const char* msg) {
		mesaj = msg;
	}
};

// daca se incearca eliminarea unui element dintr-o stiva goala
class SubCapacitate {
   public:
	const char* mesaj;
	SubCapacitate(const char* msg) {
		mesaj = msg;
	}
};

// strictul necesar - fara supraincarcari de =, constructori de copiere...
class Stiva {
   private:
	int* _stiva;
	int _capacitate;
	int _contor;  // <- numarul curent de elemente din stiva!

   public:
	Stiva(int);
	~Stiva();
	void push(int);	 // adauga un element dupa ultimul
	int pop();		 // returneaza ultimul element si il elimina
	void afiseaza();
	bool eGoala();
	bool ePlina();
};

Stiva::Stiva(int capacitate) {
	_stiva = new int[capacitate];
	_capacitate = capacitate;
	_contor = 0;
}

Stiva::~Stiva() {
	delete[] _stiva;
}

void Stiva::push(int element) {
	if (this->ePlina()) {
		throw SupraCapacitate(
			"Stiva e plina. Nu se mai pot adauga noi elemente.");
	}
	_stiva[_contor] = element;
	_contor++;
}

int Stiva::pop() {
	if (this->eGoala()) {
		throw SubCapacitate(
			"Stiva e goala. Nu se mai pot elimina alte elemente.");
	}
	int element = _stiva[_contor - 1];
	_stiva[_contor - 1] = 0;
	_contor--;

	return element;
}

void Stiva::afiseaza() {
	cout << "Capacitate: " << _capacitate
		 << "\nNumar curent de elemente: " << _contor << "\nContinut: ";
	for (int i = 0; i < _contor; i++) {
		cout << i << " ";
	}
	cout << "\n----------------------\n";
}

bool Stiva::eGoala() {
	return (_contor == 0);
}

bool Stiva::ePlina() {
	return (_contor == _capacitate);
}

int main() {
	Stiva stack(5);
	stack.afiseaza();

	try {
		for (int i = 0; i < 10; i++) {
			stack.push(i);
			stack.afiseaza();
		}
	} catch (SupraCapacitate e) {
		cerr << e.mesaj << '\n';
	}

	try {
		for (int i = 5; i >= 0; i--) {
			cout << "\nElement eliminat: " << stack.pop() << '\n';
			stack.afiseaza();
		}
	} catch (SubCapacitate e) {
		cerr << e.mesaj << '\n';
	}

	return 0;
}