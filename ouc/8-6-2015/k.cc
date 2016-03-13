#include <stdio.h>

#define MAXN 31111
#define MAXM 12

int main(int argc, char const *argv[]){
	static const double eps = 0.0000001;
	static const int v[MAXM] = {0,5,10,20,50,100,200,500,1000,2000,5000,10000};
	static long long f[MAXN][MAXM] = {0};
	for(int i=0; i<=MAXN; ++i){
		for(int j=0; j<MAXM; ++j){
			if(i==0) {
				f[i][j] = 1;
			} else if(j==0) {
				f[i][j] = 0;
			} else if(v[j]>i){
				f[i][j] = f[i][j-1];
			} else {
				f[i][j] = f[i-v[j]][j]+f[i][j-1];
			}
		}
	}
	for(double x; ~scanf("%lf", &x) && x>eps; printf("%6.2lf%17lld\n", x, f[int(x*100+.5)][MAXM-1]));
	return 0;
}