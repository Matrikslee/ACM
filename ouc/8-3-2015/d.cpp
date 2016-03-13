#include <stdio.h>

#define MAXN 1000001

int main(int argc, char const *argv[]){
	static int sum[MAXN];
	for(int i=1; i<MAXN; ++i){
		sum[i] = sum[i-1]+1;
		for(int x=i; x!=0; x/=10){
			if(x%10==4 || x%100==62){
				--sum[i];
				break;
			}
		}
	}
	for(int l, r; ~scanf("%d%d", &l, &r)&&(l+r); printf("%d\n", sum[r]-sum[l-1]));
	return 0;
}