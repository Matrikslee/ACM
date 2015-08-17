#include <stdio.h>
#include <queue>
#include <string.h>
#include <functional>

int main(int argc, char const *argv[]){
	for(int n,m; ~scanf("%d%d", &n, &m); ){
		static int r[505];
		static bool map[505][505];
		memset(r, 0x0, sizeof(r));
		memset(map, 0x0, sizeof(map));
		for(int i=0,x,y; i<m; ++i){
			scanf("%d%d", &x, &y);
			if( !map[x][y] ) {
				map[x][y]=true;
				++r[y];
			}
		}
		std::priority_queue<int,std::vector<int>, std::greater<int> > Q;
		for( int i=1; i<=n; ++i ) {
			if( r[i] ==0 ) {
				Q.push(i);
			}
		}
		int ansN = 0;
		static int ans[555];
		memset(ans, 0x0, sizeof(ans));
		for( ansN=0; !Q.empty(); ) {
			int u = ans[ansN++] = Q.top();
			Q.pop();
			for(int v=1; v<=n; ++v){
				if( map[u][v] ) {
					--r[v];
					if( r[v] == 0 ){
						Q.push(v);
					}
				}
			}
		}
		for(int i=0; i<ansN; ++i){
			printf("%d%c", ans[i]," \n"[i+1==ansN]);
		}
	}
	return 0;
}