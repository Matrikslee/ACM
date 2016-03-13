#include <stdio.h>

int main(int argc, char const *argv[]){
	for(int n,p,cas=1; ~scanf("%d%d", &p, &n) && n*p!=0; ++cas){
		int ans = 1;
		for(; n>0; n/=p){
			ans *= n%p+1;
			ans %= 10000;
		}
		printf("Case %d: %04d\n", cas, ans);
	}
	return 0;
}