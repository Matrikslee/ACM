#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	printf("%d\n%d", rand()%10000+1, rand()%20+1);
	return 0;
}