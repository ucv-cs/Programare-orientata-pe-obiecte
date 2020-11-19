/**
 C4-2. Implementați clasa Matrice reprezentată sub forma unui tablou
 unidimensional alocat dinamic. Supraîncărcați operatorii + (suma),
 * (produs), = (atribuire), [] (accesul la elementele matricei).
*/
#include <iomanip>
#include <iostream>
using namespace std;

class Matrix {
   public:
	// constructori
	Matrix(unsigned rows, unsigned columns) {
		if (rows == 0 || columns == 0) {
			cout << "Numarul de linii sau de coloane nu poate fi 0.";
			return;
		}
		this->rows_ = rows;
		this->columns_ = columns;
		this->list_ = new double[rows * columns];
		for (int i = 0; i < rows * columns; i++) {
			this->list_[i] = 0;
		}
		// cout << "\nconstructor (params)\n";
	}

	Matrix(const Matrix& matrix) {
		this->rows_ = matrix.rows_;
		this->columns_ = matrix.columns_;
		this->list_ = matrix.list_;
		// cout << "\nconstructor de copiere\n";
	}

	// destructor
	~Matrix() {
		// delete[] list_;
		// cout << "\ndestructor\n";
	}

	// afiseaza continutul matricei
	void print_matrix() {
		cout << '\n';
		for (int i = 0; i < this->rows_; i++) {
			for (int j = 0; j < this->columns_; j++) {
				cout << this->operator()(i, j) << " ";
			}
			cout << '\n';
		}
	}

	// overload pentru +
	Matrix operator+(Matrix matrix) {
		// verifica daca matricele sunt compatibile; i.e. au acelasi numar de
		// linii si de coloane
		if (this->rows_ == matrix.rows_ && this->columns_ == matrix.columns_) {
			Matrix sum = *this;

			for (int i = 0; i < sum.rows_; i++) {
				for (int j = 0; j < sum.columns_; j++) {
					sum(i, j) += matrix(i, j);
				}
			}

			return sum;
		} else {
			printf(
				"\nMatricele de forma [%d][%d] si [%d][%d] nu sunt "
				"compatibile.",
				this->rows_, this->columns_, matrix.rows_, matrix.columns_);
			throw runtime_error("Error in sum.");
		}
	}

	// overload pentru *
	Matrix operator*(Matrix matrix) {
		// verifica daca matricele sunt compatibile; i.e. numarul de coloane din
		// prima este egal cu numarul de linii din a doua
		if (this->columns_ == matrix.rows_) {
			Matrix product(this->rows_, matrix.columns_);
			product.print_matrix();

			for (int i = 0; i < this->rows_; i++) {
				cout << "\n" << i;
				for (int j = 0; j < matrix.columns_; j++) {
					cout << "\n\t" << j;
					double sum = 0;
					for (int k = 0; k < matrix.rows_; k++) {
						printf("\n\t\tk=%d:\n\t\tp=%g this=%g  matrix=%g\n", k,
							   product(i, j), this->operator()(i, k),
							   matrix(k, j));
						sum += this->operator()(i, k) * matrix(k, j);
						printf("\t\tp=%g = %g * %g\n", product(i, j),
							   this->operator()(i, k), matrix(k, j));
					}
					product(i, j) = sum;
					cout << product(i, j);
				}
			}

			return product;
		} else {
			printf(
				"\nMatricele de forma [%d][%d] si [%d][%d] nu sunt "
				"compatibile. Numarul de coloane din prima trebuie sa fie egal "
				"cu numarul de linii din a doua.",
				this->rows_, this->columns_, matrix.rows_, matrix.columns_);
			throw runtime_error("Error in product.");
		}
	}

	// overload pentru =
	Matrix& operator=(const Matrix& matrix) {
		if (this != &matrix) {
			this->rows_ = matrix.rows_;
			this->columns_ = matrix.columns_;
			this->list_ = matrix.list_;
		}
		// cout << "\noverload =\n";
		return *this;
	}

	// overload pentru ()
	double operator()(unsigned row, unsigned column) const {
		// TODO: validare
		return list_[columns_ * row + column];
	}

	// overload pentru ()
	double& operator()(unsigned row, unsigned column) {
		// TODO: validare
		return list_[columns_ * row + column];
	}

	// overload pentru []
	// incerc dupa:
	// https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
	// mai intai trebuie creata o clasa membra
	class Row {
	   public:
		double& operator[](unsigned column) {
			return parent_(row_, column);
		}

	   private:
		friend class Matrix;
		Row(Matrix& parent, unsigned row) : parent_(parent), row_(row){};
		Matrix& parent_;
		unsigned row_;
	};
	Row operator[](unsigned row) {
		return Row(*this, row);
	}

   private:
	unsigned rows_;
	unsigned columns_;
	double* list_;  // double nu int pentru ca eventuale noi functionalitati ale
					// clasei (ex. inversa) presupun utilizarea de numere reale
};

/**
 @brief Entry point
*/
int main() {
	Matrix matrix1(2, 3);
	matrix1(0, 0) = 10;  // elementele pot fi adaugate prin (,)
	matrix1(0, 1) = 3;
	matrix1(0, 2) = -3;
	matrix1(1, 0) = 12;
	matrix1(1, 1) = 31;
	matrix1(1, 2) = -2;

	Matrix matrix2(3, 1);
	matrix2(0, 0) = -2;
	matrix2(1, 0) = 0;
	matrix2(2, 0) = 7;

	cout << "\nmatrix1 = ";
	matrix1.print_matrix();
	cout << "\nmatrix2 = ";
	matrix2.print_matrix();

	cout << "\nmatrix2[1][1] = " << matrix2[1][1]
		 << "\n";  // elementele matricei pot fi accesate prin [][]

	// Matrix matrix_sum = matrix1 + matrix2;
	// cout << "\nmatrix1 + matrix2 = ";
	// matrix_sum.print_matrix();  // suma este corecta

	Matrix matrix_product = matrix1 * matrix2;
	cout << "\nmatrix1 * matrix2 = ";
	matrix_product.print_matrix();  // FIXME: produsul este buggy

	return 0;
}