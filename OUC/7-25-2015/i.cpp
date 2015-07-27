#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	int T; for(cin>>T; T;--T){
		bool yes = true;
		string s;
		cin >> s;
		if(s[0]!='M'){ yes=false; }
		else {
			int len = s.length(), ans=0;
			for(int i=1; i<len; ++i){
				if(s[i]=='M'){
					yes = false;
					break;
				} else if(s[i]=='I'){
					ans++;
				} else if(s[i]=='U'){
					ans+=3;
				}
			}
			if(ans!=1 && ans%2!=0 || ans%3==0){
				yes = false;
			}
		}
		if(yes){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}