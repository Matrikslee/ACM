#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 111

const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

struct p{
	int x,y,d,dis;
	p(int xx,int yy,int dd,int ddis):x(xx),y(yy),d(dd),dis(ddis){}
	p():x(0),y(0),d(0),dis(0){}
};

bool is_final(int cx, int cy, int h, int w){
	return cx==0||cy==0||cx+1==h||cy+1==w?true:false;
}

bool is_ok(int cx, int cy, int d,int h, int w, char (*map)[MAXN]){
	return cx>=0&&cy>=0&&cx<h&&cy<w&&map[cx][cy]=='.'?true:false;
}

int main(int argc, char const *argv[]){
	int n;
	for(scanf("%d", &n); n; --n){
		int h,w,sx,sy;
		static char map[MAXN][MAXN];
		memset(map,0x0,sizeof(map));
		scanf("%d%d\n",&h,&w);
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				scanf("%c", &map[i][j]);
				map[i][j]=='@'?sx=i, sy=j:0;
			}
			scanf("\n");
		}
		if(sx==0||sy==0||sx==h-1||sy==w-1){
			printf("0\n");
			continue;
		}
		static bool v[MAXN][MAXN][4];
		memset(v, 0x0, sizeof(v));
		std::queue<p> q;
		for(;!q.empty();q.pop());
		for(int i=0; i<4; ++i){
			q.push(p(sx,sy,i,0));
			v[sx][sy][i] = true;
		}
		int ans = -1;
		while(!q.empty()){
			p u = q.front();
			q.pop();
			bool is_turned = false;
			int tx = u.x+dx[(u.d+1)%4];
			int ty = u.y+dy[(u.d+1)%4];
			if(is_ok(tx,ty,(u.d+1)%4,h,w,map)){
				if(is_final(tx,ty,h,w)){
					ans = u.dis+1;
					break;
				}
				is_turned = true;
				if(!v[tx][ty][(u.d+1)%4]){
					v[tx][ty][(u.d+1)%4] = true;
					q.push(p(tx,ty,(u.d+1)%4,u.dis+1));
				}
			}
			tx = u.x+dx[(u.d+3)%4];
			ty = u.y+dy[(u.d+3)%4];
			if(is_ok(tx,ty,(u.d+3)%4,h,w,map)){
				if(is_final(tx,ty,h,w)){
					ans = u.dis+1;
					break;
				}
				is_turned = true;
				if(!v[tx][ty][(u.d+3)%4]){
					v[tx][ty][(u.d+3)%4] = true;
					q.push(p(tx,ty,(u.d+3)%4,u.dis+1));
				}
			}
			tx = u.x+dx[u.d];
			ty = u.y+dy[u.d];
			if(!is_turned && is_ok(tx,ty,u.d,h,w,map)){
				if(v[tx][ty][u.d]){
					continue;
				}
				if(is_final(tx,ty,h,w)){
					ans = u.dis+1;
					break;
				}
				v[tx][ty][u.d] = true;
				q.push(p(tx,ty,u.d,u.dis+1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
