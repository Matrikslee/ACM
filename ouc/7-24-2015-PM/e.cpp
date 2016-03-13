#include <iostream>
#include <string>
#define MAXN 111
using std::cin;
using std::cout;
using std::endl;
using std::string;

void solve(string &s, int num, int val){
	string t, tt;
	int len = s.length(), pos = 0;
	for(int i=0; i<len; ++i){
		if( (s[i]>='a'+9*num && s[i]<='i'+9*num) || (num==2&&s[i]=='_')){
			t.push_back(s[i]), s[i] = '*';
		}
	}
	tt = t; len = t.length();
	for(int i=0; i<len; ++i){
		tt[(i+val)%len] = t[i];
	}
	len = s.length(), pos = 0;
	for(int i=0; i<len; ++i){
		if(s[i]=='*'){
			s[i] = tt[pos++];
		}
	}
}

int main(int argc, char const *argv[]){
	for(int k[3]; cin>>k[0]>>k[1]>>k[2]; ){
		if(k[0]==0 && k[1]==0 && k[2]==0){
			break;
		}
		string s; cin >> s;
		for(int i=0; i<3; ++i){
			solve(s, i, k[i]);
		}
		cout << s << endl;
	}
	return 0;
}