#include <stdio.h>

#define MAXN 1111

int main(int argc, char const *argv[]){
	for(int n, ans; ~scanf("%d", &n) && n; ){
		static int f[MAXN];
		ans = f[1] = 0;
		for(int i=0, j, x; i<n; ++i){
			for(scanf("%d", &x), j=1; j<=ans; ++j){
				if( x<=f[j] ){
					f[j] = x;
					break;
				}
			}
			if( j>ans ){
				f[++ans] = x;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}