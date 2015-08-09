#include <stdio.h>

inline int max(int a, int b) {return a>b?a:b;}
const int MAXN = 1111111;

int main(int argc, char const *argv[]){
	for(int n, m; ~scanf("%d%d", &n, &m);){
		int sum = 0, tmp = 0, ans = 0;
		static int f[MAXN];
		for(int i=1; i<=n; ++i){
			scanf("%d", f+i);
			if(i<=m){
				sum += f[i];
				tmp += i*f[i];
			} else {
				tmp += f[i]*m-sum;
				sum += f[i]-f[i-m];
			}
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}