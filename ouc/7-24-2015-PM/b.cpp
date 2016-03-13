#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	for(string s; cin>>s; ){
		int len = s.length();
		int multi[100] = {0}, tmp = 0;
		bool isCyclic = true;
		for(int i=0; i<len; ++i){
			int mul = (s[len-i-1]-'0')*(len+1)+tmp;
			if(mul%10!=9){
				isCyclic = false;
				break;
			}
			tmp = mul/10;
		}
		if(isCyclic){
			cout << s << " is cyclic" << endl;
		} else {
			cout << s << " is not cyclic" << endl;
		}
	}
	return 0;
}