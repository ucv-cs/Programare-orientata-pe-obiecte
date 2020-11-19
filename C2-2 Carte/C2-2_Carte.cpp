/** C2-2_Carte.cpp
 * Implementati clasa Carte.
 */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * Reprezentarea unei carti.
 */
class Carte {
	private:
	// atribute ale unei carti: titlu, autori, an, editie, editura, volum, numar de pagini
	string titlu;
	string autori; // putea fi string[], dar pentru moment e o complicatie inutila
	string an; // putea fi int
	string editie;
	string volum;
	string editura;
	string numarPagini; // putea fi int
	string separator = "\n-----------------\n\n"; // utilizat doar la afisare

	public:
	// metode ale unei carti: adauga(), citeste(), afiseaza()
	// adauga metadatele unei carti
	void adauga() {
		cout << "Scrie informatiile despre carte" << endl;
		
		cout << "Titlu: ";
		getline(cin, titlu);

		cout << "Autor(i): ";
		getline(cin, autori);

		cout << "An: ";
		getline(cin, an);

		cout << "Editura: ";
		getline(cin, editura);

		cout << "Editie: ";
		getline(cin, editie);

		cout << "Volum: ";
		getline(cin, volum);

		cout << "Numar de pagini: ";
		getline(cin, numarPagini);

		cout << endl << "Datele cartii au fost inregistrate." << separator;
	}

	// comunica utilizatorului ca s-a accesat metoda citeste()
	void citeste() {
		cout << "[citeste()] cartea \"" << titlu << "\" este citita." << separator;
	}

	// afiseaza metadatele unei carti
	void afiseaza() {
		cout << "[afiseaza()]\n" ;
		cout << "Cartea \"" << titlu << "\" are urmatoarele atribute:" << endl;
		cout << "Titlu: \"" << titlu << "\"\n";
		cout << "Autor(i): " << autori << endl;
		cout << "An: " << an << endl;
		cout << "Editura: " << editura << endl;
		cout << "Editie: " << editie << endl;
		cout << "Volum: " << volum << endl;
		cout << "Numar de pagini: " << numarPagini << separator;
	}
};

int main() {
	cout << "C2.2: Implementati clasa Carte.\n\n";
	Carte carte;

	carte.adauga();
	carte.citeste();
	carte.afiseaza();

	cout << "Apasa orice tasta pentru a inchide aplicatia... ";
	getch();
	return 0;
}