#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(NULL));
	Matrix<int> randomWalk;	
	int imove[] = { -1,0,1,1,1,0,-1,-1 };
 	int jmove[] = { 1,1,1,0,-1,-1,-1,0 };
	// case 1 : n= 15, m = 15 ,start (9,9)
	int n_row = 15;
	int m_col = 15;
	int move_count = 0;
 	randomWalk(n_row, m_col);
	int random_n_row = 9;
	int random_m_col = 9;
	randomWalk.Start(random_n_row, random_m_col);
	while (move_count < 50000) {
		int random_move = rand() % 8;
		randomWalk.Move(imove[random_move], jmove[random_move]);
 		move_count++;
		if (randomWalk.FindZeroElement() == false)
			break;
	}
	randomWalk.Display();
	system("pause");
	// case 2 : n= 39, m = 19 ,start (0,0)
	n_row = 39;
	m_col = 19;
	move_count = 0;
	randomWalk(n_row, m_col);
	random_n_row = 0;//rand() % n_row;
	random_m_col = 0;//rand() % m_col;
	randomWalk.Start(random_n_row, random_m_col);
	while (move_count < 50000) {
		int random_move = rand() % 8;
		randomWalk.Move(imove[random_move], jmove[random_move]);
		move_count++;
		if (randomWalk.FindZeroElement() == false)
			break;
	}
	randomWalk.Display();
	system("pause");
	return 0;
}