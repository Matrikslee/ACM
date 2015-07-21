#include <cstdio>
#define MAXN 111

struct barrier{
	int x1, y1;
	int x2, y2;
};

void bfs(int startx, int starty, int dis[][MAXN], int w, int h, barrier *bar, int n);

int main(int argc, char const *argv[])
{
	int t; 
	for(scanf("%d", &t); t; --t) {
		bool vis[MAXN][MAXN] = {true};
		int  w, h, endx=0, endy=0;
		scanf("%d%d\n", &w, &h);
		bool fail = false;
		int  pathlen = 0;
		char ch;
		while(ch=getchar(), ch!= '\n'){
			switch(ch){
				case 'R': endx++; break;
				case 'U': endy++; break;
				case 'L': endx--; break;
				case 'D': endy--; break;
				default : break;
			}
			vis[endx][endy]=true;
			++pathlen;
		}
		int n;
		scanf("%d", &n);
		barrier bar[MAXN*MAXN];
		for(int i=0; i<n; ++i){
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			bar[i].x1=x1; bar[i].y1=y1;
			bar[i].x2=x2; bar[i].y2=y2;
			vis[x1][y1]=true;
			vis[x2][y2]=true;
		}
		int dis1[MAXN][MAXN]={0}, dis2[MAXN][MAXN]={0};
		bfs(0, 0, dis1, w, h, bar, n); bfs(endx, endy, dis2, w, h, bar, n);
		for(int i=0; i<w; ++i){
			for(int j=0; j<h; ++j){
				if(!vis[i][j]&&dis1[i][j]+dis2[i][j]==pathlen){
					fail=true;
					break;
				}
			}
			if (fail){
				break;
			}
		}
		if (fail){
			printf("INCORRECT\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			int x1=bar[i].x1, y1=bar[i].y1;
			int x2=bar[i].x2, y2=bar[i].y2;
			if( (dis1[x1][y1]+dis2[x2][y2]>pathlen 
			 && dis2[x1][y1]+dis1[x2][y2]>pathlen) 
			 || (dis1[x1][y1]==0 && dis2[x1][y1]==0) 
			 || (dis1[x2][y2]==0 && dis2[x2][y2]==0) ){
				fail=true;
				break;
			}
		}
		if (fail) {
			printf("INCORRECT\n");
			continue;
		}
		printf("CORRECT\n");
	}
	return 0;
}

void bfs(int startx, int starty, int dis[][MAXN], int w, int h, barrier *bar, int n)
{
	bool vis[MAXN][MAXN]={false}; vis[startx][starty]=true;
	int  Qx[MAXN*MAXN], Qy[MAXN*MAXN], head=0, tail=0;
	Qx[tail]=startx; Qy[tail]=starty; ++tail;
	while(head<tail){
		int x=Qx[head], y=Qy[head]; ++head;
		const int dx[4]={0,1,0,-1};
		const int dy[4]={1,0,-1,0};
		for(int i=0; i<4; ++i){
			int px=x+dx[i];
			int py=y+dy[i];
			if(vis[px][py] || px<0||py<0||px>=w||py>=h) {
				continue;
			}
			bool isgo=true;
			for(int j=0; j<n; ++j){
				int x1=bar[j].x1, y1=bar[j].y1;
				int x2=bar[j].x2, y2=bar[j].y2;
				if( x1==x&&y1==y&&x2==px&&y2==py
				 || x2==x&&y2==y&&x1==px&&y1==py ) {
					isgo=false; break;
				}
			}
			if(!isgo){ 
				continue;
			}
			dis[px][py]=dis[x][y]+1;
			vis[px][py]=true;
			Qx[tail]=px;
			Qy[tail]=py;
			++tail;
		}
	}
}