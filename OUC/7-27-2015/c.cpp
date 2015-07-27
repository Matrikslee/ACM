#include <iostream>

const int lmt = 1111;

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	static int p[lmt];
	for(int i=2; i<lmt; ++i){
		if(!p[i]) { p[++p[0]] = i; }
		for(int j=1, k=lmt/i; p[j]<=k; ++j){
			p[i*p[j]] = true;
			if(i%p[j]==0) { break; }
		}
	}
	p[0] = 1;
	for(int n,c,pos; cin>>n>>c; ){
		for(pos=1; p[pos]<=n; ++pos);
		cout << n << " " << c << ":";
		c = pos&1?2*c-1:2*c;
		c = c<pos?c:pos;
		pos = (pos-c)/2;
		for(int i=pos; i<pos+c; ++i){
			cout << " " << p[i];
		}
		cout << endl << endl;
	}
	return 0;
}