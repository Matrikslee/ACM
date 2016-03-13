#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void run(int t, int p, int q, int pre = 0);

const int N = 100001;
vector<int> g[N];
vector<int> v;
int f[N];

int main(int argc, char** argv){
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; ++i){
    cin >> f[i+1];
  }
  for (int i = 0; i < n && cin; ++i){
    int x;
    cin >> x;
    f[i+1] ^= x;
  }

  v.clear();
  run(1,0,0);

  int len = v.size();
  cout << len << endl;
  for (int i = 0; i < len; ++i) {
    cout << v[i] << endl;
  }
  return 0;
}

void run(int n, int p, int q, int pre){
  if( p^f[n] ){
    v.push_back(n);
    p ^= 1;
  }
  for ( int i = 0, l = g[n].size(); i < l; ++ i){
    if( g[n][i] != pre ) {
      run(g[n][i], q, p, n);
    }
  }
}
