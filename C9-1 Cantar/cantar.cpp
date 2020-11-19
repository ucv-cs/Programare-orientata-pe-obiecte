/**
 * C9-1. Implementati clasa Cantar. Un cantar are o capacitate maxima admisa.
 * Daca se incearca cantarirea unui obiect ce depaseste cu maxim 10% greutatea
 * maxima admisa se va genera exceptia AvertismentDepasireGreutate iar daca se
 * depaseste si acesta limita se va genera eroarea DepasireGreutate.
 */
#include <iostream>
using namespace std;

class AvertismentDepasireGreutate {
   public:
	const char* mesaj;
	AvertismentDepasireGreutate(const char* msg) {
		mesaj = msg;
	}
};

class DepasireGreutate {
   public:
	const char* mesaj;
	DepasireGreutate(const char* msg) {
		mesaj = msg;
	}
};

class Cantar {
   private:
	float _greutate_maxima = 100;

   public:
	void cantareste(float);
};

void Cantar::cantareste(float greutate) {
	float limita = _greutate_maxima * 1.1;
	if (greutate > _greutate_maxima && greutate <= limita) {
		throw AvertismentDepasireGreutate(
			"Avertisment: greutatea maxima admisa a fost depasita!");
	} else if (greutate > limita) {
		throw DepasireGreutate(
			"Eroare: greutatea maxima admisa a fost depasita cu mai mult de "
			"10%!");
	}
	cout << "Greutate: " << greutate << " kg";
}

int main() {
	float greutate_obiect;
	cout << "Scrie un numar real: ";
	cin >> greutate_obiect;

	Cantar cantar;
	try {
		cantar.cantareste(greutate_obiect);
	} catch (AvertismentDepasireGreutate exception) {
		cerr << exception.mesaj << '\n';
		// TBD: ce sa se execute mai departe in acest caz...
	} catch (DepasireGreutate exception) {
		cerr << exception.mesaj << '\n';
		// ...
	} catch (...) {
		cerr << "Eroare: greutatea introdusa este incorecta.\n";
		// ...
	}
	return 0;
}