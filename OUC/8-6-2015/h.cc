#include <stdio.h>

#define MAXN 1111

struct node{
	int w,s,idx;
};

bool cmp(const node &a, const node &b) { return a.s>b.s; }

int main(int argc, char const *argv[]){
	static node a[MAXN];
	for(n=0; ~scanf("%d%d", &a[i].w, &a[i].s); ++n);
	std::sort(a,a+n,cmp);
	static int f[MAXN], pre[MAXN];
	for(int i=0; i<n; ++i){
		f[i] = 1;
		for(int j=0; j<i; ++j){
			
		}
	}
	return 0;
}