#include <iostream>
#include <queue>

#define MAXW 111
#define MAXH 111

using std::cin;
using std::cout;
using std::endl;

struct D{
	int x, y;
	D():x(0),y(0){}
	D(int xx, int yy):x(xx),y(yy){}
};

bool can_go(char (*map)[MAXH], int w, int h, int tx, int ty){
	return tx>=0&&tx<=w&&ty>=0&&ty<=h&&map[tx][ty]=='#';
}

bool bfs(char (*map)[MAXH], int w, int h, int startX, int startY){
	map[startX][startY] = '.';
	std::queue<D> q;
	for(;!q.empty();q.pop());
	q.push(D(startX,startY));
	for(; !q.empty(); q.pop()){
		D now = q.front();
		int x = now.x, y = now.y;
		const int dx[] = {-1, 0, 0, 1};
		const int dy[] = {0, -1, 1, 0};
		for(int i=0; i<4; ++i){
			int tx = x+dx[i], ty = y+dy[i];
			if(can_go(map,w,h,tx,ty)){
				map[tx][ty] = '.';
				q.push(D(tx,ty));
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int T; 
	for(cin>>T; T; --T){
		int w, h;
		cin >> h >> w;
		char map[MAXW][MAXH];
		for(int j=0; j<h; ++j){
			for(int i=0; i<w; ++i){
				cin >> map[i][j];
			}
		}
		int ans = 0;
		for(int i=0; i<w; ++i){
			for(int j=0; j<h; ++j){
				if(map[i][j]=='#'){
					bfs(map,w,h,i,j);
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}