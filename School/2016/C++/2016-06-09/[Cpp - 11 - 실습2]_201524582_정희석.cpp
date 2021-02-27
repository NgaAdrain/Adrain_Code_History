#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>
//#include <cmath>
using namespace std;

class Player{
    public :
        virtual int getGuess()=0;
};

class HumanPlayer : public Player{
    public :
        int getGuess();
      };
      
class ComputerPlayer : public Player{
    public :
        int getGuess();
      };
      
bool checkForWin(int guess, int answer);
void play(Player &player1, Player &player2);

int main(){
    HumanPlayer H_P_1, H_P_2;
    ComputerPlayer C_P_1, C_P_2;
    cout << "The GUESSING GAME!!" << endl;
    cout << "(in range 1-to-100)" << endl;
    cout << "First game : Player vs Player" << endl;
    play(H_P_1, H_P_2);
    cout << endl;
    cout << "Second game : Player vs Computer" << endl;
    play(H_P_1, C_P_1);
    cout << endl;
    cout << "Last game : Computer vs Computer" << endl;
    play(C_P_1, C_P_2);
    cout << endl;
    cout << "Thank You For Playing!" << endl;
    system("pause");
    return 0;
}

int HumanPlayer::getGuess(){
    int input;     
    cin >> input;
    return input;                    
} 

int ComputerPlayer::getGuess(){
    int random=0,temp;
    Sleep(700);
    srand(time(NULL));
    temp = (rand()% RAND_MAX)+1;
    for(int x=0;x< temp; x++)
        random = (rand()%100) + 1;
    cout << "The computer guesses is " << random << endl ;
    return random;
}

bool checkForWin(int guess, int answer){
    if (guess == answer){
        cout << "You're right! You Win!" << endl;
        return true;
    }
    else if (guess > answer){
        cout << "Your guess is too high." << endl;
        return false;
    }
    else{
        cout << "Your guess is too low." << endl;
        return false;
    }
}

void play(Player &player1, Player &player2){
    int answer = 0, guess = 0;
    srand(time(0));
    answer = (rand()%100)+ 1;
    bool win = false;
    while (win == false){
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win == true) break;
        Sleep(300);
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        Sleep(400);
        }     
}
