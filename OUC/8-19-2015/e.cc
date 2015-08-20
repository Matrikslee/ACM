#include <stdio.h>
#include <string.h>

#define MAXN 20
#define MAXM 200

struct node{
	int id, start, end;
} task[MAXM];

bool newMap[MAXM][MAXM];
bool vis[MAXM];
int tag[MAXM];
int map[MAXN][MAXN];
const int INF = 0x3f3f3f3f;

bool dfs( int u , const int& k );

int main(int argc, char const *argv[]){
	for ( int n, k; ~scanf("%d%d", &n, &k) && n!=0; ) {
		for ( int i = 0; i < n; ++ i ) {
			for ( int j = 0; j < n; ++ j ) {
				scanf("%d", &map[i][j]);
				if ( map[i][j]==-1 ) {
					map[i][j] = INF;
				}
			}
		}
		for ( int i = 0, t; i < k; ++i ) {
			scanf("%d%d%d", &task[i].id, &task[i].start, &t);
			task[i].end = task[i].start+t;
		}
		for ( int o = 0; o < n; ++ o ) {
			for ( int u = 0; u < n; ++ u ) {
				 for ( int v = 0; v < n; ++ v ) {
				 	if( map[u][v] > map[u][o]+map[o][v] ) {
				 		map[u][v] = map[u][o]+map[o][v];
				 	}
				 }
			}
		}
		memset(newMap, 0x0, sizeof(newMap));
		for ( int u = 0; u < k; ++ u ) {
			for ( int v = 0; v < k; ++ v ) {
				if( task[v].start >= task[u].end+map[task[u].id-1][task[v].id-1] ) {
					newMap[u][v] = true;
				}
			}
		}
		int ans = k;
		memset(tag, 0xff, sizeof(tag));
		for ( int u = 0; u < k; ++ u ) {
			memset(vis, 0x0, sizeof(vis));
			if ( dfs( u , k ) ) {
				-- ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

bool dfs( int u , const int& k ) {
	bool res = false;
	for ( int v = 0; v < k; ++ v ) {
		if ( newMap[u][v] && !vis[v] ) {
			vis[v] = true;
			if ( tag[v]==-1 || dfs( tag[v], k ) ) {
				tag[v] = u;
				res = true;
				break;
			}
		}
	}
	return res;
}