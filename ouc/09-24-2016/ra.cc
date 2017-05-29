#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int t = rand()%10;
  printf("%d\n", t);
  while(t--){
    int n = rand()%60000;
    printf("%d\n", n);
    for ( int i = 1 ;i < n ; ++ i ){
      printf("%d ", rand()%1000000);
    }
    printf("%d\n", rand()%1000000);
    for ( int i = 1 ;i < n ; ++ i ){
      printf("%d ", rand()%1000000);
    }
    printf("%d\n", rand()%1000000);
  }
}
