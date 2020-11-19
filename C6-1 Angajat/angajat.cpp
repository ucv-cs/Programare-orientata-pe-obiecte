/**
 * C6-1. Implementaţi clasa Angajat ce derivă din clasa Persoana.
 */
#include <iostream>
using namespace std;

string separator = "\n------------------------\n";

/**
 * Interfața clasei Persoana
 */
class Persoana {
   public:
	Persoana();
	Persoana(string prenume, string nume, unsigned short varsta);
	Persoana(const Persoana& persoana);
	~Persoana();

	void set_prenume(string prenume);
	string get_prenume() const;
	void set_nume(string nume);
	string get_nume() const;
	void set_domiciliu(string domiciliu);
	string get_domiciliu() const;
	void set_varsta(unsigned short varsta);
	unsigned short get_varsta() const;

	void afiseaza() const;

   private:
	string _prenume;
	string _nume;
	string _domiciliu;
	unsigned short _varsta;
};

/**
 * Interfața clasei Angajat
 */
class Angajat : public Persoana {
   public:
	Angajat();
	Angajat(string prenume, string nume, unsigned short varsta,
			string angajator, string functie, unsigned salariu);
	Angajat(const Angajat& angajat);
	~Angajat();

	void set_angajator(string angajator);
	string get_angajator() const;
	void set_functie(string functie);
	string get_functie() const;
	void set_salariu(unsigned salariu);
	unsigned get_salariu() const;

	void afiseaza() const;

   private:
	string _angajator;
	string _functie;
	unsigned _salariu;
};

/**
 * Implementarea clasei Persoana
 */
Persoana::Persoana() {
	_prenume = "";
	_nume = "";
	_varsta = 20;
}

Persoana::Persoana(string prenume, string nume, unsigned short varsta) {
	_prenume = prenume;
	_nume = nume;
	_varsta = varsta;
}

Persoana::Persoana(const Persoana& persoana) {
	_prenume = persoana._prenume;
	_nume = persoana._nume;
	_varsta = persoana._varsta;
}

Persoana::~Persoana() {
	// TBD
}

void Persoana::set_prenume(string prenume) {
	_prenume = prenume;
}

string Persoana::get_prenume() const {
	return _prenume;
}

void Persoana::set_nume(string nume) {
	_nume = nume;
}

string Persoana::get_nume() const {
	return _nume;
}

void Persoana::set_domiciliu(string domiciliu) {
	_domiciliu = domiciliu;
}

string Persoana::get_domiciliu() const {
	return _domiciliu;
}

void Persoana::set_varsta(unsigned short varsta) {
	_varsta = varsta;
}

unsigned short Persoana::get_varsta() const {
	return _varsta;
}

void Persoana::afiseaza() const {
	cout << "\n"
		 << get_prenume() << " " << get_nume() << separator
		 << "Domiciliu: " << get_domiciliu() << "\n"
		 << "Varsta: " << get_varsta();
}

/**
 * Implementarea clasei Angajat
 */
Angajat::Angajat() {
	set_prenume("");
	set_nume("");
	set_varsta(20);
}

Angajat::Angajat(string prenume, string nume, unsigned short varsta,
				 string angajator, string functie, unsigned salariu)
	: Persoana(prenume, nume, 20) {
	set_angajator(angajator);
	set_functie(functie);
	set_salariu(salariu);
}

Angajat::~Angajat() {
	// TBD
}

void Angajat::set_angajator(string angajator) {
	_angajator = angajator;
}

string Angajat::get_angajator() const {
	return _angajator;
}

void Angajat::set_functie(string functie) {
	_functie = functie;
}

string Angajat::get_functie() const {
	return _functie;
}

void Angajat::set_salariu(unsigned salariu) {
	_salariu = salariu;
}

unsigned Angajat::get_salariu() const {
	return _salariu;
}

void Angajat::afiseaza() const {
	Persoana::afiseaza();
	cout << separator << "Angajator: " << get_angajator() << "\n"
		 << "Functie: " << get_functie() << "\n"
		 << "Salariu: " << get_salariu() << " $";
}

// exemple
int main() {
	Angajat ionel("Ionel", "Petrescu", 25, "Alphabet Inc.", "C++ developer",
				  15000);
	ionel.afiseaza();

	cout << "\n";

	Persoana gigel;
	gigel.set_prenume("George");
	gigel.set_nume("Ionescu");
	gigel.set_domiciliu("Craiova");
	gigel.afiseaza();
}