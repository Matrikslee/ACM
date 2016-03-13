#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	for(int i=rand()%11+1; i>0; --i){
		int x=rand()%40000+10000, y1=rand()%40000+10000, z1=rand()%40000+10000;
		int y2=rand()%40000+10000, z2=rand()%40000+10000;
		long long p = rand()%90000000+10000000;
		printf("%d %d %d\n", x,y1,z1);
		printf("%d %d\n%lld\n", y2,z2,p);
	}
	printf("-1 -1 -1\n");
	return 0;
}