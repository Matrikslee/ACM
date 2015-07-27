#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int lmt = 22222;

int main(int argc, char const *argv[]){
	static int p[lmt];
	static bool c[lmt];
	for(int i=2; i<lmt; ++i){
		if(!c[i]) { p[++p[0]] = i; }
		for(int j=1, k=lmt/i; p[j]<=k; ++j){
			c[i*p[j]] = true;
			if(i%p[j]==0) { break; }
		}
	}
	c[1] = c[2] = true;
	for(int x,cnt=1; cin>>x && x>0; ++cnt){
		if(c[x]){
			cout << cnt << ": no" << endl;
		} else {
			cout << cnt << ": yes" << endl;
		}
	}
	return 0;
}