#include <stdio.h>
int main(int argc, char* argv[]) {
  int n,k,ans;
  while(~scanf("%d%d", &n, &k)){
    if(n<2*k) {
      ans = 2*k-1;
    } else {
      ans = 2*k;
    }
    printf("%d\n", ans);
  }
}
