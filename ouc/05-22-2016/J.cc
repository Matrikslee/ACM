#include <stdio.h>
#include <vector>

using std::vector;

int main(){
  int n,m,k,q;
  scanf("%d%d%d%d", &n,&m,&k,&q);
  vector<int> col(n+1),row(m+1);
  for(int i = 0; i < k; ++ i) {
    int x, y;
    scanf("%d%d",&x,&y);
    col[x] = 1;
    row[y] = 1;
  }
  for(int i = 1; i < n; ++ i) {
    col[i] += col[i-1];
  }
  for(int i = 1; i < m; ++ i) {
    row[i] += row[i-1];
  }
  for(int i = 0; i < q; ++ i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    bool check_col = (col[x2]-col[x1-1]==x2-x1+1);
    bool check_row = (row[y2]-row[y1-1]==y2-y1+1);
    if(check_col&&check_row) printf("YES\n");
    else printf("NO\n");
  }
}
