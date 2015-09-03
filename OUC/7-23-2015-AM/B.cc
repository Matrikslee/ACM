#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string playerName[4] = {"South player:","West player:","North player:","East player:"};

class Player{
	bool card[4][13];
public:
	Player(){ memset(card, 0x0, sizeof(card)); } 
	void push(int color, int number){ card[color][number]=true; }
	void print(){
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
		for(int i=0; i<4; ++i){
			for(int j=0; j<13; ++j){
				if(card[i][j]){
					cout << "|" << "23456789TJQKA"[j] << " " << "23456789TJQKA"[j];
				}
			}
		}
		cout << "|" << endl;
		for(int i=0; i<4; ++i){
			for(int j=0; j<13; ++j){
				if(card[i][j]) {
					cout << "| " << "CDSH"[i] << " ";
				}
			}
		}
		cout << "|" << endl;
		for(int i=0; i<4; ++i){
			for(int j=0; j<13; ++j){
				if(card[i][j]){
					cout << "|" << "23456789TJQKA"[j] << " " << "23456789TJQKA"[j];
				}
			}
		}
		cout << "|" << endl;
		cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
	};
};

int main(int argc, char const *argv[]){
	while(true){
		int turn=0;
		string c,s,t;
		cin >> c;
		bool isEnd = false;
		switch(c[0]){
			case 'E' : ++turn;
			case 'N' : ++turn;
			case 'W' : ++turn;
			case 'S' : break;
			default : isEnd = true;
		}
		if(isEnd){ break; }
		Player player[4];
		cin >> s >> t; s+=t;
		for(int i=0; i<52; ++i){
			int color = 0, number = 0;
			switch(s[2*i]){
				case 'H' : ++color;
				case 'S' : ++color;
				case 'D' : ++color;
				case 'C' : default: break;
			}
			switch(s[2*i+1]){
				case 'A' : ++number; case 'K' : ++number; case 'Q' : ++number;
				case 'J' : ++number; case 'T' : ++number; case '9' : ++number;
				case '8' : ++number; case '7' : ++number; case '6' : ++number; 
				case '5' : ++number; case '4' : ++number; case '3' : ++number;
				case '2' : default: break;
			}
			player[turn=(turn+1)%4].push(color,number);
		}
		// Sort card && Print card style
		for(int i=0; i<4; ++i){
			cout << playerName[i] << endl;
			player[i].print();
		}
		cout << endl;
	}
	return 0;
}