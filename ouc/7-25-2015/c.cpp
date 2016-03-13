#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	long long x1, y1, x2, y2, n, ans = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for(int i=0; i<n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		long long t1 = a*x1+b*y1+c;
		long long t2 = a*x2+b*y2+c;
		if( (t1>0&&t2<0) || (t1<0&&t2>0) ){ ++ans; }
	}
	cout << ans;
	return 0;
}