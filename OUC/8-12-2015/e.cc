#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class link {
	const int len;
	int cnt;
	int* v;
public:
	link(int n):len(n+10), cnt(n) {
		v = (int*)malloc(sizeof(int)*len);
		for(int i=0; i<len; v[i]=i,++i);
	}
	~link() {
		free(v);
	}
	int find(int x){
		return v[x]==x?x:v[x]=find(v[x]);
	}
	bool merge(int x, int y){
		bool res = true;
		int fx = find(x), fy=find(y);
		if( fx!=fy ) {
			v[fx] = fy;
			--cnt;
		} else {
			res = false;
		}
		return res;
	}
	int count() {
		return cnt;
	}
};

int main(int argc, char const *argv[]){
	const int MAXN = 100000;
	while ( true ) {
		bool is_final = false;
		bool is_ok = true;
		int cnt = 0;
		link list(MAXN);
		static bool vis[MAXN];
		memset(vis, 0x0, sizeof(vis));
		for( int x,y; ~scanf("%d%d", &x, &y); ){
			if( x==-1 && y==-1 ) {
				is_final = true;
				break;
			}
			if( x==0 && y==0 ) {
				if( cnt==0 ) { ++cnt; }
				break;
			}
			if ( !vis[x] ){
				++cnt;
				vis[x] = true;
			}
			if ( !vis[y] ){
				++cnt;
				vis[y] = true;
			}
			if( x==y ) { continue; }
			if( !list.merge(x,y) ){
				is_ok = false;
			} else {
				--cnt;
			}
		}
		if( is_final ) {
			break;
		}
		if( is_ok && cnt==1 ){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}