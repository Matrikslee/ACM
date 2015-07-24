#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

#define MAXW 22
#define MAXH 22

struct D{
	int x, y;
	D():x(0),y(0){}
	D(int xx, int yy):x(xx),y(yy){}
};

bool can_go(char (*map)[MAXH], int w, int h, int x, int y){
	return x>=0 && x<w && y>=0 && y<h && map[x][y]=='.';
}

int main(int argc, char const *argv[]){
	for( int w, h, startX, startY; cin>>w>>h && w*h!=0; ){
		char map[MAXW][MAXH];
		for(int j=0; j<h; ++j){
			for(int i=0; i<w; ++i){
				cin >> map[i][j];
				if(map[i][j]=='@'){
					startX = i, startY =j;
				}
			}
		}
		int ans = 1;
		std::queue<D> q;
		for(;!q.empty();q.pop());
		q.push(D(startX,startY));
		for(;!q.empty();q.pop()){
			D tmp = q.front();
			int x = tmp.x, y = tmp.y;
			// cout << "(" << x << "," << y << ")-->";
			const int dx[] = {-1,0,0,1};
			const int dy[] = {0,-1,1,0};
			for(int i=0; i<4; ++i){
				int tx = x+dx[i], ty = y+dy[i];
				if(can_go(map,w,h,tx,ty)){
					// cout << "("<<tx<<","<<ty<<"), ";
					map[tx][ty] = '#';
					q.push(D(tx,ty));
					++ans;
				}
			}
			// cout << endl;
		}
		// for(int i=0; i<w; ++i){
		// 	for(int j=0; j<h; ++j){
		// 		cout << map[i][j];
		// 	}
		// 	cout << endl;
		// }
		cout << ans << endl;
	}
	return 0;
}