#include <cstdio>
#define MAXN 55

int find(int* f, int x){
	return f[x]==x?x:f[x]=find(f,f[x]);
}

int link(int* f, int x, int y){
	f[find(f,x)] = find(f,y);
}

int main(int argc, char const *argv[]){
	int f[MAXN];
	// input
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i){
		f[i] = i;
	}
	for(int i=0; i<m; ++i){
		int x,y;
		scanf("%d%d",&x,&y);
		link(f,x,y);
	}
	int cnt=0, fuck[MAXN];
	for(int i=1; i<=n; ++i){
		bool is_found = false;
		for(int j=0; j<cnt; ++j){
			if(fuck[j]==find(f,i)){
				is_found = true;
				break;
			}
		}
		if(!is_found){
			fuck[cnt++] = find(f,i);
		}
	}
	long long ans;
	for(ans=1,n-=cnt; n-->0; ans*=2);
	printf("%lld\n", ans);
	return 0;
}
