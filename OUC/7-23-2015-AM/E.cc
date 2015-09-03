#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
	int s,t; cin>>s>>t;
	if(s==1){
		cout << 1 << endl;
	} else {
		int ans;
		double min = 1e10;
		for(int x=t; x>=s; --x){
			int seg = (int)sqrt(x)+1;
			int numerator = 1;
			for(int i=2; i<seg; ++i){
				if(x%i==0){
					numerator += i+x/i;
					// cout << i << " " << x/i << endl;
				}
			}
			if(numerator==1){
				ans = x;
				break;
			} else if(numerator*1./x<min){
				min = numerator*1./(ans=x);
			}
		}
		cout << ans << endl;
	}
	return 0;
}