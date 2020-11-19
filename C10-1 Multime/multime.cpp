/**
 * C10-1. Implementati clasa Multime care sa poata retine elemente de orice tip.
 * Sa se supraincarce operatorii +, * pentru a realiza reuniunea respectiv
 * intersectia a doua multimi.
 */
#include <iostream>	 // cin, cout

using namespace std;

const unsigned capacitate_maxima = 100;

template <typename Tip>
class Multime {
   private:
	Tip _colectie[capacitate_maxima];
	unsigned _cardinal;	 // numarul curent de elemente
	bool _apartine(Tip, Multime);

   public:
	Multime();

	Multime operator+(Multime);
	Multime operator*(Multime);

	void adauga_element(Tip);
	void afiseaza();
};

template <typename Tip>
Multime<Tip>::Multime() {
	_cardinal = 0;
}

template <typename Tip>
Multime<Tip> Multime<Tip>::operator+(Multime<Tip> multime) {
	Multime<Tip> reuniune;

	for (int i = 0; i < this->_cardinal; i++) {
		reuniune.adauga_element(this->_colectie[i]);
	}

	for (int i = 0; i < multime._cardinal; i++) {
		if (reuniune._cardinal + 1 <= capacitate_maxima) {
			reuniune.adauga_element(multime._colectie[i]);
		} else {
			throw out_of_range(
				"Eroare: reuniunea celor doua multimi depaseste capacitatea "
				"maxima (100 elemente)! Operatia nu va avea loc.\n");
		}
	}

	return reuniune;
}

template <typename Tip>
Multime<Tip> Multime<Tip>::operator*(Multime<Tip> multime) {
	Multime<Tip> intersectie;
	for (int i = 0; i < this->_cardinal; i++) {
		if (_apartine(this->_colectie[i], multime)) {
			intersectie.adauga_element(this->_colectie[i]);
		}
	}
	return intersectie;
}

template <typename Tip>
bool Multime<Tip>::_apartine(Tip element, Multime<Tip> multime) {
	for (int i = 0; i < multime._cardinal; i++) {
		if (multime._colectie[i] == element) {
			return true;
		}
	}
	return false;
}

template <typename Tip>
void Multime<Tip>::adauga_element(Tip element) {
	if (_cardinal + 1 <= capacitate_maxima - 1 && !_apartine(element, *this)) {
		_colectie[_cardinal] = element;
		_cardinal++;
	}
}

template <typename Tip>
void Multime<Tip>::afiseaza() {
	cout << "{";
	for (int i = 0; i < _cardinal - 1; i++) {
		cout << _colectie[i] << ", ";
	}
	cout << _colectie[_cardinal - 1] << "}\n";
}

// tip oarecare pentru testarea multimilor
class Carte {
   public:
	string titlu;
	Carte() {
	}

	Carte(string text) {
		this->titlu = text;
	}

	bool operator==(const Carte &carte_2) {
		return (this->titlu == carte_2.titlu);
	}
};

ostream &operator<<(ostream &output_stream, Carte const &carte) {
	return output_stream << carte.titlu;
}

int main() {
	try {
		Multime<int> prima;
		for (int i = 0; i < 10; i++) {
			prima.adauga_element(i);
		}
		cout << "A = ";
		prima.afiseaza();

		Multime<int> a_doua;
		for (int i = 5; i < 15; i++) {
			a_doua.adauga_element(i);
		}
		cout << "\nB = ";
		a_doua.afiseaza();

		Multime<int> reuniune = prima + a_doua;
		cout << "\nA + B = ";
		reuniune.afiseaza();

		Multime<int> intersectie = prima * a_doua;
		cout << "\nA * B = ";
		intersectie.afiseaza();

		Multime<float> a_treia;
		for (int i = 0; i < 5; i++) {
			a_treia.adauga_element((float)i / (rand() % 3 + 0.1));
		}
		cout << "\nC = ";
		a_treia.afiseaza();

		Multime<Carte> carti_1;
		for (int i = 0; i < 4; i++) {
			carti_1.adauga_element(
				Carte("The Art of Computer Programming. Vol. " +
					  to_string(i + 1) + " [Knuth]"));
		}
		cout << "\nD = ";
		carti_1.afiseaza();

		Multime<Carte> carti_2;
		carti_2.adauga_element(
			Carte("The Art of Computer Programming. Vol. 1 [Knuth]"));
		carti_2.adauga_element(
			Carte("The C++ Programming Language [Stroustrup, 4, 2013]"));
		cout << "\nE = ";
		carti_2.afiseaza();

		cout << "\nD + E = ";
		(carti_1 + carti_2).afiseaza();

		cout << "\nD * E = ";
		(carti_1 * carti_2).afiseaza();

	} catch (exception e) {
		cout << e.what();
	}
	cout << "\nApasa ENTER pentru a inchide aplicatia...";
	getchar();
}