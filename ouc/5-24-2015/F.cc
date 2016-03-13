#include <cstdio>
#define MAXN 111

struct line{
	int s,t,v;
};

void swap(line *a, line *b)
{
	line tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char const *argv[])
{
	line l[MAXN], *p=l;
	int n, num=0, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int x;
			scanf("%d", &x);
			if(i>j){
				p->s=i;
				p->t=j;
				p->v=x;
				++p;
			}
		}
	}
	bool vis[MAXN] = {false};
	for(p=l; p<l+num; ++p){
		if(!vis[p->s] || !vis[p->t]){
			ans += p->v;
			vis[p->s] = true;
			vis[p->t] = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
