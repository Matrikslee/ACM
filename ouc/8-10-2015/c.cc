#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	for(static char s[222]; gets(s); ) {
		char c;
		double num[222] = {0};
		int len = strlen(s), p = 0, i = 0, x;
		if ( len<3 && s[0]=='0' ) { break; }
		for ( x=0; s[i]>='0'&&s[i]<='9'; x = x*10+s[i++]-'0' );
		for ( num[0] = x; i<len; ++i ) {
			for ( ; i<len && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i] !='/'; ++i );
			for ( c = s[i]; !(s[i]>='0'&&s[i]<='9'); ++i);
			for ( x=0; s[i]>='0'&& s[i]<='9'; x = x*10+s[i++]-'0' );
			if  ( c=='*' ) { num[p]*=x; }
			else if ( c=='/' ) { num[p]/=x; }
			else if ( c=='+' ) { num[++p]=x; }
			else if ( c=='-' ) { num[++p]=-x; }
		}
		double ans;
		for(ans = 0; p>=0; ans+=num[p--]);
		printf("%.2lf\n", ans);
	}
	return 0;
}