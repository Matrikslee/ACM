#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){
  int n;
  cin >> n;
  for ( int i = 0; i < n; ++i){
    int cnt[2] = {0}, point = 0;
    string cur_string="", pre_string="";
    while(cin>>cur_string&&cur_string!="END"){
      if(cur_string==pre_string) {
        point = (point+1)%2;
      }
      pre_string=cur_string;
      ++cnt[point];
    }
    cout << cnt[0]*cnt[1] << endl;
  }
  return 0;
}
