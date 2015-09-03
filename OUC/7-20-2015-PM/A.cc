#include <cstdio>
#include <cstring>
#define MAXN 111

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int dfs(int x, int y, int n, int k, int (*map)[MAXN], int (*dp)[MAXN]);
inline int max(int a, int b) { return a>b?a:b; }

int main(int argc, char const *argv[]){
	for(int n,k;~scanf("%d%d",&n,&k)&& n!=-1&&k!=-1;){
		static int map[MAXN][MAXN];
		static int dp[MAXN][MAXN];
		memset(map,0x0,sizeof(map));
		memset(dp,0x0,sizeof(dp));
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		printf("%d\n", dfs(0,0,n,k,map,dp));
	}
	return 0;
}

int dfs(int x, int y, int n, int k, int (*map)[MAXN], int (*dp)[MAXN]){
	if(!dp[x][y]){
		for(int s=1; s<=k; ++s){
			for(int i=0; i<4; ++i){
				int tx = x+dx[i]*s;
				int ty = y+dy[i]*s;
				if(tx>=0 && ty>=0 && tx<n && ty<n && map[tx][ty]>map[x][y]){
					int tmp = dfs(tx,ty,n,k,map,dp);
					dp[x][y] = dp[x][y]<tmp+map[x][y]?tmp+map[x][y]:dp[x][y];
				}
			}
		}
	}
	return max(dp[x][y],map[x][y]);
}