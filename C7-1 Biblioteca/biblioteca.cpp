/**
 * C7-1. Intr-o biblioteca se gasesc mai multe tipuri de materiale. Fiecare
 * material are un numar unic de identificare (cota) si un titlu. Aceste
 * materiale pot fi carti, reviste si CD-uri. Implementati o ierarhie de clase
 * care reprezinta aceste materiale si clasa Biblioteca ce include metode pentru
 * gestiunea materialelor.
 */
#include <iostream>
#include <string>
using namespace std;

string separator = "\n------------------------\n";

// pentru brevitatea codului am combinat interfetele cu implementarile...
// din acelasi motiv nu am folosit nici constructori de copiere, overloaduri
// etc.
// am scris totusi getteri si setteri, chiar daca nu fac alterari sau procesari
// la membrii privati
class Publicatie {	// se putea numi si Material, dar Publicatie pare mai
					// sugestiv
   public:
	Publicatie() {
		_cota = "-";
		_autor = "";
		_titlu = "";
	}

	Publicatie(string cota, string autor, string titlu) {
		_cota = cota;
		_autor = autor;
		_titlu = titlu;
	}

	~Publicatie() {
		// TBD
	}

	void reseteaza() {
		_cota = "-";
		_autor = "";
		_titlu = "";
	}

	virtual void afiseaza() {
		cout << "Hmmm";
	}

	string get_autor() const {
		return _autor;
	}

	string get_cota() const {
		return _cota;
	}

	string get_titlu() const {
		return _titlu;
	}

	bool get_imprumutata() const {
		return _imprumutata;
	}

	void set_autor(string autor) {
		_autor = autor;
	}

	void set_cota(string cota) {
		_cota = cota;
	}

	void set_titlu(string titlu) {
		_titlu = titlu;
	}

	void set_imprumutata(bool imprumutata = true) {
		_imprumutata = imprumutata;
	}

   protected:
	string _autor;
	string _cota = "-";	 // folosita ca id; daca e "-" obiectul de "gol"
	string _titlu;

	bool _imprumutata = false;
};

class Carte : public Publicatie {
   public:
	Carte(string cota, string autor, string titlu)
		: Publicatie(cota, autor, titlu) {
	}

	~Carte() {
		// TBD
	}

	void afiseaza() {
		if (get_cota().compare("-") != 0) {
			cout << "\nCarte: " << get_cota() << " / " << get_titlu() << "\n"
				 << get_autor() << separator;
		}
	}

	// putea avea si alte metadate, ex. domeniu...
};

class Revista : public Publicatie {
   public:
	Revista(string cota, string autor, string titlu)
		: Publicatie(cota, autor, titlu) {
	}

	~Revista() {
		// TBD
	}

	void afiseaza() {
		if (get_cota().compare("-") != 0) {
			cout << "\nRevista: " << get_cota() << " / " << get_titlu() << "\n"
				 << get_autor() << separator;
		}
	}

	// putea avea si alte metadate, ex. periodicitate, domeniu...
};

class CD : public Publicatie {
   public:
	CD(string cota, string autor, string titlu)
		: Publicatie(cota, autor, titlu) {
	}

	~CD() {
		// TBD
	}

	void afiseaza() {
		if (get_cota().compare("-") != 0) {
			cout << "\nCD: " << get_cota() << " / " << get_titlu() << "\n"
				 << get_autor() << separator;
		}
	}

	// putea avea si alte metadate, ex. gen...
};

class Biblioteca {
   public:
	Biblioteca(unsigned capacitate = 100) {
		_capacitate = capacitate;
		Publicatie** colectie = new Publicatie*[_capacitate];
		for (unsigned i = 0; i < _capacitate; i++) {
			colectie[i] = nullptr;
		}
		_colectie = colectie;
	}

	~Biblioteca() {
		delete[] _colectie;
	}

	void adauga_publicatie(Publicatie* publicatie) {
		// TBD: verificari inainte de inserare (ex. daca exista cota, daca mai e
		// loc etc.)
		for (unsigned i = 0; i < _capacitate; i++) {
			if (_colectie[i] == nullptr ||
				_colectie[i]->get_cota().compare("-") == 0) {
				_colectie[i] = publicatie;
				_contor_colectie++;
				return;
			}
		}

		cout << "Publicatia nu a fost adaugata din lipsa de spatiu sau "
				"intrucat exista deja.";
	}

	void elimina_publicatie(string cota) {
		for (unsigned i = 0; i < _capacitate; i++) {
			if (_colectie[i] != nullptr &&
				_colectie[i]->get_cota().compare(cota) == 0) {
				_colectie[i]->reseteaza();
				_contor_colectie -= 1;
				return;
			}
		}
	}

	void imprumuta_publicatie(string cota) {
		for (unsigned i = 0; i < _capacitate; i++) {
			if (_colectie[i] != nullptr &&
				_colectie[i]->get_cota().compare(cota) == 0) {
				_colectie[i]->set_imprumutata();
				return;
			}
		}
	}

	void afiseaza_publicatii() {
		cout << "Biblioteca are " << _contor_colectie << " publicatii.\n";

		for (unsigned i = 0; i < _capacitate; i++) {
			if (_colectie[i] != nullptr) {
				_colectie[i]->afiseaza();
			}
		}
	}

	bool este_imprumutata(string cota) {
		for (unsigned i = 0; i < _capacitate; i++) {
			if (_colectie[i]->get_cota().compare(cota) == 0) {
				return _colectie[i]->get_imprumutata();
			}
		}
		return false;
	}
	Publicatie** _colectie;

   private:
	unsigned _capacitate;
	unsigned _contor_colectie = 0;
};

// exemple
int main() {
	Biblioteca biblioteca(10);
	Carte carte1("10.100/1", "Stapanul inelelor", "J. R. R. Tolkien");

	biblioteca.adauga_publicatie(&carte1);

	Carte carte2("10.100/2", "Harry Potter", "J. K. Rowling");
	biblioteca.adauga_publicatie(&carte2);

	CD cd1("1.2/1", "Best of U2", "U2");
	biblioteca.adauga_publicatie(&cd1);

	Revista revista1("2.1/1", "National Geographic", "Burda Romania");
	biblioteca.adauga_publicatie(&revista1);

	biblioteca.afiseaza_publicatii();

	biblioteca.elimina_publicatie("1.2/1");

	cout << "\nAm Eliminat CD-ul cu cota 1.2/1:\n";
	biblioteca.afiseaza_publicatii();
}