#include <stdio.h>

int main(int argc, char const *argv[]){
	for(int n;~scanf("%d", &n); printf("%d\n", n/7*2+n%7/6));
	return 0;
}