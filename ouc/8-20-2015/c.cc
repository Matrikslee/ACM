#include <stdio.h>

int main(int argc, char const *argv[]){
	for( int n; ~scanf("%d", &n) && n!=0; printf("%d\n", (n-1)/2));
	return 0;
}