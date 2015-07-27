#include <iostream>

#define MAXN 33333

using std::cin;
using std::cout;
using std::endl;

class T{
	int f[MAXN], len;
public:
	T():len(MAXN){
		for(int i=0; i<MAXN; ++i){
			f[i] = i;
		}
	}
	T(int l):len(l){
		for(int i=0; i<len; ++i){
			f[i] = i;
		}
	}
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void link(int x, int y){
		f[find(y)] = find(x);
	}
};

int main(int argc, char const *argv[]){
	for(int n,m;cin>>n>>m && n!=0; ){
		T S(n);
		for(int i=0; i<m; ++i){
			int x,u; cin >> x >> u;
			for(int j=1; j<x; ++j){
				int v; cin >> v;
				S.link(u,v);
			}
		}
		int ans = 1;
		for(int i=1; i<n; ++i){
			if(S.find(i)==S.find(0)){
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}