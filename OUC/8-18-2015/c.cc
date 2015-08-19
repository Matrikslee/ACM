#include <stdio.h>
#include <string.h>
#include <queue>

#define MAXN 1000

int main(int argc, char const *argv[]){
	for(int n,m; ~scanf("%d%d", &n, &m) && n*m!=0; ) {
		static int map[MAXN][MAXN][2];
		memset(map, 0x3f, sizeof(map));
		for( int i=0; i<m; ++i ) {
			int x,y,d,p;
			scanf("%d%d%d%d", &x, &y, &d, &p);
			if(map[x][y][0]>d || map[x][y][0]==d && map[x][y][2]>p){
				map[x][y][0] = map[y][x][0] = d;
				map[x][y][1] = map[y][x][1] = p;
			}
		}
		int s,t;
		scanf("%d%d", &s, &t);
		static int dis[MAXN];
		static int val[MAXN];
		static bool vis[MAXN];
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0x0, sizeof(vis));
		memset(val, 0x0, sizeof(val));
		std::queue<int> Q;
		vis[s] = true;
		dis[s] = 0;
		Q.push(s);
		while( !Q.empty() ) {
			int now = Q.front();
			vis[now] = false; Q.pop();
			for(int i=1; i<=n; ++i) {
				if ( dis[now]+map[now][i][0]<dis[i] ||
				dis[now]+map[now][i][0]==dis[i] && val[now]+map[now][i][1]<val[i] ) {
					dis[i] = dis[now]+map[now][i][0];
					val[i] = val[now]+map[now][i][1];
					if( !vis[i] ) {
						vis[i] = true;
						Q.push(i);
					}
				}
			}
		}
		printf("%d %d\n", dis[t], val[t]);
	}
	return 0;
}