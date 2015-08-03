#include <stdio.h>
#include <string.h>

#define MAXN 22

int main(int argc, char const *argv[]){
	int T; for(scanf("%d", &T); T; --T){
		int n,m; scanf("%d%d", &m, &n);
		int f[MAXN][MAXN] = {0};
		for(int i=0; i<=n; ++i) { f[i][0] = 1; }
		for(int i=0; i<=m; ++i) { f[1][i] = 1; }
		for(int i=2; i<=n; ++i) {
			for(int j=1; j<=m; ++j){
				if( i>j ){
					f[i][j] = f[j][j];
				} else {
					f[i][j] += f[i-1][j] + (j>=i?f[i][j-i]:0);
				}
			}
		}
		printf("%d\n", f[n][m]);
	}
	return 0;
}