#include <cstdio>
#include <cstring>
#define MAXN 111111

struct node {
	int value;
	node *next[10];
};

void insert(node *root, node **pbuf, char *s);
bool check(node *root);

int main(int argc, char const *argv[])
{
	int t, n;
	static node root[MAXN]; 
	for(scanf("%d", &t); t!=0; --t){
		node *pbuf = root;
		memset(root, 0x0, sizeof(root));
		for(scanf("%d\n", &n); n!=0; --n){
			char s[11];
			scanf("%s", s);
			insert(root, &pbuf, s);
		}
		if( check(root) ) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

void insert(node *root, node **pbuf, char *s){
	node *p  = root;
	for(char *ps = s; *ps!='\0'; ++ps){
		int v = *ps-'0';
		if( p->next[v]==NULL ){
			p->next[v] = ++(*pbuf);
		}
		p = p->next[v];
	}
	++(p->value);
}

bool check(node *root){
	bool ans = true;
	int head=0, tail=0;
	static node *q[MAXN];

	q[tail++] = root;
	while( ans && head<tail ){
		node *p = q[head++];
		for(int i=0; i<10; ++i){
			if( p->next[i]==NULL ){
				continue;
			}
			if( p->value ){
				ans = false;
				break;
			}
			q[tail++] = p->next[i];
		}
	}
	return ans;
}