#include <cstdio>

int main(int argc, char const *argv[])
{
	int k, ans[15] = {0};
	while(scanf("%d", &k) && k!=0){
		if(ans[k] == 0) {
			int n = k*2;
			for(int m = k+1; ; ++m){
				for(int cur=(m-1)%n+1, tot=n; cur>k && tot!=k;){
					cur = (cur+m-2)%--tot+1;
					if(tot==k){ ans[k] = m; }
				}
				if(ans[k]!=0) { break; }
			}
		}
		printf("%d\n", ans[k]);
	}
	return 0;
}