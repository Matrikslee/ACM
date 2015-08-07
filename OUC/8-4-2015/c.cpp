#include <iostream>
#include <string.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAXN 111

inline int min(int a, int b) { return a<b?a:b; }

inline int islowcase(char c) { return c>='a'&&c<='z'?1:0; }

int main(int argc, char const *argv[]){
	int T; for(cin>>T; T; --T){
		static int f[MAXN][2];
		memset(f, 0xf, sizeof(f));
		string s; cin >> s;
		int len = s.length();
		f[0][0] = 0; f[0][1] = 1;
		for(int i=0; i<len; ++i){
			int t = islowcase(s[i]);
			f[i+1][1] = min(f[i+1][1], f[i][0]+2+t);
			f[i+1][1] = min(f[i+1][1], f[i][1]+1+t);
			f[i+1][0] = min(f[i+1][0], f[i][1]+2+!t);
			f[i+1][0] = min(f[i+1][0], f[i][0]+1+!t);
		}
		int ans = min(f[len][0], f[len][1]+1);
		cout << ans << endl;
	}
	return 0;
}