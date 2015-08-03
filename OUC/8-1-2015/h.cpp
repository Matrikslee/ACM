#include <stdio.h>
#include <string.h>

#define MAXN 222

bool match(bool map[][MAXN], int i, const int m, bool vis[], int prev[]){
	bool res = false;
	for(int j=1; j<=m; ++j){
		if(map[i][j] && !vis[j]) {
			vis[j] = true;
			if(prev[j]==0 || match(map, prev[j], m, vis, prev)){
				prev[j] = i;
				res = true;
				break;
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	static bool map[MAXN][MAXN];
	for(int m,n; ~scanf("%d%d", &n, &m); ){
		memset(map, 0x0, sizeof(map));
		for(int i=1; i<=n; ++i){
			int k; scanf("%d", &k);
			for(int j=0; j<k; ++j){
				int x; scanf("%d", &x);
				map[i][x] = true;
			}
		}
		int ans = 0;
		int prev[MAXN] = {0};
		for(int i=1; i<=n; ++i){
			bool vis[MAXN] = {false};
			if( match(map, i, m, vis, prev) ){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}