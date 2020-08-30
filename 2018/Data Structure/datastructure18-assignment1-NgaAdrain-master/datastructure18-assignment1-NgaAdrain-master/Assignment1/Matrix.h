#pragma once			//Electrical Engineering and Computer Science 
#include <iostream>		//Computer Science Major Undergraduate Course 
				//sophomore 201524582 정희석(Jeong Hee Seok) 
#include <ctime>		//srand의 seed를 time으로 하기 위함 (for using time to random's seed)
#include <cstdlib>		//rand사용 (for using rand)
using namespace std;
// 보통 행렬에 대하여add, sub, multiply, transpose 구현하는 코딩 

class Matrix {

public:

	Matrix(int row, int col);

	int GetData();

	Matrix Transpose();

	int Display();

	//Matrix Add(Matrix b);

	Matrix Multiply(Matrix b);

	int CompareRowCol(Matrix b);

private:

	int rows, cols;

	//int Term[rows][cols]; 2-division array

	int *Term;			//the add 2.6ress of a[i][j] = 0 + i * cols + j => Fig2.6 
					//=> 2-division array to raw-major 1-division array  
};



Matrix::Matrix(int row, int col) : rows(row), cols(col)

{

	Term = new int[rows * cols];	// raw-major

}



int Matrix::GetData() {
	srand(time(NULL));

	cout << "rows = " << rows << "  cols = " << cols << endl;

	for (int j = 0; j < rows * cols; j++)

	{
		Term[j] = (rand() % 10) + 1;	//1~10사이 난수생성 -> Term에 차례차례 저장 => 배열 생성!	
	}					//make random number between 1 to 10 -> linearly save to Term => making Array!

	return 0;

}



Matrix Matrix::Transpose() {

	Matrix trans_b(cols, rows);	//result : for return transposed Matrix 

	for (int index_col = 0; index_col < cols; index_col++)			//because Matrix original's column -> Matrix b's row
		for (int index_row = 0; index_row < rows; index_row++) {	//because Matrix original's row -> Matrix b's column
			trans_b.Term[(index_col*cols) + index_row] = Term[(index_row*rows) + index_col];
		}	// ㄴ> because integers are saved to row-major-order -> example) row = 5 column = 5 
	return trans_b;	//trans_b[1]=trans_b[column*0+1] = Matrix original[5] = original[1*row+0]
}



Matrix Matrix::Multiply(Matrix b) {
	if (cols != b.rows) cout << "Incompatible matrices" << endl;

	else {
		Matrix bXpose = b.Transpose();

		Matrix d(rows, b.cols);	//for result of Multiplied between Matrix original with Matrix b

		for (int i = 0; i < rows*b.cols; i++) { //i is index of Matrix d
			int i_q = (int)i / b.cols;// = bXpose.rows; //quotient is related to original matrix's index
			int i_r = (int)i % b.cols;// = bXpose.rows; //remainder is related to opponent matrix's index
			d.Term[i] = 0;
			for (int j = 0; j < cols; j++) {
				d.Term[i] += Term[(i_q*rows) + j] * bXpose.Term[(i_r*rows) + j]; // <- transpose
				//d.Term[i] += Term[(i_q*rows) + j] * b.Term[(b.cols*j) + i_r];		//<- non transpose	
			}
		}
		return d;
	}
}

int Matrix::CompareRowCol(Matrix b) {

	if (cols != b.rows) return 1;

	else return 0;

}

int Matrix::Display() {

	int n;

	n = rows * cols;

	for (int i = 0; i < rows; i++)

	{

		cout << endl;

		for (int j = 0; j < cols; j++)

			cout << Term[i*cols + j] << " ";

	}

	cout << endl;

	return 0;

}
