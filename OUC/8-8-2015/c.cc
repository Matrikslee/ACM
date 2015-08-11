#include <stdio.h>

int main(int argc, char const *argv[]){
	for(int n,k,ans=0; ~scanf("%d%d\n", &n,&k);){
		for(int x,i=0; i++<n; scanf("%d", &x), ans+=x);
		for(int i=0; i++<k; scanf("%d"));
		for(int i=1; i++<n; scanf("%d"));
		printf("%d\n", ans);
	}
	return 0;
}