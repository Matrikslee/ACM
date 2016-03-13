#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]){
	srand(time(NULL));
	int n = 200000;
	printf("%d\n", n);
	for(int i=1; i<=n; ++i){
		printf("%d %d\n", rand()%i, rand()%1001+1);
	}
	return 0;
}