#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int p = 9973;

int main(int argc, char const *argv[]){
	int T;for(cin>>T; T; --T){
		unsigned long long B;
		int n;
		cin >> n >> B;
		B %= p;
		for(long long ans=1; ans<=p; ++ans){
			if((ans*B)%p==n){
				cout << ans << endl;
				break;
			}
		}
	}
	return 0;
}