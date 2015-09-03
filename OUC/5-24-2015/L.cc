#include <cstdio>
#define MAXN 1111111

int main(int argc, char const *argv[])
{
	static long long o[MAXN] = {0};
	static bool isprime[MAXN] = {false};
	for(int i=2; i<MAXN; ++i){
		if(!isprime[i]){
			o[i]=i-1;
			for(int j=2; i*j<MAXN; ++j){
				isprime[i*j] = true;
				if(j%i!=0) {
					o[i*j] = o[i]*o[j];
				} else {
					o[i*j] = i*o[j];
				}
			}
		}
	}
	for(int i=0; i<MAXN; ++i){
		o[i] += o[i-1];
	}
	for(int n; ~scanf("%d", &n) && n!=0; printf("%I64d\n", o[n]));
	return 0;
}
