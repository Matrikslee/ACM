#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	for(int n; cin>>n; ){
		int x = n/2, y = n-x;
		cout << (x*(x-1)+y*(y-1))/2 << endl;
	}
	return 0;
}