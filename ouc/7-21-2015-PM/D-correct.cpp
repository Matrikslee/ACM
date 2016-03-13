#include <cstdio>
#define MAXN 111

int main(int argc, char const *argv[]){
	int n, m;
	static int map[MAXN][MAXN];
	scanf("%d%d\n", &n, &m);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			map[i][j]=getchar();
		}
		getchar();
	}
	//do work
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(map[i][j]=='.'){
				if((i+j)&1){
					map[i][j] = 'B';
				} else {
					map[i][j] = 'W';
				}
			}
		}
	}
	//output
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			putchar(map[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
