#include <stdio.h>
#include <queue>
#include <string.h>
#define MAXN 111

int main(int argc, char const *argv[]){
	for(int n,m; ~scanf("%d%d", &n, &m) && n*m!=0 ; ) {
		static int map[MAXN][MAXN];
		memset(map, 0x3f, sizeof(map));
		for(int i=0; i<m; ++i) {
			int x,y,z;
			scanf("%d%d%d", &x, &y, &z);
			if( map[x][y] > z ) {
				map[y][x] = map[x][y] = z;
			}
		}
		static int dis[MAXN];
		static bool vis[MAXN];
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0x0, sizeof(vis));
		std::queue<int> Q;
		vis[1] = true;
		dis[1] = 0;
		Q.push(1);
		while( !Q.empty() ) {
			int now = Q.front();
			vis[now] = false; Q.pop();
			for(int i=1; i<=n; ++i) {
				if ( dis[now]+map[now][i]<dis[i] ) {
					dis[i] = dis[now]+map[now][i];
					if( !vis[i] ) {
						vis[i] = true;
						Q.push(i);
					}
				}
			}
		}
		printf("%d\n", dis[n]);
	}
	return 0;
}