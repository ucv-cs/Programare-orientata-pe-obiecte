/** C2-3_Student.cpp
 * Implementati clasa Student in care numele se va aloca dinamic.
 */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

/*
enum sex {
	masculin = 1,
	feminin = 2
};

enum facultate {
	stiinte = 1,
	economie = 2,
	drept = 3,
	medicina = 4
};
*/

/**
 * Reprezentarea unui student.
 */
class Student {
	private:
	// atribute ale unui student: nume-prenume, varsta, cnp, sex, adresa, telefon, email, facultate, specializare, an de studiu, serie, grupa, forma de invatamant...

	//nefolosite...
	int varsta;
	string cnp;
	string adresa;
	string telefon;
	string email;


	string separator = "\n-----------------\n\n"; // utilizat doar la afisare

	public:
	string nume_prenume;
	
	// constructor
	Student(string nume) {
		nume_prenume = nume;
	}

	// destructor
	~Student() {
		cout << "\nObiectul a fost distrus!";
	}

	// metode ale unui student: afiseaza(), studiaza(), e_prezent(), rezolva_teme(), da_examen()...

	//
	static string obtineNume(){
		string nume;
		cout << "\nScrie numele studentului: ";
		getline(cin, nume);
		
		return nume;
	}

	// afiseaza metadatele unui student
	void afiseaza() {
		cout << "[afiseaza()]\n";
		cout << nume_prenume;
	}

};

int main() {
	cout << "C2.3: Implementati clasa Student in care numele se va aloca dinamic.\n";
	
	string nume = Student::obtineNume();	
	
	Student student(nume);
	student.afiseaza();

	Student *student2 = new Student(Student::obtineNume());
	student2->afiseaza();

	delete student2;

	cout << "\nApasa orice tasta pentru a inchide aplicatia... ";
	getch();
	return 0;
}