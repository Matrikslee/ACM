#include <iostream>
#include <cstring>
#define MAXN 22
#define MAXW 222

using std::cin;
using std::cout;
using std::endl;

void getMap(char map[][MAXW], int raw, int col,int matrix[][MAXN], int n){
	for(int j=0; j<raw; ++j){
		for(int i=0; i<col; ++i){
			if(j==0 || j+1==raw || i==0 || i+1==col){
				map[i][j] = '*';
			} else {
				const char cc[5][5] = {"H O ","    ","  H ","    "};
				map[i][j] = cc[(j+3)%4][(i+3)%4];
			}
		}
	}
	bool vis[MAXW][MAXW] = {false};
	for(int j=1,x=0; j<raw; j+=4,x++){
		for(int i=3,y=0; i<col; i+=4,y++){
			if(matrix[x][y]==1){
				map[i-1][j] = map[i+1][j] = '-';
				vis[i-2][j] = vis[i+2][j] = true;
			}
			if(matrix[x][y]==-1){
				map[i][j-1] = map[i][j+1] = '|';
				vis[i][j-2] = vis[i][j+2] = true;
			}
		}
	}
	for(int j=1,x=0; j<raw; j+=4,x++){
		for(int i=3,y=0; i<col; i+=4,y++){
			if(matrix[x][y]==0){
				if(j>2&&!vis[i][j-2]){
					map[i][j-1] = '|';
					vis[i][j-2] == true;
				} else if(j+2<raw&&!vis[i][j+2]){
					map[i][j+1] = '|';
					vis[i][j+2] = true;
				}
				if(!vis[i-2][j]){
					map[i-1][j] = '-';
					vis[i-2][j] = true;
				} else if(!vis[i+2][j]) {
					map[i+1][j] = '-';
					vis[i+2][j] = true;
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
	for(int n,cnt=1; cin>>n && n!=0; ++cnt){
		int matrix[MAXN][MAXN];
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				cin >> matrix[i][j];
			}
		}
		int raw = 4*n-1, col = 4*n+3;
		static char map[MAXW][MAXW];
		memset(map, ' ', sizeof(map));
		getMap(map, raw, col, matrix, n);
		cout << "Case " << cnt << ":" << endl << endl;
		print(map,raw,col);
		cout << endl;
	}
	return 0;
}