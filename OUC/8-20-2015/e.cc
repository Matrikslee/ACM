#include <iostream>
#include <string.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAXN 2000005

inline int min ( int a , int b ) { return a < b ? a : b ; }

int main(int argc, char const *argv[]) {
	cin.sync_with_stdio(false);
	for ( string ins; cin >> ins && ins!="END"; ) {
		string s = "$#";
		for ( int i = 0, len = ins.length(); i < len; ++ i ) {
			s.push_back(ins[i]);
			s.push_back('#');
		}
		int len = s.length(), pos = 0, nMax = 0, ans = 0;
		static int p[MAXN];
		memset(p, 0x0, sizeof(p));
		for ( int i = 0; i < len; ++ i ) {
			if ( nMax > i ) {
				p[i] = min(p[2*pos-i], nMax-i);
			} else {
				p[i] = 1;
			}
			for ( ; i>=p[i] && i+p[i] < len && s[i+p[i]] == s[i-p[i]] ; ++p[i]);
			if ( p[i] + i > nMax ) {
				nMax = p[i] + i ;
				pos = i ;
			}
			if ( p[i] > ans ) {
				ans = p[i];
			}
		}
		static int cnt = 0;
		cout << "Case " << ++cnt << ": " << ans-1 << endl;
	}
	return 0;
}