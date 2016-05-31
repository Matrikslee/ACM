#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 2001
using std::max;

int main(int argc, char* argv[]){
  int n;
  static int cnt[MAXN];
  while(~scanf("%d", &n)){
    memset(cnt, 0x0, sizeof(cnt));
    for ( int i = 0,x; i < n; ++ i ){
      scanf("%d",&x);
      ++cnt[x];
    }
    int ans = 0;
    for ( int i = 0; i < MAXN; ++i) {
      ans = max(ans, cnt[i]);
    }
    for ( int i = 0; i<MAXN; ++i) {
      if(cnt[i]==0) continue;
      for ( int j = 1; j < MAXN; ++j) {
        int pos = i, len = 0;
        while(pos<MAXN&&cnt[pos]!=0) {
          pos+=j;
          ++len;
        }
        ans = max(ans,len);
      }
    }
    printf("%d\n", ans);
  }
}
