#include <stdio.h>

int main(int argc, char const *argv[]){
	int n,m;
	scanf("%d%d", &n, &m);
	if( m==n && n==1){
		printf("1\n");
	} else if( m-1>=n-m ) {
		printf("%d\n", m-1);
	} else {
		printf("%d\n", m+1);
	}
	return 0;
}