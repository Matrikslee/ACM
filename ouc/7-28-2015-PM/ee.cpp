#include <iostream>

typedef unsigned long long uint64;

using std::cin;
using std::cout;
using std::endl;

uint64 gcd(uint64 a, uint64 b){
	return b?gcd(b,a%b):a;
}

int main(int argc, char const *argv[]){
	for(int n; cin>>n; ){
		uint64 ans = 0;
		for(int i=1; i<=n; ++i){
			ans += gcd(i,n);
		}
		cout << n << " " << ans << endl;
	}
	return 0;
}