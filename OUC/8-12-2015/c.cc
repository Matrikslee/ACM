#include <stdio.h>
#include <stdlib.h>

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
	void merge(int x, int y){
		int fx = find(x), fy=find(y);
		if(fx!=fy) {
			v[fx] = fy;
			--cnt;
		}
	}
	int count() {
		return cnt;
	}
};

int main(int argc, char const *argv[]){
	int T, n, m; for(scanf("%d", &T); T; --T) {
		scanf("%d%d", &n, &m);
		link list(n);
		for(int i=0,x,y; i<m; ++i){
			scanf("%d%d", &x, &y);
			list.merge(x,y);
		}
		printf("%d\n", list.count());
	}
	return 0;
}