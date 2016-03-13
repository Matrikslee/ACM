#include <cstdio>
#include <ctime>
#include <cstdlib>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int T = rand()%100+1;
	while(T--){
		int x = rand()%1000+1;
		int n = rand()%12+1;
		printf("%d %d ", x, n);
		for(int i=0; i<n; ++i){
			printf("%d ", rand()%100+1);
		}
		printf("\n");
	}
	printf("0 0\n");
	return 0;
}