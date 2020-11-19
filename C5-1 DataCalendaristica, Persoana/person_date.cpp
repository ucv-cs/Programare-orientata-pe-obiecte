/**
 * Implementați clasa DataCalendaristică (zi, lună, an) și Persoana(nume, data
 * nașterii).Să se implementeze o metodă care calculează vârsta persoanei la o
 * anumită dată.
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * Interfata clasei DataCalendaristica
 */
class DataCalendaristica {
   public:
	DataCalendaristica();
	DataCalendaristica(int an, int luna, int zi);
	DataCalendaristica(const DataCalendaristica& data);
	~DataCalendaristica();

	// luna si ziua au valorile normale (numarate de la 1...)
	void set_data(int an, int luna, int zi);
	void set_an(int an);
	void set_luna(int luna);
	void set_zi(int zi);
	int get_an() const;
	int get_luna() const;
	int get_zi() const;
	string data_text();
	string durata(DataCalendaristica data);

   private:
	int _an;
	int _luna;	// 1 ... 12
	int _zi;	// 1 ... 31
	static const int zile[12];
};

/**
 * O implementare a clasei DataCalendaristica
 * (implementarea este una naiva, ca simplu exercitiu legat de utilizarea
 * agregarii in clase, si evita folosirea de biblioteci dedicate ex. time,
 * ctime, chrono...)
 */
// numarul maxim de zile din fiecare luna
const int DataCalendaristica::zile[12] = {31, 29, 31, 30, 31, 30,
										  31, 31, 30, 31, 30, 31};

// seteaza 01.01.1970 ca data implicita
DataCalendaristica::DataCalendaristica() {
	_an = 1970;
	_luna = 1;
	_zi = 1;
}

DataCalendaristica::DataCalendaristica(int an, int luna, int zi) {
	set_an(an);
	set_luna(luna);
	set_zi(zi);
}

DataCalendaristica::DataCalendaristica(const DataCalendaristica& data) {
	_an = data._an;
	_luna = data._luna;
	_zi = data._zi;
}

DataCalendaristica::~DataCalendaristica() {
	// TODO
}

void DataCalendaristica::set_data(int an, int luna, int zi) {
	set_an(an);
	set_luna(luna);
	set_zi(zi);
}

void DataCalendaristica::set_an(int an) {
	_an = an;
}

void DataCalendaristica::set_luna(int luna) {
	if (luna > 0 && luna <= 12) {
		_luna = luna;
	} else {
		cout << "Numarul lunii este gresit (" << luna
			 << "). Valoarea trebuie sa fie intre 1 si 12.";
		throw;
	}
}

void DataCalendaristica::set_zi(int zi) {
	if (zi > 0 && zi <= DataCalendaristica::zile[get_luna() - 1]) {
		_zi = zi;
	} else {
		cout << "Numarul zilei este gresit (" << zi << "). Pentru luna data ("
			 << get_luna() << "), valoarea trebuie sa fie intre 1 si "
			 << DataCalendaristica::zile[get_luna() - 1] << ".";
		throw;
	}
}

int DataCalendaristica::get_an() const {
	return _an;
}

int DataCalendaristica::get_luna() const {
	return _luna;
}

int DataCalendaristica::get_zi() const {
	return _zi;
}

string DataCalendaristica::data_text() {
	char durata[15];
	sprintf(durata, "%02d.%02d.%d", get_zi(), get_luna(), get_an());
	return durata;
}

// calcul de durata intre data obiectului curent si data primita de metoda
// v. https://stackoverflow.com/a/33944269
string DataCalendaristica::durata(DataCalendaristica data) {
	int zile_ = 0;
	if (data._zi - this->_zi < 0) {
		int luna = data._luna - 2;
		if (luna < 0) {
			luna = 11;
		}
		zile_ = DataCalendaristica::zile[luna] - 30;
		/* https://en.wikipedia.org/wiki/Leap_year#Algorithm
			if (year is not divisible by 4) then (it is a common year)
			else if (year is not divisible by 100) then (it is a leap year)
			else if (year is not divisible by 400) then (it is a common year)
			else (it is a leap year)
		*/
		if ((luna == 1) && (data._an % 4 == 0) && (data._an % 100) ||
			(data._an % 400 == 0)) {
			zile_++;
		}
	}
	int zile_data1 = this->_an * 360 + this->_luna * 30 + this->_zi;
	int zile_data2 = data._an * 360 + data._luna * 30 + data._zi;
	int diferenta = zile_data2 - zile_data1;

	int ani = diferenta / 360;
	int luni = (diferenta - ani * 360) / 30;
	int zile = diferenta - ani * 360 - luni * 30 + zile_;

	char durata[15];
	sprintf(durata, "%d ani, %d luni, %d zile", ani, luni, zile);
	return durata;
}

/**
 * Interfata clasei Persoana
 */
class Persoana {
   public:
	string prenume;
	string nume;
	DataCalendaristica data_nastere;
	string domiciliu;
	enum sexe { masculin = 1, feminin = 2 } sex;

	Persoana();
	Persoana(const Persoana& persoana);
	~Persoana();

	// calculul varstei la o anume data
	string calcul_varsta(DataCalendaristica data);
};

/**
 * Implementarea clasei Persoana
 */

Persoana::Persoana() {
	this->data_nastere = DataCalendaristica();
}

Persoana::Persoana(const Persoana& persoana) {
	this->prenume = persoana.prenume;
	this->nume = persoana.nume;
	this->data_nastere = persoana.data_nastere;
	this->domiciliu = persoana.domiciliu;
	this->sex = persoana.sex;
}

Persoana::~Persoana() {
	// TODO
}

string Persoana::calcul_varsta(DataCalendaristica data) {
	return this->data_nastere.durata(data);
}

/**
 * Afiseaza varsta unei persoane la data specificata
 */
void afiseaza_varsta(Persoana persoana, DataCalendaristica data) {
	cout << "La data de " << data.data_text() << ", " << persoana.prenume << " "
		 << persoana.nume << " (n. " << persoana.data_nastere.data_text()
		 << ") avea varsta de " << persoana.calcul_varsta(data) << ".\n";
}

// exemplu
int main() {
	DataCalendaristica data(2020, 4, 3);

	Persoana primus;
	primus.prenume = "Georgel";
	primus.nume = "Ionescu";
	primus.data_nastere = DataCalendaristica(1977, 7, 3);
	afiseaza_varsta(primus, data);

	Persoana secundus;
	secundus.prenume = "Ionela";
	secundus.nume = "Popescu";
	secundus.data_nastere = DataCalendaristica(2000, 5, 5);
	afiseaza_varsta(secundus, data);

	Persoana tertius;
	tertius.prenume = "Ion";
	tertius.nume = "Georgescu";
	tertius.data_nastere = DataCalendaristica(1982, 6, 4);
	afiseaza_varsta(tertius, data);
}