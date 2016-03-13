#include <stdio.h>
#include <string.h>
#include <queue>

class S {
	const int len;
	int cnt;
	int* v;
public:
	S(int n):len(n+10), cnt(n) {
		v = new int[len];
		for(int i=0; i<len; v[i]=i,++i);
	}
	~S() {
		delete[] v;
	}
	int find(int x){
		return v[x]==x?x:v[x]=find(v[x]);
	}
	bool is_merged(int x, int y){
		return find(x)==find(y);
	}
	void merge(int x, int y) {
		if( !is_merged(x,y) ) {
			v[find(x)] = find(y);
		}
	}
	int count() {
		return cnt;
	}
};

struct node{
	int to;
	node* next;
	node():to(0),next(NULL){}
	node(int o, node* n):to(o), next(n){}
};

template <typename T>
class G {
	const int dotNumber;
	T **const e;
public:
	G(int n): dotNumber(n), e(new T*[dotNumber]){
		for(int i=0; i<n; ++i) {
			e[i] = new T();
		}
	}
	~G(){
		for(int i=0; i<dotNumber; ++i) {
			while ( e[i]!=NULL ) {
				T* p = e[i];
				e[i] = p->next;
				delete p;
			}
		}
		delete[] e;
	}
	void link(int u, int v) {
		e[u]->next = new T(v,e[u]->next);
	}
	const T* head(int u) {
		return e[u];
	}
};

const int maxn = 10000+5;

struct edge{
	int x,y;
	char c;
};

int main(int argc, char const *argv[]){
	for ( int n,m; ~scanf("%d%d", &n, &m) ; ) {
		S set(n);
		int tot = n;
		static edge e[maxn];
		for ( int i=0; i<m; ++i ) {
			int x, y; char c;
			scanf("%d %c %d", &e[i].x, &e[i].c, &e[i].y);
			if( e[i].c=='=' && !set.is_merged(e[i].x,e[i].y) ) {
				set.merge(e[i].x, e[i].y);
				--tot;
			}
		}
		G<node> graph(n);
		bool ans = false;		
		static int in_degree[maxn];
		memset(in_degree, 0x0, sizeof(in_degree));
		for (int i=0; i<m; ++i) {
			if ( e[i].c=='=' ) { continue; }
			int x = set.find(e[i].x);
			int y = set.find(e[i].y);
			if ( x==y ) { ans = true; }
			if ( e[i].c=='>' && !ans) {
				++in_degree[y];
				graph.link(x,y);
			} else if ( e[i].c=='<' && !ans) {
				++in_degree[x];
				graph.link(y,x);
			}
		}
		if( ans ) {
			printf("CONFLICT\n");
			continue;
		}
		ans = false;
		std::queue<int> Q;
		for(int i=0; i<n; ++i) {
			if ( in_degree[i]==0 && set.find(i)==i ) {
				Q.push(i);
			}
		}
		while( !Q.empty() ) {
			if( Q.size()>1 ) {
				ans = true;
			}
			int now = Q.front(); Q.pop(); --tot;
			for( const node* p = graph.head(now); p!=NULL; p=p->next ) {
				if( 0 == --in_degree[p->to] ) {
					Q.push(p->to);
				}
			}
		}
		if ( tot>0 ) {
			puts("CONFLICT");
		} else if( ans ) {
			puts("UNCERTAIN");
		} else {
			puts("OK");
		}
	}
	return 0;
}