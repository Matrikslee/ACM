#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	for(int n=rand()%20+1, i=0, k; i<n; ++i){
		printf("%d ", k=rand()%100000+1);
		printf("%d\n",k+rand()%900000+1);
	}
	printf("0 0\n");
	return 0;
}