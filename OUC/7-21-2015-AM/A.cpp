#include <cstdio>
#define MAXN 33

const int dx[] = {-2, -2, -1, -1, 1,  1, 2,  2};
const int dy[] = {-1, 1,  -2, 2,  -2, 2, -1, 1};

bool dfs(int x,int y,int w, int h, int(*pre)[MAXN]){
	for(int i=0; i<8; ++i){
		
	}
}

int main(int argc, char const *argv[]){
	int T,n,m,pre[MAXN][MAXN];
	for(scanf("%d", &T); T; --T){
		scanf("%d%d",&n,&m);
		dfs(0,0,n,m,pre);
	}
	return 0;
}