#include <stdio.h>

#define MAXN 610000

int main(int argc, char const *argv[]){
	static int f[MAXN];
	for (int i = 2; i <= MAXN; f[i]-=i, i++) {
		for(int j=1; i*j<=MAXN; ++j){
			f[i*j] += i+j;
		}
		if( (long long)i*i < MAXN ) { f[i*i] += i; }
	}
	int T; for(scanf("%d", &T); T; --T){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d %d\n", f[a], f[b]);
		// if(f[a]==b && f[b]==a){
		// 	printf("YES\n");
		// } else {
		// 	printf("NO\n");
		// }
	}
	return 0;
}