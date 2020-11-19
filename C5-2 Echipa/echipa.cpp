/**
 * Realizați diagrama de clase UML pentru a reprezenta următoarele clase:
 * - Jucător de fotbal
 * - Echipă
 * Să se implementeze în C++ aceste clase.
 */
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/**
 * Interfata clasei JucatorFotbal
 */
class JucatorFotbal {
   public:
	JucatorFotbal();
	JucatorFotbal(string nume);
	JucatorFotbal(const JucatorFotbal& jucator);
	~JucatorFotbal();

	unsigned get_id();
	void set_id(unsigned id);
	string get_nume();
	void set_nume(string nume);
	unsigned short get_numar();
	void set_numar(unsigned short numar);
	string get_rol();
	void set_rol(string rol);

	void afiseaza_jucator();

	void paseaza(JucatorFotbal coechipier);
	void alearga(int x, int y);
	void suteaza(int x, int y);

   private:
	unsigned _id;
	string _nume;
	unsigned short _numar;
	string _rol;
};

/**
 * Interfata clasei Echipa
 */
class Echipa {
   public:
	Echipa(string nume);
	Echipa(const Echipa& echipa);
	~Echipa();
	string get_nume();
	void set_nume(string nume);
	void inlocuieste_jucator(JucatorFotbal out, JucatorFotbal in);
	void cumpara_jucator(JucatorFotbal jucator);
	void vinde_jucator(JucatorFotbal jucator);
	void afiseaza_echipa();

   private:
	string _nume;
	// FIXME: listele pot fi implementate folosind alte tipuri de date - ex.
	// vector
	JucatorFotbal* _jucatori_activi;
	unsigned _numar_activi = 11;
	JucatorFotbal* _jucatori_rezerva;
	unsigned _numar_rezerve = 15;
};

/**
 * O implementare a clasei JucatorFotbal
 */
JucatorFotbal::JucatorFotbal() {
	this->_nume = "Prenume Nume";
}

JucatorFotbal::JucatorFotbal(string nume) {
	this->_nume = nume;
}

JucatorFotbal::JucatorFotbal(JucatorFotbal& jucator) {
	this->_nume = jucator._nume;
}

JucatorFotbal::~JucatorFotbal() {
	// TBD
	// cout << "dtor JucatorFotbal\n";
}

unsigned JucatorFotbal::get_id() {
	return this->_id;
}

void JucatorFotbal::set_id(unsigned id) {
	this->_id = id;
}

string JucatorFotbal::get_nume() {
	return this->_nume;
}

void JucatorFotbal::set_nume(string nume) {
	this->_nume = nume;
}

unsigned short JucatorFotbal::get_numar() {
	return this->_numar;
}

void JucatorFotbal::set_numar(unsigned short numar) {
	this->_numar = numar;
}

string JucatorFotbal::get_rol() {
	return this->_rol;
}

void JucatorFotbal::set_rol(string rol) {
	this->_rol = rol;
}

void JucatorFotbal::afiseaza_jucator() {
	cout << this->get_nume() << " are numarul " << this->get_numar()
		 << " si este " << this->get_rol() << ".\n";
}

void JucatorFotbal::paseaza(JucatorFotbal coechipier) {
	cout << this->get_nume() << " a pasat catre " << coechipier.get_nume()
		 << "\n";
}

void JucatorFotbal::alearga(int x, int y) {
	cout << this->get_nume() << " alearga spre punctul (" << x << ", " << y
		 << ")"
		 << "\n";
}

void JucatorFotbal::suteaza(int x, int y) {
	cout << this->get_nume() << " suteaza catre punctul (" << x << ", " << y
		 << ")"
		 << "\n";
}

/**
 * O implementare a clasei Echipa
 */
Echipa::Echipa(string nume) {
	this->_nume = nume;

	// completeaza echipa cu 11 anonimi
	JucatorFotbal activi[11];
	this->_jucatori_activi = activi;
	for (int i = 0; i < _numar_activi; i++) {
		this->_jucatori_activi[i] = JucatorFotbal();
		this->_jucatori_activi[i].set_numar(i + 1);
		this->_jucatori_activi[i].set_id(i + 1 + 1e6);
	}

	// si 15 rezerve...
	JucatorFotbal rezerve[15];
	this->_jucatori_rezerva = rezerve;
	for (int i = 0; i < _numar_rezerve; i++) {
		this->_jucatori_rezerva[i] = JucatorFotbal();
		this->_jucatori_rezerva[i].set_numar(i + 12);
		this->_jucatori_rezerva[i].set_id(i + 12 + 1e6);
	}
}

Echipa::~Echipa() {
	delete[] _jucatori_activi;
	delete[] _jucatori_rezerva;
}

string Echipa::get_nume() {
	return this->_nume;
}

void Echipa::set_nume(string nume) {
	this->_nume = nume;
}

void Echipa::inlocuieste_jucator(JucatorFotbal iese, JucatorFotbal intra) {
	// TBD: iese trece in lista _jucatori_rezerva, iar intra trece in lista
	// _jucatori_activi
}

void Echipa::cumpara_jucator(JucatorFotbal jucator) {
	// TBD: jucator se adauga implicit la lista _jucatori_rezerva
}

void Echipa::vinde_jucator(JucatorFotbal jucator) {
	// TBD: jucator se elimina din _jucatori_activi si _jucatori_rezerva
}

void Echipa::afiseaza_echipa() {
	cout << "Echipa " << this->get_nume() << " are urmatoarea componenta:\n";
	for (int i = 0; i < this->_numar_activi; i++) {
		cout << setw(4) << std::right << _jucatori_activi[i].get_numar() << ". "
			 << setw(15) << std::left << _jucatori_activi[i].get_nume() << " "
			 << setw(10) << _jucatori_activi[i].get_rol() << " "
			 << _jucatori_activi[i].get_id() << "\n";
	}
}

// exemplu
int main() {
	Echipa ucv("Universitatea Craiova");
	ucv.afiseaza_echipa();
}