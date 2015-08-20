#include <stdio.h>
#include <string.h>

bool map[300][7*12];
bool vis[300];
int tag[7*12];

bool dfs(int u) {
	bool res = false;
	for( int v = 0; v < 7*12; ++ v ) {
		if ( !vis[v] && map[u][v] ) {
			vis[v] = true;
			if ( !~tag[v] || dfs(tag[v]) ) {
				tag[v] = u;
				res = true;
				break;
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {
	for ( int n; ~scanf("%d", &n); ) {
		memset(map,0x0,sizeof(map));
		for ( int u = 0; u < n; ++ u ) {
			int k; scanf("%d", &k);
			for ( int j = 0; j < k; ++j ) {
				int x, y;
				scanf("%d%d", &x, &y);
				int v = 12*--x+--y;
				map[u][v] = true;
			}
		}
		int ans = 0;
		memset(tag, 0xff, sizeof(tag));
		for ( int u = 0; u < n; ++ u ) {
			memset(vis, 0x0, sizeof(vis));
			if( dfs(u) ) {
				++ ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}