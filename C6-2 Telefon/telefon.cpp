/**
 * C6-2. Implementați ierarhia de clase Telefon, TelefonFix, TelefonMobil.
 */
#include <iostream>
using namespace std;

string separator = "\n------------------------\n";

/**
 * Interfața clasei Telefon
 */
class Telefon {
   public:
	Telefon();
	Telefon(string numar);
	Telefon(string numar, string retea);
	Telefon(string numar, string retea, string model);
	Telefon(const Telefon& telefon);
	~Telefon();

	void set_model(string model);
	string get_model() const;
	void set_retea(string retea);
	string get_retea() const;
	void set_numar(string numar);
	string get_numar() const;

	void afisare() const;

   private:
	string _model = "";
	string _retea = "";
	string _numar = "";  // string pentru valori precum +4074... sau 0351...
};

/**
 * Interfața clasei TelefonFix
 */
class TelefonFix : public Telefon {
   public:
	TelefonFix() : Telefon(){};
	TelefonFix(string numar) : Telefon(numar){};
	TelefonFix(string numar, string retea) : Telefon(numar, retea){};
	TelefonFix(string numar, string retea, string model)
		: Telefon(numar, retea, model){};
	TelefonFix(string numar, string retea, string model, string interfata)
		: Telefon(numar, retea, model) {
	}
	TelefonFix(const TelefonFix& telefon);
	~TelefonFix();

	void set_interfata(string interfata);
	string get_interfata() const;

	void afisare() const;

   private:
	string _interfata = "cu butoane";  // cu butoane, cu roata; poate fi un enum
};

/**
 * Interfața clasei TelefonMobil
 */
class TelefonMobil : public Telefon {
   public:
	TelefonMobil();
	TelefonMobil(string numar) : Telefon(numar){};
	TelefonMobil(string numar, string retea) : Telefon(numar, retea){};
	TelefonMobil(string numar, string retea, string model)
		: Telefon(numar, retea, model){};
	TelefonMobil(const TelefonMobil& telefon);
	~TelefonMobil();

	void set_tip(string tip);
	string get_tip() const;
	void set_sistem_operare(string sistem_operare);
	string get_sistem_operare() const;
	void set_conexiune(string conexiune);
	string get_conexiune() const;
	void set_dual_sim(bool is_dual_sim);
	string get_dual_sim() const;
	void set_stocare(unsigned stocare);
	unsigned get_stocare() const;

	void afisare() const;

   private:
	string _tip = "smart";  // smart sau "dumb"; poate fi un enum
	string _sistem_operare = "Android";
	string _conexiune = "4G";  // 2G, 3G, 4G...
	bool _is_dual_sim = false;
	unsigned _stocare = 16;  // GB, s.a.m.d. pentru alte caracteristici
};

/**
 * Implementarea clasei Telefon
 */
Telefon::Telefon() {
}

Telefon::Telefon(string numar) {
	_numar = numar;
}

Telefon::Telefon(string numar, string retea) {
	_retea = retea;
	_numar = numar;
}

Telefon::Telefon(string numar, string retea, string model) {
	_model = model;
	_retea = retea;
	_numar = numar;
}

Telefon::Telefon(const Telefon& telefon) {
	_model = telefon._model;
	_retea = telefon._retea;
	_numar = telefon._numar;
}

Telefon::~Telefon() {
	// TBD
}

void Telefon::set_model(string model) {
	_model = model;
}

string Telefon::get_model() const {
	return _model;
}

void Telefon::set_retea(string retea) {
	_retea = retea;
}

string Telefon::get_retea() const {
	return _retea;
}

void Telefon::set_numar(string numar) {
	_numar = numar;
}

string Telefon::get_numar() const {
	return _numar;
}

void Telefon::afisare() const {
	cout << "\n"
		 << get_numar() << separator << "Model: " << get_model() << "\n"
		 << "Retea: " << get_retea() << separator;
}

/**
 * Implementarea clasei TelefonFix
 */
TelefonFix::TelefonFix(const TelefonFix& telefon) {
	set_model(telefon.get_model());
	set_retea(telefon.get_retea());
	set_numar(telefon.get_numar());
	_interfata = telefon._interfata;
}

TelefonFix::~TelefonFix() {
	// TBD
}

void TelefonFix::set_interfata(string interfata) {
	_interfata = interfata;
}

string TelefonFix::get_interfata() const {
	return _interfata;
}

void TelefonFix::afisare() const {
	Telefon::afisare();
	cout << "\nInterfata: " << get_interfata();
}

/**
 * Implementarea clasei TelefonMobil
 */
TelefonMobil::TelefonMobil() {
	// TBD
}

TelefonMobil::TelefonMobil(const TelefonMobil& telefon) {
	set_model(telefon.get_model());
	set_retea(telefon.get_retea());
	set_numar(telefon.get_numar());
	_tip = telefon._tip;
	_sistem_operare = telefon._sistem_operare;
	_conexiune = telefon._conexiune;
	_is_dual_sim = telefon._is_dual_sim;
	_stocare = telefon._stocare;
}

TelefonMobil::~TelefonMobil() {
	// TBD
}

void TelefonMobil::set_tip(string tip) {
	_tip = tip;
}

string TelefonMobil::get_tip() const {
	return _tip;
}

void TelefonMobil::set_sistem_operare(string sistem_operare) {
	_sistem_operare = sistem_operare;
}

string TelefonMobil::get_sistem_operare() const {
	return _sistem_operare;
}

void TelefonMobil::set_conexiune(string conexiune) {
	_conexiune = conexiune;
}

string TelefonMobil::get_conexiune() const {
	return _conexiune;
}

void TelefonMobil::set_dual_sim(bool is_dual_sim) {
	_is_dual_sim = is_dual_sim;
}

string TelefonMobil::get_dual_sim() const {
	return _is_dual_sim ? "Da" : "Nu";
}

void TelefonMobil::set_stocare(unsigned stocare) {
	_stocare = stocare;
}

unsigned TelefonMobil::get_stocare() const {
	return _stocare;
}

void TelefonMobil::afisare() const {
	Telefon::afisare();
	cout << "Tip: " << get_tip()
		 << "\nSistem de operare: " << get_sistem_operare()
		 << "\nConexiune: " << get_conexiune()
		 << "\nDual sim: " << get_dual_sim() << "\nStocare: " << get_stocare()
		 << " GB";
}

// exemple
int main() {
	TelefonMobil mobil("071234567");
	mobil.set_model("Xiaomi K20 Pro");
	mobil.set_retea("Vodafone");
	mobil.set_stocare(128);
	mobil.set_dual_sim(true);
	mobil.afisare();

	cout << "\n";

	TelefonFix fix("025100032202", "Digi", "Alcatel");
	fix.afisare();
}