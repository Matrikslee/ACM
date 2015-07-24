#include <cstdio>
#include <cstring>
#define MAXN 33

const int dx[] = {-2, -2, -1, -1, 1,  1, 2,  2};
const int dy[] = {-1, 1,  -2, 2,  -2, 2, -1, 1};

int T,n,m,sx[MAXN],sy[MAXN];
bool vis[MAXN][MAXN]={true};

bool dfs(int step, int x,int y,int w, int h){
	sx[step] = x; sy[step] = y;
	vis[x][y] = true;
	bool res;
	if(step==n*m){
		res = true;
	} else {
		res = false;
		for(int i=0; i<8; ++i){
			int tx = x+dx[i], ty = y+dy[i];
			if(tx>=0 && tx<w && ty>=0 && ty<h){
				if(!vis[tx][ty]){
					res = dfs(step+1, tx,ty,w,h);
					if(res) {
						break;
					}
				}
			} 
		}
	}
	vis[x][y] = false;
	return res;
}

int main(int argc, char const *argv[]){
	scanf("%d", &T);
	for(int t=0; t<T; ++t){
		scanf("%d%d",&n,&m);
		memset(vis,0x0,sizeof(vis));
		printf("Scenario #%d:\n", t+1);
		bool is_found = false;
		vis[0][0] = true;
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				if(dfs(1,i,j,m,n)){
					is_found = true;
					break;
				}
			}
			if(is_found){
				break;
			}
		}
		if(is_found){
			for(int i=1; i<=n*m; ++i){
				printf("%c%c", 'A'+sx[i],'1'+sy[i]);
			}
		} else {
			printf("impossible");
		}
		printf("\n\n");
	}
	return 0;
}