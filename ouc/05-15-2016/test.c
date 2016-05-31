#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
  srand(time(NULL));
  int T = rand()%100;
  int n = rand()%10000;
  for ( int t = 0; t < T; ++t){
    printf("%d\n",n);
    for ( int i = 0; i < n; ++ i) {
      printf("%d ", rand()%2001);
    }
    printf("\n");
  }
}
