#include <iostream>
#include <string>
#include <string.h>

typedef long long LINT;

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define lowbit(o) ({int _=o; _&(~_+1);})

void add(LINT *bint, int pos, int value, int lmt){
	while(pos>0 && pos<lmt){
		bint[pos] += value;
		pos += lowbit(pos);
	}
}

LINT sum(LINT *bint, int pos, int lmt){
    LINT ans = 0;
    while(pos > 0 && pos < lmt){
        ans += bint[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

int main(int argc, char const *argv[]){
	int T,c=1; for(cin>>T; c<=T; ++c){
		int n; cin >> n;
		static LINT A[55555];
		memset(A,0x0,sizeof(A));
		for(int i=0; i<n; ++i){
			int x; cin >> x;
			add(A, i+1, x, n+1);
		}
		cout << "Case " << c << ":" << endl;
		for(string a; cin>>a; ){
			if(a=="End"){
				break;
			} else if(a=="Query"){
				int l, r;
				cin >> l >> r;
				cout << sum(A,r,n+1)-sum(A,l-1,n+1) << endl;
			} else if(a=="Add"){
				int x,y; cin >> x >> y;
				add(A,x,y,n+1);
			} else if(a=="Sub"){
				int x,y; cin >> x >> y;
				add(A,x,-1*y,n+1);
			}
		}
	}
	return 0;
}