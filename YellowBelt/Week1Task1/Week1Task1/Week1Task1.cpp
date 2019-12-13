#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Matrix {
public:
	Matrix() {
		matrix.resize(0);
	}
	Matrix(int new_rows, int new_cols) {
		IsSizeNotLessThanZero(new_rows, new_cols);
			matrix.resize(new_rows);
			for (auto m : matrix) {
				m.resize(new_cols);
			}
	}
	void Reset(int new_rows, int new_cols) {
		IsSizeNotLessThanZero(new_rows, new_cols);
		matrix.resize(new_rows);
		for (auto m : matrix) {
			//m.assign(new_cols, 0);
		}
	}
	int At(int num_row, int num_col) const {
		IsSizeValid(num_row, num_col);
		return matrix.at(num_row).at(num_col);
	}
	int& At(int num_row, int num_col) {
		IsSizeValid(num_row, num_col);
		return matrix.at(num_row).at(num_col);
	}
	int GetNumRows() const {
		return matrix.size();
	}
	int GetNumColumns() const {
		return matrix.at(0).size();
	}

private:
	void IsSizeValid(int num_row, int num_col) const {
		if ((num_row > matrix.size()) || (num_row < 0)) {
			throw out_of_range(to_string(num_row));
		}
		else if ((num_col > matrix.size()) || (num_col < 0)) {
			throw out_of_range(to_string(num_col));
		}
	}
	void IsSizeNotLessThanZero(int num_row, int num_col) const {
		if (num_row < 0) {
			throw out_of_range(to_string(num_row));
		}
		else if (num_col < 0) {
			throw out_of_range(to_string(num_col));
		}
	}
	vector<vector<int>> matrix;
};
// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

istream& operator>>(istream& stream, Matrix& matrix) {

	int num_rows, num_cols;
	stream >> num_rows >> num_cols;
	matrix.Reset(num_rows, num_cols);
	//cout << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int i = 0; i < matrix.GetNumRows(); ++i) {
		for (int j = 0; j < matrix.GetNumColumns(); ++j) {
			stream >> matrix.At(i, j);
		}
	}

	return stream;
}

ostream& operator<<(ostream& stream, Matrix& matrix) {

	stream << matrix.GetNumRows() << matrix.GetNumColumns() << endl;
		for (int i = 0; i < matrix.GetNumRows(); ++i) {
			for (int j = 0; j < matrix.GetNumColumns(); ++j) {
				stream << matrix.At(i, j);
			}
			cout << endl;
		}
	return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
		return false;
	}
	for (int i = 0; i < rhs.GetNumRows(); ++i) {
		for (int j = 0; j < rhs.GetNumColumns(); ++j) {
			if (lhs.At(i, j) != rhs.At(i, j)) {
				return false;
			}
		}
	}
	return true;
}

Matrix& operator+(const Matrix& lhs, const Matrix& rhs) {
	if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
		throw invalid_argument("wrong size");
	}

	Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int i = 0; i < rhs.GetNumRows(); ++i) {
		for (int j = 0; j < rhs.GetNumColumns(); ++j) {
			if (lhs.At(i, j) != rhs.At(i, j)) {
				result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
			}
		}
	}
	return result;
}

int main() {
	Matrix one;
	Matrix two;
	//one.Reset(3, 5);
	cin >> one;/* >> two;
	cout << one + two << endl;*/
	return 0;
}
