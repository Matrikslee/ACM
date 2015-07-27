#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int ex_gcd(int a, int b, long long &x, long long &y){
	int ans;
	if(b==0){
		ans = a;
		x = 1, y = 0;
	} else {
		ans = ex_gcd(b,a%b,x,y);
		int t = x;
		x = y, y = t - a/b*y;
	}
	return ans;
}

int main(){
	int T; for(cin>>T; T; --T){
		long long n,B;
		cin >> n >> B;
		long long x, y;
		ex_gcd(B%9973, 9973, x, y);
		cout << (x*n)%9973+9973 << endl;
	}
	return 0;
}