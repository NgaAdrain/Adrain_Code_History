#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Player{
		public :
			Player();
			Player(string& i_name, string& i_u_Number);
			void nextSalary(ofstream &output);
			string get_name();
			string get_u_Number();
		private :
			string name;
			string u_Number; 
	};	
	
class Pitcher : public Player
	{
		public :
            Pitcher();
			Pitcher(string& i_name, string& i_u_Number, 
			int t_s, int i_win, int i_lose, int i_hold, 
            int i_saves, double i_ERA);
            void Calculate();
            void nextSalary(ofstream &output);
		private :
            int t_salary;
            int win; 
            int lose; 
            int hold; 
            int saves; 
            double ERA;
            int n_salary;		
	};	
    	
class Batter : public Player{
		public :
			Batter();
			Batter(string& i_name, string& i_u_Number, 
			int t_s, int t_b, int i_hits,
            int i_b_o_b, int i_RBI);
            void Calculate();
            void nextSalary(ofstream &output);
		private :
            int t_salary;
            int t_b_chance;
            int hits;
            int b_o_b;
            int RBI;
            int n_salary;             
};	

int main() {
	ifstream player_Info("BBPlayers.txt");
	ofstream output("NSPlayers.txt");
	string temp,temp_name,temp_num;
	int temp_ts,temp_w_or_tb,temp_l_or_hi,temp_h_or_bo,temp_s_or_RBI;
	double temp_ERA;
	int count_1=0,count_2=0;
    vector<Pitcher> list_1;
    vector<Batter> list_2;
    while(getline(player_Info, temp)){                           
    if(temp == "P"){
        getline(player_Info, temp_name);
        getline(player_Info, temp_num);
        getline(player_Info, temp);
        temp_ts = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_w_or_tb = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_l_or_hi = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_h_or_bo = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_s_or_RBI = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_ERA = atof(temp.c_str());
        Pitcher Ptemp(temp_name,temp_num,temp_ts,temp_w_or_tb,temp_l_or_hi,
        temp_h_or_bo,temp_s_or_RBI,temp_ERA);
        list_1.push_back(Ptemp);
        list_1[count_1].Calculate();
        list_1[count_1].nextSalary(output);
        count_1++;
        }
    else if(temp == "B"){
        getline(player_Info, temp_name);
        getline(player_Info, temp_num);
        getline(player_Info, temp);
        temp_ts = atoi(temp.c_str());  
        getline(player_Info, temp);
        temp_w_or_tb = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_l_or_hi = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_h_or_bo = atoi(temp.c_str());
        getline(player_Info, temp);
        temp_s_or_RBI = atoi(temp.c_str());
        Batter Btemp(temp_name,temp_num,temp_ts,temp_w_or_tb,temp_l_or_hi,
        temp_h_or_bo,temp_s_or_RBI); 
        list_2.push_back(Btemp);
        list_2[count_2].Calculate();
        list_2[count_2].nextSalary(output);
        count_2++;
        }
    else
        continue;                           
    }
    player_Info.close();
	output.close();
	system("pause");
	return 0;
}

Player::Player(string& i_name, string& i_u_Number){
    name = i_name;
    u_Number = i_u_Number;
	}
string Player::get_name(){
    return name;
}
string Player::get_u_Number(){
       return u_Number;
}
void Player::nextSalary(ofstream &output){
    cout << "Now Computing : " <<endl;
    cout << "The next year salary ";
    cout << "is computed in a different ";
    cout << "way depending on the player's position..." << endl;
	}

Pitcher::Pitcher(string& i_name, string& i_u_Number, 
			int t_s, int i_win, int i_lose, int i_hold, 
            int i_saves, double i_ERA) : Player(i_name,i_u_Number){
     t_salary = t_s;
     win = i_win;
     lose = i_lose;
     hold = i_hold;
     saves = i_saves;
     ERA = i_ERA;             
}
void Pitcher::Calculate(){
     ERA = 0.5*t_salary + 1500*win + 100*hold + 500*saves + 10000*(1/ERA);
     n_salary = (int) ERA;
     }
void Pitcher::nextSalary(ofstream &output){
     output << "Pitcher : " << get_u_Number() << " " << get_name() << endl;
     output << "This year salary : " << t_salary << endl;
     output << "Next year salary : " << n_salary << endl;
     output << endl;
     }

Batter::Batter(string& i_name, string& i_u_Number, 
			int t_s, int t_b, int i_hits,
            int i_b_o_b, int i_RBI) : Player(i_name,i_u_Number){
     t_salary = t_s;
     t_b_chance = t_b ;
     hits = i_hits;
     b_o_b = i_b_o_b;
     RBI = i_RBI;             
}
void Batter::Calculate(){
     double batAvg = (double) hits / (t_b_chance - b_o_b);
     n_salary = 0.5*t_salary + 200*RBI + 5000*batAvg;
     }
void Batter::nextSalary(ofstream &output){
     output << "Batter : " << get_u_Number() << " " << get_name() << endl;
     output << "This year salary : " << t_salary << endl;
     output << "Next year salary : " << n_salary << endl;
     output << endl;
     }
