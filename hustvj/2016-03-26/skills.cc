#include <stdio.h>

int main() {
  int n; scanf("%d\n", &n);
  for (int i = 0; i < n; ++i){
    int x = 0, cnt = 0, flag = -1, ipv6[8] = {0};
    for ( char c, pre=0; c=getchar(), c>='0'&&c<='9'||c>='a'&&c<='f'||c==':'; pre = c) {
      if( c>='0'&&c<='9'){ x = x*16+c-'0'; }
      if( c>='a'&&c<='f'){ x = x*16+c-'a'+10; }
      if( c==':' ){
        if(pre!=':') { ipv6[cnt++] = x; }
        else { flag = cnt; }
        x = 0;
      }
    }
    ipv6[cnt] = x;
    if(flag!=-1){
      for ( int i = 0; i < flag; ++i) {
        printf("%04x:", ipv6[i]);
      }
      for ( int i = 0; i < 8-cnt-1; ++i ) {
        printf("0000:");
      }
    }
    for ( int i = flag==-1?0:flag; i < cnt; ++i){
      printf("%04x:", ipv6[i]);
    }
    printf("%04x\n", ipv6[cnt]);
  }
  return 0;
}
