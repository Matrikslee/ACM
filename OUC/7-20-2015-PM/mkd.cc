#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	for(int t=rand()%20+1; t; --t){
		for(int n=rand()%20+1;n;--n){
			putchar("01"[rand()%2]);
		}
		putchar('\n');
	}
	return 0;
}