#include <stdio.h>
#include <queue>
#include <stdlib.h>

struct edge{
	int x,y,d;
	edge():x(0), y(0), d(0){}
	edge(int xx, int yy, int dd):x(xx),y(yy),d(dd){}
	bool friend operator < (const edge& a, const edge& b){
		return a.d>b.d;
	}
};

class link {
	const int len;
	int cnt;
	int* v;
public:
	link(int n):len(n+10), cnt(n) {
		v = (int*)malloc(sizeof(int)*len);
		for(int i=0; i<len; v[i]=i,++i);
	}
	~link(){
		free(v);
	}
	int find(int x){
		return v[x]==x?x:v[x]=find(v[x]);
	}
	void merge(int x, int y){
		int fx = find(x), fy=find(y);
		if(fx!=fy) {
			v[fx] = fy;
			--cnt;
		}
	}
	int count() {
		return cnt-1;
	}
};

int main(int argc, char const *argv[]){
	for(int n; ~scanf("%d", &n) && n!=0; ) {
		std::priority_queue<edge> Q;
		for(int i=0; i<n*(n-1)/2; ++i){
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			Q.push(edge(x,y,d));
		}
		int ans = 0;
		link list(n);
		for(int i=1; i<n; ++i){
			int x=Q.top().x, y=Q.top().y;
			while( list.find(x)==list.find(y) ){
				Q.pop();
				x = Q.top().x;
				y = Q.top().y;
			}
			list.merge(x,y);
			ans += Q.top().d;
		}
		printf("%d\n", ans);
	}
	return 0;
}