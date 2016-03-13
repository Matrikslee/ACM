#include <cstdio>
#define MAXN 66

int main(int argc, char const *argv[])
{
	int t;
	for(scanf("%d", &t); t--;){
		int k; 
		long long n;
		char sign[MAXN];
		scanf("%d\n", &k);
		for(int i=0; i<k; ++i){
			sign[k-i-1]=getchar();
		}
		scanf("%lld", &n);
		bool bit[MAXN] = {false};
		for(int i=0; i<k; ++i){
			if(n&1) { 
				bit[i] = true;
				if(sign[i]=='p'){
					n>>=1;
				} else {
					n=(n>>1)+1;
				}
			} else {
				bit[i] = false;
				n>>=1;
			}
		}
		if(n!=0) { 
			printf("Impossible\n"); 
			continue;
		}
		for(int i=k; i>0; --i){
			if(bit[i-1]){
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}

	return 0;
}