#include <iostream>
#include <exception>

using namespace std;

const int MaxTerms = 100;

char compare(int x, int y)
{
	if (x > y) return '>';
	else if (x < y) return '<';
	else return '=';
}

class SparseMatrix;

class MatrixTerm {
	friend class SparseMatrix;
private:
	int row, col;
	int value;
};


class SparseMatrix
{
public:
	SparseMatrix() {}
	SparseMatrix(int rows, int cols):Rows(rows), Cols(cols) {};
	~SparseMatrix() {}

	SparseMatrix Transpose();
	SparseMatrix FastTranspose();

	SparseMatrix Add(SparseMatrix b) const;

	SparseMatrix Multiply(SparseMatrix b);

	//create an empty matrix
	SparseMatrix EmptyMatrix();

	int StoreSum(int, int&, int, int);
	void Output();
	void OutputToMatrice() const;
	void Init(int*);
	void Init2(int*);
	void Init3(int*);
	//add a new Term to the SparseMatrix
	void addElement(int row, int col, int value);
private:
	int Rows, Cols, Terms = 0;
	MatrixTerm smArray[MaxTerms];

};


void SparseMatrix::Init(int *a)
{
	Rows = 6; Cols = 6; Terms = 8;
	smArray[0].row = 0; smArray[0].col = 0; smArray[0].value = a[0];
	smArray[1].row = 0; smArray[1].col = 3; smArray[1].value = a[1];
	smArray[2].row = 0; smArray[2].col = 5; smArray[2].value = a[2];
	smArray[3].row = 1; smArray[3].col = 1; smArray[3].value = a[3];
	smArray[4].row = 1; smArray[4].col = 2; smArray[4].value = a[4];
	smArray[5].row = 2; smArray[5].col = 3; smArray[5].value = a[5];
	smArray[6].row = 4; smArray[6].col = 0; smArray[6].value = a[6];
	smArray[7].row = 5; smArray[7].col = 2; smArray[7].value = a[7];
}


void SparseMatrix::Init2(int *a)
{
	Rows = 3; Cols = 3; Terms = 5;
	smArray[0].row = 0; smArray[0].col = 0; smArray[0].value = a[0];
	smArray[1].row = 0; smArray[1].col = 2; smArray[1].value = a[1];
	smArray[2].row = 1; smArray[2].col = 1; smArray[2].value = a[2];
	smArray[3].row = 1; smArray[3].col = 2; smArray[3].value = a[3];
	smArray[4].row = 2; smArray[4].col = 0; smArray[4].value = a[4];
}


void SparseMatrix::Init3(int *a)
{
	Rows = 3; Cols = 4; Terms = 3;
	smArray[0].row = 0; smArray[0].col = 2; smArray[0].value = a[0];
	smArray[1].row = 1; smArray[1].col = 0; smArray[1].value = a[1];
	smArray[2].row = 2; smArray[2].col = 3; smArray[2].value = a[2];
}



SparseMatrix SparseMatrix::Transpose()
// return the transpose of a (\(**this\fR)
{
	SparseMatrix b;
	b.Rows = Cols; // rows in b = columns in a
	b.Cols = Rows; // columns in b = rows in a
	b.Terms = Terms; // terms in b = terms in a
	if (Terms > 0) // nonzero matrix
	{
		int CurrentB = 0;
		for (int c = 0; c < Cols; c++) // transpose by columns
			for (int i = 0; i < Terms; i++)
				// find elements in column c
				if (smArray[i].col == c) {
					b.smArray[CurrentB].row = c;
					b.smArray[CurrentB].col = smArray[i].row;
					b.smArray[CurrentB].value = smArray[i].value;
					CurrentB++;
				} // end of if (smArray[i].col == c)
	}
	return b;
} // end of transpose


SparseMatrix SparseMatrix::FastTranspose()
//The transpose of a is placed in b and is found in \*(OH(terms+columns) time.
{
	int *RowSize = new int[Cols];
	int *RowStart = new int[Cols];
	SparseMatrix b;
	b.Rows = Cols; b.Cols = Rows; b.Terms = Terms;
	if (Terms > 0) // nonzero matrix
	{
		int i = 0;
		// compute RowSize[i] = number of terms in row i of b
		for (i = 0; i < Cols; i++) RowSize[i] = 0; // initialize
		for (i = 0; i < Terms; i++) RowSize[smArray[i].col]++;

		//RowStart[i] = starting position of row i in b
		RowStart[0] = 0;
		for (i = 1; i < Cols; i++) RowStart[i] = RowStart[i - 1] + RowSize[i - 1];

		for (i = 0; i < Terms; i++) // move from a to b
		{
			int j = RowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowStart[smArray[i].col]++;
		}  // of for\fR
	} // of if
	return b;
} // of FastTranspose


int SparseMatrix::StoreSum(int sum, int& LastD, int r, int c)
/*If sum != 0, then it along with its row and column position are stored
as the LastD+1'st entry in d.  sum is reset to zero and LastD incremented.*/
{
	//   cout << "LastD:" << LastD << "r:" << r << "c:" << c << "sum:" << sum << endl;
	if (sum != 0) {
		if (LastD < MaxTerms - 1) {
			LastD++;
			smArray[LastD].row = r;
			smArray[LastD].col = c;
			smArray[LastD].value = sum;
			return 0;
		}
		else {
			cout << "Number of terms in product exceeds MaxTerms" << endl;
			return 1; //terminate program
		}
	}
	else return 0;
}// end of StoreSum


SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
//Multiply two sparse matrices A and B producing D.
{
	if (Cols != b.Rows) {
		cout << "Incompatible matrices" << endl;
		return EmptyMatrix();
	};

	if ((Terms == MaxTerms) || (b.Terms == MaxTerms))
	{
		cout << "One additional space in a or b needed" << endl;
		return EmptyMatrix();
	};
	SparseMatrix e = b.FastTranspose();
	SparseMatrix d;
	int i = 0; int LastD = -1; int RowBegin = 0; int r = smArray[0].row;
	// set boundary conditions
	smArray[Terms].row = Rows; e.smArray[b.Terms].row = b.Cols;
	e.smArray[b.Terms].col = -1; int sum = 0;
	while (i < Terms) // generate row r of d
	{
		int c = e.smArray[0].row; int j = 0;
		while (j <= b.Terms) // multiply row r of a by column c of b
		{
			//cout << "i:" << i << " j:" << j << " r:" << r << " c:" << c << endl;
			if (smArray[i].row != r) // end of row r
			{
				//cout << "1: new col" << endl;
				sum = d.StoreSum(sum, LastD, r, c); if (sum) return EmptyMatrix();
				i = RowBegin;
				// go to next column
				while (e.smArray[j].row == c) j++;
				c = e.smArray[j].row;
				continue;
			}
			if (e.smArray[j].row != c) // end of column c of b
			{
				//cout << "2: new row" << endl;
				sum = d.StoreSum(sum, LastD, r, c); if (sum) return EmptyMatrix();
				// set to multiply row r with next column
				i = RowBegin; c = e.smArray[j].row;
				continue;
			}
			switch (compare(smArray[i].col, e.smArray[j].col)) {
			case '<':   // advance to next term in row.
						//cout << "3a: next term in row" << endl;
				i++; break;
			case '=':   // add to sum
						//cout << "3b:  add to sum" << endl;
				sum += smArray[i].value * e.smArray[j].value;
				i++; j++; break;
			case '>': // advance to next term in column c
					  //cout << "3c: next term in col" << endl;
				j++;
			}; // end of switch
		} // of while (j <= B.Terms)
		while (smArray[i].row == r) // advance to next row
			i++;
		RowBegin = i; r = smArray[i].row;
	} //end of while (i < Terms)
	d.Rows = Rows; d.Cols = b.Cols; d.Terms = LastD + 1;
	return d;
} // of Multiply

void SparseMatrix::Output()
{
	cout << "\trow" << "\tcol" << "\tvalue" << endl;
	for (int i = 0; i < Terms; i++)
		cout << "\t" << smArray[i].row << "\t" << smArray[i].col << "\t" << smArray[i].value << endl;
}

//display matrix as a shape of a matrice.
void SparseMatrix::OutputToMatrice() const {
	int ** tempArr = new int*[Rows];
	for (int i = 0; i < Rows; i++) {
		tempArr[i] = new int[Cols];
	}

	//initial the tempArr
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			tempArr[i][j] = 0;
		}
	}
	//set values in tempArr
	for (int i = 0; i < this->Terms; i++) {
		tempArr[smArray[i].row][smArray[i].col] = smArray[i].value;
	}
	//print out
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << tempArr[i][j] << " ";
		}
		cout << endl;
	}
	//release heap memory
	for (int i = 0; i < Rows; i++) {
		delete[] tempArr[i];
	}
	delete[] tempArr;
	tempArr = nullptr;

}

//add a new Term to the SparseMatrix
void SparseMatrix::addElement(int row, int col, int value) {
	if (Terms > MaxTerms) throw runtime_error("terms > maxTerms");

	this->smArray[Terms].row = row;
	this->smArray[Terms].col = col;
	this->smArray[Terms++].value = value;

	if (row > Rows) Rows = row;
	if (col > Cols) Cols = col;
}

//This function performs the execution of adding two matrixs.
//The order of data stored in "smArray" is spacial. For example,
//row     col     value
//0       2       1
//0       3       2
//1       0       1
//1       3       3
//2       2       1
//the data is sorted by row first and then sorted by col in ascending order.
SparseMatrix SparseMatrix::Add(SparseMatrix b) const {
	if (this->Rows != b.Rows || this->Cols != b.Cols) 
		throw runtime_error("a.rows != b.rows or a.cols != b.cols");
	SparseMatrix result(Rows, Cols);

	int aIndex = 0, bIndex = 0;
	while (aIndex < Terms && bIndex < b.Terms) {
		int aRow = smArray[aIndex].row;
		int aCol = smArray[aIndex].col;
		int bRow = b.smArray[bIndex].row;
		int bCol = b.smArray[bIndex].col;
		int aValue = smArray[aIndex].value;
		int bValue = b.smArray[bIndex].value;

		if (aRow == bRow && aCol == bCol) {
			result.addElement(aRow, aCol, aValue+bValue);
			aIndex++;
			bIndex++;
		}
		else if ((aRow < bRow) || (aRow == bRow && aCol < bCol)) {
			result.addElement(aRow, aCol, aValue);
			aIndex++;
		}
		else if ((bRow < aRow)|| (bRow == aRow && bCol < aCol)) {
			result.addElement(bRow, bCol, bValue);
			bIndex++;
		}
	}
	for (; aIndex < Terms; aIndex++) {
		result.addElement(smArray[aIndex].row, smArray[aIndex].col, smArray[aIndex].value);
	}

	for (; bIndex < b.Terms; bIndex++) {
		result.addElement(b.smArray[bIndex].row, b.smArray[bIndex].col, b.smArray[bIndex].value);
	}

	return result;
}


SparseMatrix SparseMatrix::EmptyMatrix() {
	SparseMatrix *sm = new SparseMatrix;
	sm->Rows = sm->Cols = sm->Terms = 0;
	return *sm;
}