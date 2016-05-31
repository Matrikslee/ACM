#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::min;

#define MAXN 1001
#define MAXA 101

int f[MAXN][MAXA];
long long g[MAXN][MAXA];
int a[MAXN], b[MAXN];

int main() {
  int n,m;
  while(~scanf("%d%d",&n,&m)) {
    long long ans = 0;
    memset(f,0x0,sizeof(f));
    memset(g,0x0,sizeof(g));
    for ( int i = 1; i <= n; ++ i ) scanf("%d",a+i);
    for ( int i = 1; i <= n; ++ i ) scanf("%d",b+i);
    for ( int i = 1; i <= n; ++ i ) ans += a[i]*a[i]*b[i];
    for ( int i = 1; i <= n; ++ i ) {
      for ( int j = 0; j < a[i]; ++j) {
        for ( int k = j+1; k <= a[i]; ++k) {
          f[i][k] = f[i-1][j] + k-j;
          g[i][k] = g[i-1][j] + (k-j)*(k-j)*b[i];
          if(f[i][k]>=m) {
            ans = min(ans, g[i][k]);
          }
        }
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}
