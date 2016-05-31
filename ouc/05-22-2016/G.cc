#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>

using std::priority_queue;
using std::greater;
using std::vector;

int main(){
  priority_queue<long long,vector<long long>,greater<long long> > Q;
  int n,k;
  scanf("%d%d", &n, &k);
  while(k--) { Q.push(0); }
  for ( int i = 0; i < n; ++ i){
    int s, m;
    scanf("%d%d", &s, &m);
    long long tmp = Q.top();
    Q.pop();
    if(s<=tmp) {
      tmp += m;
    } else {
      tmp = s+m;
    }
    Q.push(tmp);
    printf("%lld\n",tmp);
  }
  return 0;
}
