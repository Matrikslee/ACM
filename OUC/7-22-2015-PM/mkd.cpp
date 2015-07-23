#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	for(int i=0; i<40; ++i){
		for(int j=0; j<40; ++j){
			if(i==0 || j==0 || i==39 || j==39 ){
				putchar('#');
			} else {
				putchar(".#"[rand()%101%2]);
			}
		}
		putchar('\n');
	}
	return 0;
}