#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int M = 21252;
const int m[] = {5544,14421,1288};

int main(int argc, char const *argv[]){
	for(int p,e,i,d,c=1; cin>>p>>e>>i>>d; ++c){
		if(p==e && e==i && i==d && d==-1){ break; }
		long long ans = (p*m[0]+e*m[1]+i*m[2]-d+M-1)%M+1;
		cout << "Case " << c <<": the next triple peak occurs in "<< ans << " days." << endl;
	}
	return 0;
}