#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main(){
  const char start[] = "heavy", end[] = "metal";
  int pstart = 0, pend = 0;
  long long answer = 0, cnt = 0;
  string s; cin >> s;
  for (int i = 0, l=s.size(); i<l; ++i){
    bool isHeavy = true, isMetal = true;
    for ( int j = 0; j < 5; ++j ){
      if( s[i+j] != start[j] ) { isHeavy = false; }
      if( s[i+j] != end[j] ) { isMetal = false; }
    }
    if( isHeavy ) { ++cnt; }
    if( isMetal ) { answer += cnt; }
  }
  cout << answer;
}
