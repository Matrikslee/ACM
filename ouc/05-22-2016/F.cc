#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(){
  string name, parten;
  cin>>name;
  cin>>parten;
  int head = 0, tail = 0;
  int name_len = name.size();
  int parten_len = parten.size();
  for( int i = 0, p = 0; i < parten_len; ++ i){
    if(name[p]==parten[i]) { ++p; }
    if(p==name_len) { head=i; break; }
  }
  for( int i = parten_len, p = name_len; i > 0; -- i) {
    if(name[p-1]==parten[i-1]) { --p; }
    if(p==0) { tail = i; break;}
  }
  int ans = tail-head-1;
  cout << (ans<=0?0:ans);
}
