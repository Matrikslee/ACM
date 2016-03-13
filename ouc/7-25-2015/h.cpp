#include <iostream>
#include <cstring>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
const int maxTime = 6;

struct D{
	int x,y,d,t;
	D():x(0),y(0),d(0),t(0){}
	D(int xx, int yy, int dd, int tt):x(xx),y(yy),d(dd),t(tt){}
};

int main(int argc, char const *argv[]){
	int T; cin >>T;
	while(T--){
		int map[11][11] = {0};
		int n, m, sx, sy, ans=-1;
		cin >> n >> m;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin >> map[i][j];
				if(map[i][j] == 2){	sx = i, sy = j; }
			}
		}
		bool vis[11][11][11] = {false};
		std::queue<D> q;
		for(;!q.empty(); q.pop());
		q.push(D(sx,sy,0,0));
		vis[sx][sy][0] = true;
		for(;!q.empty(); q.pop()){
			D td = q.front();
			int d = td.d, t = td.t;
			int x = td.x, y = td.y;
			if( t==maxTime ) { continue; }
			if( map[x][y]==3 ) { ans = d; break; }
			if( map[x][y]==4 ) { t = 0; }
			for(int i=0; i<4; ++i){
				int tx = x+dx[i], ty=y+dy[i];
				if( tx<0||tx==n||ty<0||ty==m ) { continue; }
				if( map[tx][ty]==0 ) { continue; }
				if( vis[tx][ty][t+1] ) { continue; }
				vis[tx][ty][t+1] = true;
				q.push(D(tx,ty,d+1,t+1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}