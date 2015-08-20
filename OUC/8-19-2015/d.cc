#include <stdio.h>
#include <string.h>

int n, k;
bool map[500][500];
bool vis[500];
int tag[500];

bool dfs(int u){
	bool res = false;
	for ( int v = 0; v < n; ++ v ) {
		if( map[u][v] && !vis[v] ) {
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

int main(int argc, char const *argv[]){
	scanf("%d%d", &n, &k);
	for( int i = 0; i < k; ++ i ) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[--x][--y] = true;
	}
	int ans = 0;
	memset(tag, 0xff, sizeof(tag));
	for ( int u = 0; u < n; ++ u ) {
		memset(vis, 0x0, sizeof(vis));
		if ( dfs(u) ) {
			++ ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}