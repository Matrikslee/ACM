#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
	srand(time(NULL));
	for(int i=0; i<10; ++i){
		printf("%c\n", "NWSE"[rand()%4]);
		bool vis[4][13] = {false};
		for(int cardNumbers = 0;cardNumbers<52;){
			int color = rand()%4;
			int number = rand()%13;
			if(!vis[color][number]){
				vis[color][number] = true;
				printf("%c%c", "CDSH"[color], "23456789TJQKA"[number]);
				if(++cardNumbers==26){
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	printf("#\n");
	return 0;
}