#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<class T>
class Matrix {
public:
	Matrix(int r = 0, int c = 0);
	Matrix(const Matrix<T>& m);
	//~Matrix() { delete[] element; }
	int Rows() const { return rows; }
	int Columns() const { return cols; }
	T& operator() (int i, int j);
	void Start(int inputRow, int inputColu);
	void Move(int moveRow, int moveColumn);
	void Display();
	bool FindZeroElement();
private:
	int rows, cols;
	int nowRows, nowCols;
	int moveCount = 0;
	T *element;
};

template<class T>
Matrix<T>::Matrix(int r, int c) : rows(r),cols(c)
{
	rows = r;
	cols = c;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m) : rows(m.Rows()), cols(m.Cols())
{
	element = new T[rows*cols];
	for (int index = 0; index < rows*cols; index++)
		element[index] = m.element[index];
}

template<class T>
T& Matrix<T>::operator()(int i, int j) 
{
	rows = i;
	cols = j;
   	moveCount = 0;
	element = new T[rows*cols];
	for (int index = 0; index < rows*cols; index++)
		element[index] = 0;
	/*
	if ((rows <= i) || (cols <= j)) {
		cout << "해당 위치는 없습니다." << endl;
		exit(0);
	}
	*/
	return element[rows*j+i];
}

template<class T>
void Matrix<T>::Start(int inputRow, int inputColu)
{
	nowRows = inputRow;
	nowCols = inputColu;
	element[rows*inputColu + inputRow] = 1;
	moveCount = 1;
}

template<class T>
void Matrix<T>::Move(int moveRow, int moveColumn)
{
	nowRows += moveRow;
	nowCols += moveColumn;
	if (nowRows < 0)
		nowRows = 0;
	else if (nowRows >= rows)
		nowRows -= moveRow;
	if (nowCols < 0)
		nowCols = 0;
	else if (nowCols >= cols)
		nowCols -= moveColumn;
	else{
		element[rows*nowCols + nowRows] += 1;
		moveCount++;
	}
}

template<class T>
void Matrix<T>::Display()
{
	for (int indexColumn = 0; indexColumn < cols; indexColumn++) {
		for (int indexRow = 0; indexRow < rows; indexRow++){
			cout << "(" << indexRow << "," << indexColumn << ") ";
			cout << element[rows*indexColumn + indexRow] << "번 지나감" << endl;
		}
	}
	cout << rows << " X " << cols ;
	cout << " 판 위에서 바퀴벌레의 총 이동수 : " << moveCount << endl;
}

template<class T>
bool Matrix<T>::FindZeroElement() {
	bool result = false;
	for (int index = 0; index < rows*cols; index++)
		if (element[index] == 0) {
			result = true;
			break;
		}
		else
			continue;
	return result;
}


