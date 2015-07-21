#include <cstdio>
#include <ctime>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n = rand()%100;
	for(int i=0; i<n; ++i){
		printf("%d\n", rand()%1000000);
	}
	printf("0\n");
	return 0;
}