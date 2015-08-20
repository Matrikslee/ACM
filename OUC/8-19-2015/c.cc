#include <stdio.h>
#include <string.h>
#include <cmath>

#define MAXN 100

int tag[MAXN];
bool vis[MAXN];
bool map[MAXN][MAXN];

bool dfs( int u, const int& m );

int main(int argc, char const *argv[]){
	for( int n,m,s,v; ~scanf("%d%d%d%d", &n, &m, &s, &v); ) {
		double gx[MAXN], gy[MAXN];
		for ( int i = 0; i < n; ++ i ) {
			scanf("%lf%lf", &gx[i], &gy[i]);
		}
		double hx[MAXN], hy[MAXN];
		for ( int i = 0; i < m; ++ i ) {
			scanf("%lf%lf", &hx[i], &hy[i]);
		}
		memset(map, 0x0, sizeof(map));
		for ( int i = 0; i < n; ++ i ) {
			for ( int j = 0; j < m; ++ j ) {
				double dx = gx[i]-hx[j];
				double dy = gy[i]-hy[j];
				if ( s*v-sqrt(dx*dx+dy*dy) >= 0 ) {
					map[i][j] = true;
				}
			}
		}
		int ans = n;
		memset(tag, 0xff, sizeof(tag));
		for ( int u = 0; u < n; ++ u ) {
			memset(vis, 0x0, sizeof(vis));
			if( dfs( u, m ) ) {
				-- ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

bool dfs( int u, const int& m ) {
	bool res = false;
	for ( int v = 0; v < m; ++ v ) {
		if ( map[u][v] && !vis[v] ) {
			vis[v] = true;
			if ( tag[v]==-1 || dfs( tag[v], m ) ) {
				tag[v] = u;
				res = true;
				break;
			}
		}
	}
	return res;
}