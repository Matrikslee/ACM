#include <stdio.h>
#include <limits.h>
#include <math.h>

const int maxn = 60000;
int a[maxn], b[maxn];

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; ++ i ){
      scanf("%d", a+i);
    }
    for ( int i = 0; i < n; ++ i ){
      scanf("%d", b+i);
    }
    long long ans = LONG_MAX;
    for ( int k = 0; k < n; ++ k ){
      long long tmp = 0;
      for ( int i = 0; i < n; ++ i ){
        long long x = a[i]-b[(i+k)%n];
        tmp +=  x*x;
        if(tmp>ans) { break; }
      }
      if(tmp<ans) { ans = tmp; }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
