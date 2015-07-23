#include <cstdio>
#include <queue>
#define MAXN 44

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

bool can_go(char (*map)[MAXN], int n, int m, int x, int y){
	return (x>=0 && x<n && y>=0 && y<m && map[x][y]!='#')?true:false;
}

void go(char (*map)[MAXN], int n, int m, int sx, int sy, int tag){
	int d;
	for(int i=0; i<4; ++i){
		if(can_go(map,n,m,sx+dx[i],sy+dy[i])){
			d = i; break;
		}
	}
	int step=1, x=sx, y=sy, cnt=0;
	while(map[x][y]!='E'){
		if(can_go(map,n,m,x+dx[d],y+dy[d])){
			x += dx[d], y += dy[d], ++step;
			int td = (d+tag+4)%4;
			if(can_go(map,n,m,x+dx[td],y+dy[td])){
				d = td;
			}
		} else {
			d = (d-tag+4)%4;
		}
	}
	printf("%d ", step);
}

struct P{
	int x,y,d;
	P():x(0),y(0),d(0){}
	P(int xx, int yy, int dis):x(xx),y(yy),d(dis){}
};

void bfs(char(*map)[MAXN], int n, int m, int sx, int sy){
	int ans = 0;
	std::queue<P> q;
	int vis[MAXN][MAXN] = {false};
	for(;!q.empty();q.pop());
	q.push(P(sx,sy,1));
	vis[sx][sy] = true;
	while(!q.empty()){
		P tmp = q.front(); q.pop();
		int x = tmp.x, y = tmp.y;
		if(map[x][y] == 'E'){
			ans = tmp.d;
			break;
		}
		for(int i=0; i<4; ++i){
			int tx = x+dx[i], ty = y+dy[i];
			if(can_go(map,n,m,tx,ty) && !vis[tx][ty]){
				vis[tx][ty] = 1;
				q.push(P(tx,ty,tmp.d+1));
			}
		}
	}
	printf("%d ", ans);
}

int main(int argc, char const *argv[]){
	int T; for(scanf("%d", &T);T;--T){
		char map[MAXN][MAXN];
		int n,m,sx,sy; scanf("%d%d\n",&m,&n);
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				'S'==(map[i][j]=getchar()) && (sx=i,sy=j);
			}
			getchar();
		}
		go(map,n,m,sx,sy,-1);
		go(map,n,m,sx,sy,1);
		bfs(map,n,m,sx,sy);
		printf("\n");
	}
	return 0;
}