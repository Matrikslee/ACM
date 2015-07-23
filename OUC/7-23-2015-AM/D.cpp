#include <stdio.h>

typedef long long int64;

inline int64 abss(int64 a){ return a<0?-a:a; }

int main(int argc, char const *argv[]){
	int n, idx = 0;
	scanf("%d", &n);
	int64 a, b, ans=-1;
	for(int i=0; i<n; ++i){
		scanf("%lld", &a);
		int64 tmp = abss(a-b);
		if( i>0 && tmp>ans ){
			ans = tmp;
			idx = i;
			// printf("%lld %i\n", ans, idx);
		}
		b = a;
	}
	printf("%d %d\n", idx, idx+1);
	return 0;
}