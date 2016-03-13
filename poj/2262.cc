#include <cstdio>
#define MAXN 1111111

int main(int argc, char const *argv[])
{
	static int  prime[MAXN], top = 0;
	static bool isprime[MAXN] = {false};
	for(int i=2; i<MAXN; ++i){
		if(!isprime[i]){
			for(int j=2; i*j<MAXN; ++j){
				isprime[i*j] = true;
			}
			prime[top++] = i;
		}
	}
	for(int n; ~scanf("%d", &n) && n!=0; ){
		int a = 0, b = 0, ans = 0;
		for(int i=1; i<top; ++i){
			a = prime[i]; b = n-a;
			if(!isprime[b]){
				ans = 1;
				break;
			}
		}
		if(ans==1){
			printf("%d = %d + %d\n", n, a, b);
		} else {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	return 0;
}