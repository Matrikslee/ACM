#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	int n, x;
	cin >> n >> x;
	int cur=0, cnt=0;
	for(int i=0; i<n; ++i){
		int a, b;
		cin >> a >> b;
		for(; cur+x<a; ++cnt, cur+=x);
		cur = b;
	}
	cout << cur-cnt*x;
	return 0;
}