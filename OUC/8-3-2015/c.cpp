#include <stdio.h>
#include <string.h>

#define MAXN 111
#define MAXW 11111

int main(int argc, char const *argv[]){
	int T; for(scanf("%d", &T); T; --T){
		double W; int n;
		scanf("%lf%d", &W, &n);
		int v[MAXN] = {0};
		double w[MAXN] = {0};
		for(int i=0; i<n; ++i){
			scanf("%d%lf", &v[i], &w[i]);
		}
		static double f[MAXN][MAXW];
		for(int i=0; i<=n; ++i){

		}
	}
	return 0;
}