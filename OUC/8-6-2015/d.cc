#include <stdio.h>
#include <string.h>

#define MAXN 7589

int main(int argc, char const *argv[]){
	const int a[] = {0,1,5,10,25,50};
	static int f[MAXN][6];
	for(int i=0; i<=MAXN; ++i){
		for(int j=0; j<=5; ++j){
			if(i==0) {
				f[i][j] = 1;
			} else if(j==0) {
				f[i][j] = 0;
			} else if(a[j]>i){
				f[i][j] = f[i][j-1];
			} else {
				f[i][j] = f[i-a[j]][j]+f[i][j-1];
			}
		}
	}
	for(int tot; ~scanf("%d", &tot); printf("%d\n", f[tot][5]));
	return 0;
}