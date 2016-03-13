#include <stdio.h>

inline int max(int a, int b) { return a>b?a:b; }

int lcs(int* a, int* b, int len){
	int f[22][22] = {0};
	for(int i=1; i<=len; ++i){
		for(int j=1; j<=len; ++j){
			if(a[i]==b[j]){
				f[i][j] = f[i-1][j-1]+1;
			} else {
				f[i][j] = max(f[i][j-1],f[i-1][j]);
			}
		}
	}
	return f[len][len];
}

int main(int argc, char const *argv[]){
	int n, s[22] = {0}; scanf("%d", &n);
	for(int x,i=0; i<n && ~scanf("%d", &x); s[x]=++i);
	// for(int i=1; i<=n; ++i){ printf("%d ", s[i]);} printf("\n");
	while(true) {
		int ss[22] = {0}, l=0;
		for(int x; l<n && ~scanf("%d",&x); ss[x]=++l);
		// for(int i=1; i<=l; ++i){ printf("%d ", ss[i]);} printf("\n");
		if(l<n) { break; }
		int ans = lcs(s,ss,n);
		printf("%d\n", ans);
	}
	return 0;
}