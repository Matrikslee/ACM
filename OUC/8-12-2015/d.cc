#include <stdio.h>
#include <string.h>

const int MAXN = 10000000;

int find(int* f, int x) {
	return x==f[x]?x:f[x]=find(f,f[x]);
}

inline int max(int a, int b) { return a>b?a:b; }

int main(int argc, char const *argv[]) {
	for(int n; ~scanf("%d", &n); ){
		static int f[MAXN+10], a[MAXN+10], b[MAXN+10], count[MAXN+10];
		int len = 0, ans = 0;
		for ( int i=0; i<n; ++i ) {
			scanf("%d%d", a+i, b+i);
			len = max(len, max(a[i],b[i]));
		}
		for(int i=0; i<=len; f[i]=i, ++i);
		for(int i=0; i<n; ++i) {
			f[find(f,a[i])] = find(f,b[i]);
		}
		memset(count, 0x0, sizeof(count));
		for(int i=0; i<=len; ++count[find(f,i++)]);
		for(int i=0; i<=len; ans=max(ans,count[i++]));
		printf("%d\n", ans);
	}
	return 0;
}