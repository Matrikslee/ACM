#include <stdio.h>
#include <string.h>
#define MAXN 111

inline int max(int a, int b) { return a>b?a:b; }

int main(int argc, char const *argv[]){
	for(int m,n,cnt=0; ~scanf("%d%d", &m,&n) && m*n; ){
		int a[MAXN] = {0}, b[MAXN] = {0};
		for(int i=1; i<=m; ++i){ scanf("%d", a+i); }
		for(int i=1; i<=n; ++i){ scanf("%d", b+i); }
		static int f[MAXN][MAXN];
		memset(f,0x0,sizeof(f));
		for(int i=1; i<=m; ++i){
			for(int j=1; j<=n; ++j){
				if(a[i]==b[j]){
					f[i][j] = f[i-1][j-1]+1;
				} else {
					f[i][j] = max(f[i-1][j], f[i][j-1]);
				}
			}
		}
		printf("Twin Towers #%d\n", ++cnt);
		printf("Number of Tiles : %d\n\n", f[m][n]);
	}
	return 0;
}