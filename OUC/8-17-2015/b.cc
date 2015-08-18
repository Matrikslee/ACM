#include <stdio.h>
#include <string.h>
#include <queue>
const int maxn = 2200;
const int maxx = maxn*maxn;

inline int max(int a, int b) { return a>b?a:b; }

struct node {
	int p; 
	node* next;
	node():p(0), next(NULL){}
	node(int o, node* n):p(o), next(n){}
} head[maxx], *pbuf=head, *e[maxn];

int main(int argc, char const *argv[]) {
	int t, n, cnt=1;
	for(scanf("%d", &t); cnt<=t; ++cnt) {
		pbuf = head;
		scanf("%d\n", &n);
		static int rank[maxn];
		memset(e, 0x0, sizeof(e));
		memset(rank, 0x0, sizeof(rank));
		for(int i=0; i<n; ++i) {
			char s[maxn]; gets(s);
			for(int j=0; j<n; ++j) {
				if( s[j]=='1' ) {
					pbuf->p = j;
					pbuf->next = e[i];
					e[i] = pbuf++;
					++rank[j];
				}
			}
		}
		std::queue<int> Q;
		for(int i=0; i<n; ++i) {
			if( rank[i]==0 ) {
				Q.push(i);
			}
		}
		int cntx = 0;
		while( !Q.empty() ) {
			++cntx;
			int now = Q.front(); Q.pop();
			for( node* q=e[now]; q!=NULL; q=q->next ) {
				if ( 0 == --rank[q->p] ) {
					Q.push(q->p);
				}
			}
		}
		printf("Case #%d: ", cnt);
		if( cntx<n ) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}