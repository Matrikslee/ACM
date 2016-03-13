#include <stdio.h>
#include <string.h>
#define MAXN 2008

int main(int argc, char const *argv[]){
	for(int n; ~scanf("%d", &n); ){
		bool ans = true;
		if( n==2 ){
			int x, y;
			scanf("%d-%d", &x, &y);
			if(x!=y && x+y==3){
				ans = true;
			} else {
				ans = false;
			}
		} else {
			static int count[MAXN];
			memset(count, 0x0, sizeof(count));
			for(int i=1,x,y; i<n; ++i){
				scanf("%d-%d", &x, &y); ++count[x], ++count[y];
				scanf("%d-%d", &x, &y); ++count[x], ++count[y];
			}
			for(int i=1; i<=n; ++i){
				if(count[i] != n-1){
					ans = false;
					break;
				}
			}
		}
		if( ans ){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}