#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int n = rand()%100+1;
	printf("%d\n", n);
	for(int i=0; i<n; ++i){
		printf("%d %d\n", rand()%600000+1, rand()%600000+1);
	}
	return 0;
}