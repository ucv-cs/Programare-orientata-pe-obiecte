/**
 C4-1. Implementați clasa Polinom pentru care supraîncărcați operatorii +, *
 pentru a efectua adunarea și înmulțirea a două polinoame.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

// alias pentru o declaratie prea lunga
// map este declarat cu o ordine inversa a cheilor
typedef std::map<unsigned int, float, std::greater<unsigned int>> dict;

class Polinom {
   public:
	// constructori
	Polinom() { this->dictionary = {}; };
	Polinom(dict poly_map) { this->dictionary = poly_map; }
	Polinom(const Polinom& poly) { this->dictionary = poly.dictionary; }

	// afiseaza continutul unui polinom
	void print_poly() {
		// FIXME: afisarea poate fi facuta mai corect, dar nu e cazul aici
		// https://github.com/alin-c/CS/blob/master/Fundamentele%20algebrice%20ale%20informaticii/T8_polynomials.py
		char _coefficient[15];  // FIXME: magic number
		string poly_text;

		for (auto item : this->dictionary) {
			// formateaza floatul in format generic
			sprintf(_coefficient, "%g", item.second);
			string coefficient(_coefficient);
			if (item.second > 0) {
				coefficient = '+' + coefficient;
			}
			string exponent = to_string(item.first);
			poly_text.append(coefficient + "X" + exponent);
		}

		cout << poly_text;
	}

	// overload pentru +
	Polinom operator+(Polinom poly) {
		dict result = this->dictionary;
		dict term = poly.dictionary;

		for (auto item : term) {
			if (result.find(item.first) != result.end()) {
				// daca exponentul este comun, aduna coeficientii corespunzatori
				result[item.first] += term[item.first];
			} else {
				// altfel insereaza in rezultat elementul lipsa
				result.insert({item.first, item.second});
			}
		}

		Polinom sum;
		sum.dictionary = result;

		return sum;
	}

	// overload pentru *
	Polinom operator*(Polinom poly) {
		dict factor1 = this->dictionary;
		dict factor2 = poly.dictionary;
		Polinom product;

		for (auto item1 : factor1) {
			for (auto item2 : factor2) {
				Polinom temp;

				// aduna exponentii
				int exponent = item1.first + item2.first;
				// inmulteste coeficientii
				float coefficient = item1.second * item2.second;

				temp.dictionary.insert({exponent, coefficient});

				product = product + temp;
			}
		}

		return product;
	}

   private:
	// dictionar (map) ce reprezinta perechile (exponent, coeficient)
	// exponentul este numar natural
	// coeficientul este numar real
	dict dictionary;
};
/**/
/**
 @brief Entry point
*/
int main() {
	// FIXME: valori hardcodate; ar trebui introduse de utilizator...
	dict a = {{2, 2.31}, {3, 3.14}, {1, 3}};
	dict b = {{2, 4}, {0, 2}};

	Polinom p(a);
	Polinom q(b);

	Polinom r;
	r = p * q;
	Polinom s;
	s = p + q;

	cout << "p = ";
	p.print_poly();
	cout << "\nq = ";
	q.print_poly();
	cout << "\np+q = ";
	s.print_poly();
	cout << "\np*q = ";
	r.print_poly();

	return 0;
}