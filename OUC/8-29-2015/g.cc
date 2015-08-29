#include <stdio.h>

int main(int argc, char const *argv[]){
	const int MAXN = 155;
	for (int n, cnt = 1; ~scanf("%d", &n) && n!=0; ++cnt) {
		bool f[MAXN][MAXN] = {false};
		for ( int i = 1; i <= n; ++ i ) {
			for ( int j = n-i+1; j < n+i; ++ j ) {
				int x;
				scanf("%1d", &x);
				f[i][j] = (x==1);
			}
		}
		printf("Puzzle %d\n", cnt);
		bool ans = true;
		for ( int i = 2; i <= n; ++ i ) {
			int cnt = 0 ;
			for ( int j = n-i+2; j < n+i; ++ j ) {
				if ( f[i][j] != f[i][j-1] ) {
					++cnt;
				}
			}
			if ( cnt > 1 ) {
				ans = false;
				break;
			}
		}
		if ( ans ) {
			printf("Parts can be separated\n");
			continue;
		}
		for ( int i = 0; i < n-1; ++ i ) {
			int x = i+1, y = n-i, cnt = 0;
			for ( int j = 0; j < 2*(n-i)-1; ++j ) {
				int tx = x, ty = y;
				++tx;
				if ( f[tx][ty] != f[x][y] ) {
					++cnt;
				}
				x = tx;
				++ty;
				if ( f[tx][ty] != f[x][y] ) {
					++cnt;
				}
				y = ty;
			}
			if ( cnt > 1 ) {
				ans = false;
				break;
			}
		}		
		if ( ans ) {
			printf("Parts can be separated\n");
			continue;
		}
		printf("Parts cannot be separated\n");
	}
	return 0;
}