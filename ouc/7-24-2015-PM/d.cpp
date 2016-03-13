#include <iostream>
#include <string>

#define MAXH 222
#define MAXLEN 2222

typedef unsigned int uint;

using std::cin;
using std::cout;
using std::endl;
using std::string;

const char chr[10][6][4] = {
	{" - ","| |","   ","| |"," - "},
	{"   ","  |","   ","  |","   "},
	{" - ","  |"," - ","|  "," - "},
	{" - ","  |"," - ","  |"," - "},
	{"   ","| |"," - ","  |","   "},
	{" - ","|  "," - ","  |"," - "},
	{" - ","|  "," - ","| |"," - "},
	{" - ","  |","   ","  |","   "},
	{" - ","| |"," - ","| |"," - "},
	{" - ","| |"," - ","  |"," - "},
};

void print(char (*map)[MAXLEN], int pos, int size, int value){
	const char (*cc)[4] = chr[value];
	for(int i=0; i<5; ++i){
		for(int j=0; j<3; ++j){
			int x = i%2+(i/2)*(size+1);
			int y = j%2+(j/2)*(size+1) + pos;
			if(i%2==0){
				if(j%2==0){
					map[x][y] = cc[i][j];
				} else {
					for(int k=0; k<size; ++k){
						map[x][y+k] = cc[i][j];
					}
				}
			} else {
				for(int k=0; k<size; ++k){
					if(j%2==0){
						map[x+k][y] = cc[i][j];
					} else {
						for(int l=0; l<size; ++l){
							map[x+k][y+l] = cc[i][j];
						}
					}
				}
			}
		}
	}
}

void display(char (*map)[MAXLEN], int width, int height){
	for(int j=0; j<height; ++j){
		for(int i=0; i<width; ++i){
			cout << map[j][i];
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[]){
	int n; string s; bool isFirst = true;
	while(cin>>n>>s && n!=0){
		int ss[20]={0}, len = 0;
		if(!isFirst) { cout << endl; }
		for(; s[len]!='\0'; ss[len] = s[len]-'0',++len);
		static char map[MAXH][MAXLEN];
		for(int j=0; j<2*n+3; ++j){
			for(int i=0; i<len*(n+3); ++i){
				map[j][i] = ' ';
			}
		}
		for(int i=0; i<len; ++i){
			print(map, i*(n+3), n, ss[i]);
		}
		display(map,len*(n+3)-1,2*n+3);
		isFirst=false;
	}
	return 0;
}