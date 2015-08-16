#include <stdio.h>
#include <string.h>
#define MAXN 100100

inline int max(int a, int b) { return a>b?a:b; }

inline int max(int a, int b, int c){ return max(max(a,b),c); }

int main(int argc, char const *argv[]){
	for( int n; ~scanf("%d", &n) && n!=0; ){
		static int f[MAXN][13];
		memset(f, 0x0, sizeof(f));
		int maxTime = 0;
		for( int i=0, x, t; i<n; ++i ) {
			scanf("%d%d", &x, &t);
			maxTime = max(maxTime, t);
			++f[t][x+1];
		}
		for( int i=maxTime-1; i>0; --i ){
			for( int j=1; j<12; ++j) {
				f[i][j] += max(f[i+1][j-1], f[i+1][j], f[i+1][j+1]);
			}
		}
		printf("%d\n", max(f[1][5], f[1][6], f[1][7]));
	}
	return 0;
}