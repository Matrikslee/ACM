#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	for( string s; cin>>s; ){
		int ans = 0;
		for(int i=0, len=s.length(); i<len; ++i){
			if( s[i]=='(' ) { ++ans; }
			if( s[i]==')' ) { --ans; } 
			if( s[i]=='B' ) { break; }
		}
		cout << ans << endl;
	}
	return 0;
}