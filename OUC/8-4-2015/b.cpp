#include <stdio.h>

#define MAXN 100000

typedef long long LINT;

inline LINT max(LINT a, LINT b) { return a>b?a:b; }

int main(int argc, char const *argv[]){
	for(int n; ~scanf("%d", &n) && n!=0; ){
		static int h[MAXN];
		for(int i=0; i<n; ++i){
			scanf("%d", h+i);
		}
		static int L[MAXN], R[MAXN];
		static int st[MAXN];
		for(int i=0,t=0; i<n; ++i){
			for(;t>0 && h[st[t-1]]>=h[i]; --t);
			L[i] = t?st[t-1]+1:0;
			st[t++] = i;
		}
		for(int i=n-1,t=0; i>=0; --i){
			for(; t>0 && h[st[t-1]]>=h[i]; --t);
			R[i] = t?st[t-1]:n;
			st[t++] = i;
		}
		long long ans = 0;
		for(int i=0; i<n; ++i){
			ans = max(ans, (LINT)h[i] * (R[i]-L[i]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}