#include <stdio.h>
#include <algorithm>

#define MAXN 1111

struct node{
	int v,w;
	double p;
};

bool cmp(const node &a, const node &b) { return a.p>b.p; }

int main(int argc, char const *argv[]){
	for(int m,n; ~scanf("%d%d", &m, &n); ){
		if(m==-1 && n==-1){ break; }
		node x[MAXN];
		for(int i=0; i<n; ++i){
			scanf("%d%d",&x[i].v, &x[i].w);
			x[i].p = x[i].v/(double)x[i].w;
		}
		std::sort(x, x+n, cmp);
		double ans = 0;
		for(node *pos=x; m>0 && pos-x<n; ++pos){
			if(m>pos->w){
				ans += pos->v;
				m -= pos->w;
			} else {
				ans += m*pos->p;
				m = 0;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}