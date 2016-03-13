#include <stdio.h>

int main(int argc, char const *argv[]){
	for(long long n; ~scanf("%lld", &n); ){
		long long ans = 1;
		for( long long p=2; p*p<=n; ++p){
			if(n%p==0){
				long long k=0,pk=1;
				while(n%p==0){
					++k, pk*=p, n/=p;
				}
				ans *= k*(pk-pk/p)+pk;
			}
		}
		n>1 && (ans *= 2*n-1);
		printf("%lld\n", ans);
	}
	return 0;
}