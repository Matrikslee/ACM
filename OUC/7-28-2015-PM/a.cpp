#include <iostream>

typedef long long int64;
using std::cin;
using std::cout;
using std::endl;

int64 ex_gcd(int64 a, int64 b, int64 &x, int64 &y){
	int64 ans = 1;
	if(b==0){
		ans = a, x = 1, y =0;
	} else {
		ans = ex_gcd(b,a%b,x,y);
		int64 temp = x; x = y;
		y = temp - a/b*y;
	}
	return ans;
}

int main(int argc, char const *argv[]){
	int64 x, y, m, n, l, ans, ansx, ansy;
	cin >> x >> y >> m >> n >> l;
	int64 c = m-n, len = y-x;
	if( c<0 ) { c*=-1, len*=-1; }
	ans = ex_gcd(c, l, ansx, ansy);
	if( len%ans ==0 ){
		ansx = (ansx*len/ans%l+l)%l;
		cout << ansx << endl;
	} else {
		cout << "Impossible" << endl;
	}
	
	return 0;
}