#include <stdio.h>
#include <queue>
using std::priority_queue;

priority_queue<int> Q;

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for ( int i = 0; i < n; ++i ) {
    int x;
    scanf("%d", &x);
    Q.push(x);
  }
  long long value[2];
  int status = 0;
  while(!Q.empty()) {
    status %= 4;
    long long tmp = Q.top(); Q.pop();
    switch(status) {
    case 0:
      value[0] = tmp;
      ++status;
      break;
    case 1:
      if(tmp==value[0] || tmp+1==value[0]) { ++status; }
      value[0] = tmp;
      break;
    case 2:
      value[1] = tmp;
      ++status;
      break;
    case 3:
      if(tmp==value[1] || tmp+1==value[1]) { ++status; }
      value[1] = tmp;
    default:
      break;
    }
    if(status==4) {
      ans += value[0]*value[1];
    }
  }
  printf("%lld", ans);
}

