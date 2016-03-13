#include <cstdio>
#include <queue>
#define MAXN 111

struct dot{
	int x,y,color;
	dot():x(0),y(0),color(0){}
	dot(int xx, int yy, int c):x(xx),y(yy),color(c){}
};

int main(int argc, char const *argv[]){
	int n, m;
	static int map[MAXN][MAXN];
	static bool vis[MAXN][MAXN];
	//input
	scanf("%d%d\n", &n, &m);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			map[i][j]=getchar();
		}
		getchar();
	}
	//do work
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(map[i][j]=='.'){
				std::queue<dot> q;
				for(;!q.empty();q.pop());
				q.push(dot(i,j,0));
				map[i][j]='B';
				vis[i][j]=true;
				while(!q.empty()){
					dot tmp = q.front(); q.pop();
					static const int dx[]={1,0,-1,0};
					static const int dy[]={0,1,0,-1};
					for(int i=0; i<4; ++i){
						int x = tmp.x+dx[i], y = tmp.y+dy[i], c = !tmp.color;
						if(x>=0 && x<n && y>=0 && y<m && map[x][y]=='.'){
							vis[x][y] = true;
							map[x][y] = c?'W':'B';
							q.push(dot(x,y,c));
						}
					}
				}
			}
		}
	}
	//output
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			putchar(map[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
