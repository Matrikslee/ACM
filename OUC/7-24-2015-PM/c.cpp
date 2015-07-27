#include <iostream>
#define MAXN 22
#define MAXW (1<<12)

using std::cin;
using std::cout;
using std::endl;

void getMap(char (*map)[MAXW], int raw, int col, int(*matrix)[MAXN])){
	for(int j=0,x; j<raw; ++j){
		for(int i=0,y; i<col; ++i){
			if(j==0 || j+1==raw || i==0 || i+1==col){
				map[i][j] = '*';
			} else {
				const char cc[5][5] = {"H O ","    ","  H ","    "};
				map[i][j] = cc[(j+3)%4][(i+3)%4];
				if(map[i][j]=='O'){

				}
			}
		}
	}
}

void print(char (*map)[MAXW], int raw, int col){
	for(int j=0; j<raw; ++j){
		for(int i=0; i<col; ++i){
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[]){
	for(int n; cin>>n && n!=0; ){
		int matrix[MAXN][MAXN],col,raw=1;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				cin >> matrix[i][j];
			}
		}
		// get raw and col number
		for(int i=0; i<=n; ++i,raw*=2); 
		col = --raw+4;
		// get map character && add '-' & '|'
		static char map[MAXW][MAXW];
		getMap(map, raw, col, matrix);
		// print map
		print(map,raw,col);
	}
	return 0;
}