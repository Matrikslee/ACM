#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int T; for(scanf("%d",&T);T;--T){
		double n; scanf("%lf", &n);
		double x = log10(n)*n;
		int ans = int(pow(10, x-(long long)x));
		printf("%d\n", ans);
	}
	return 0;
}