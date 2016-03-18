#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int MAXN = 100011;

void dfs(int cur, int pre, int catNumber);

int n,m,ans;
bool haveCat[MAXN];
vector<int> edge[MAXN];

int main(int argc, char* argv[]){
  cin >> n >> m;
  for ( int i = 0, x; i < n; ++i ){
    cin >> x;
    haveCat[i+1] = (x==1);
  }
  for ( int i = 1, x, y; i < n; ++i ){
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, -1, haveCat[1]);
  cout << ans;
  return 0;
}
void dfs(int cur, int pre, int catNumber){
  for ( int i = 0; i < edge[cur].size(); ++ i ){
    int next = edge[cur][i];
    if(next == pre) { continue; }
    if(!haveCat[next]){
      if(edge[next].size() == 1){ ++ans; }
      dfs(next, cur, 0);
    } else if(catNumber+1 <= m) {
      if(edge[next].size() == 1){ ++ans; }
      dfs(next, cur, catNumber+1);
    }
  }
}
