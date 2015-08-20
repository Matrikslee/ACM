#include <stdio.h>
#include <string.h>

int cnt;
int tag[32*32];
bool vis[32*32];
bool map[32][32];
int number[32][32];
bool newMap[32*32][32*32];

bool dfs(int u) {
	bool res = false;
	for(int v=1; v<=cnt; ++v) {
		if( newMap[u][v] && !vis[v] ) {
			vis[v] = true;
			if( tag[v]==0 || dfs(tag[v]) ) {
				tag[v] = u;
				res = true;
				break;
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	int m,n,k;
	scanf("%d%d%d", &m, &n, &k);
	for(int i=0,x,y; i<k; ++i){
		scanf("%d%d", &x, &y);
		map[--x][--y] = true;
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if( !map[i][j] ){
				number[i][j] = ++cnt;
			}
		}
	}
	const int dx[] = {-1, 0, 0, 1};
	const int dy[] = {0, -1, 1, 0};
	for( int x = 0; x < n; ++ x ) {
		for(int y = 0; y < m; ++ y ) {
			if( !map[x][y] ){
				int u = number[x][y];
				for( int k = 0; k < 4; ++ k ) {
					int tx = x+dx[k], ty = y+dy[k];
					if ( tx>=0 && tx<n && ty>=0 && ty<m && !map[tx][ty] ) {
						int v = number[tx][ty];
						newMap[u][v] = true;
					}
				}
			}
		}
	}
	int res = 0;
	for(int u=1; u<=cnt; ++u) {
		memset(vis, 0x0, sizeof(vis));
		if ( dfs(u) ) {
			++ res;
		}
	}
	if( res==cnt ) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}