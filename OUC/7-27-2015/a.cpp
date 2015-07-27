#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	int T;	for(cin>>T; T; --T){
		long long x,ans=0;
		for(cin >> x; x!=0; ans += x/=5);
		cout << ans << endl;
	}
	return 0;
}