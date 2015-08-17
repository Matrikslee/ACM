#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;

struct edge{
	char u,v;
	int weight;
	edge():u(0), v(0), weight(0){}
	edge(char a, char b, int w):u(a), v(b), weight(w){}
	friend bool operator < (const edge& a, const edge& b) {
		return a.weight>b.weight;
	}
};

class Union{
	int* f;
	int cnt;
public:
	Union(int n) : cnt(n) {
		f = new int[256];
		for(int i=1; i<=256; ++i){
			f[i] = i;
		}
	}
	int find(int x) { 
		return x==f[x]?x:f[x]=find(f[x]);
	}
	bool is_merged(int x, int y) {
		return find(x)==find(y);
	}
	void merge(int x, int y) {
		if( !is_merged(x,y) ){
			f[find(x)] = find(y);
			--cnt;
		}
	}
	int count() {
		return cnt;
	}
	~Union(){
		delete[] f;
	}
};

int main(int argc, char const *argv[]) {
	for(int n; cin>>n && n!=0; ) {
		std::priority_queue<edge> Q;
		for(int i=1,k; i<n; ++i) {
			char c,s; cin >> c >> k;
			for(int j=0,w; j<k; ++j) {
				cin >> s >> w;
				Q.push(edge(c,s,w));
			}
		}
		Union T(n);
		int ans = 0;
		for( ; !Q.empty() || T.count()>1; Q.pop()) {
			edge cur = Q.top();
			if( !T.is_merged(cur.u, cur.v) ) {
				T.merge(cur.u, cur.v);
				ans += cur.weight;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
