#include <stdio.h>
#include <string.h>

#define N 1000010
char t[2*N] = "$#";
int p[2*N];

inline int min ( int a , int b ) { return a < b ? a : b ; }

int main(int argc, char const *argv[]) {
	while ( true ) {
		int len = 2, pos = 0, ans = 0;
		char c = getchar(), *ps = t + len ;
		if( c == 'E' ) {
			break;
		} else {
			do {
				len += 2;
				* ps ++ = c;
				* ps ++ = '#';
			} while( (c=getchar()) != '\n' );
		}
		*ps = '\0';
		memset(p, 0x0, sizeof(p));
		for ( int i = 0; i < len; ++ i ) {
			if ( pos+p[pos] > i ) {
				p[i] = min(p[2*pos-i], pos+p[pos]-i);
			} else {
				p[i] = 1;
			}
			for ( ; t[i+p[i]] == t[i-p[i]] ; ++p[i]);
			if ( p[i] + i > pos+p[pos] ) {
				pos = i ;
			}
			if ( p[i] > ans ) {
				ans = p[i];
			}
		}
		static int cnt = 0;
		printf("Case %d: %d\n", ++cnt, ans-1);
	}
	return 0;
}