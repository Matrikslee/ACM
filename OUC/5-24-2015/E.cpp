#include <cstdio>
#define MAXN 33333

int find(int *link, int i);

int main(int argc, char const *argv[])
{
	static int link[MAXN];
	for(int m,n;~scanf("%d%d", &n, &m) && n!=0; ){
		for(int i=0; i<n; ++i) {
			link[i]=i;
		}
		for(int i=0; i<m; ++i){
			int k, t;
			scanf("%d", &k);
			scanf("%d", &t);
			int tlink=find(link, t);
			for(int j=1; j<k; ++j){
				int x;
				scanf("%d", &x);
				int xlink=find(link, x);
				link[xlink]=tlink;
			}
		}
		int ans=0, slink=find(link, 0); 
		for(int i=0; i<n; ++i){
			if(find(link, i) == slink) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

int find(int *link, int i)
{
	if(link[i]!=i){
		link[i] = find(link, link[i]);
	}
	return link[i];
}