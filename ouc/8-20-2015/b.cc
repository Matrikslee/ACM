#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 100005

struct node{
	int to;
	node* next;
} head[MAXM], *pbuf, *e[MAXN];

int ans, idx;

int dfn[MAXN];
int low[MAXN];
int tag[MAXN];
bool inS[MAXN];

#include <stack>

std::stack<int> S;

bool dfs( int u ) {
	int v;
	S.push(u);
	inS[u] = true;
	dfn[u] = low[u] = ++idx;
	for ( node* p = e[u]; p!=NULL; p=p->next ) {
		v = p->to;
		if ( !dfn[v] ) {
			dfs( v );
			if ( low[v] < low[u] ) {
				low[u] = low[v];
			}
		} else if ( inS[v] && low[v] < low[u] ) {
			low[u] = low[v];
		}
	}
	if ( dfn[u] == low[u] ) {
		++ ans;
		do {
			v = S.top();
			inS[v] = false;
			tag[v] = ans;
			S.pop();
		} while( u!=v );
	}
}

int main( int argc, char const *argv[] ) {
	for ( int n,m; ~scanf("%d%d", &n, &m) && n+m!=0; ) {
		pbuf = head;
		memset(e, 0x0, sizeof(e));
		memset(head, 0x0, sizeof(head));
		for ( int i = 0, x, y; i < m; ++ i ) {
			scanf("%d%d", &x, &y);
			pbuf->to = y;
			pbuf->next = e[x];
			e[x] = pbuf++;
		}
		ans = idx = 0;
		memset(dfn, 0x0, sizeof(dfn));
		memset(low, 0x0, sizeof(low));
		memset(tag, 0x0, sizeof(tag));
		memset(inS, 0x0, sizeof(inS));
		while ( !S.empty() ) { S.pop(); }
		for( int i = 1; i <= n; ++ i ) {
			if ( !dfn[i] ) {
				dfs( i );
			}
		}
		printf("%s\n", ans == 1 ? "Yes" : "No" );
	}
	return 0;
}