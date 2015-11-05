#include <cstdio>
#define max(a,b) ({int _=(a), __=(b); _>__?_:__; })
#define min(a,b) ({int _=(a), __=(b); _<__?_:__; })
#define MAXN 111

int main(int argc, char const *argv[])
{
	int n, a[MAXN][MAXN];
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int g[MAXN][MAXN][MAXN]={0};
	for(int k=0; k<n; ++k){
		for(int i=0; i<n; ++i){
			g[k][i][i] = a[i][k];
			for(int j=i+1; j<n; ++j){
				g[k][i][j]=g[k][i][j-1]+a[j][k];
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=k; j<n; ++j){
			int s[MAXN]={0};
			int b[MAXN]={0};
			int d[MAXN]={0};
			int c[MAXN]={0};
		}
	}
	return 0;
}