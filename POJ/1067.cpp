#include <cstdio>
#include <cmath>

inline int min(int a, int b)
{ return a<b?a:b; }

inline int abs(int a)
{ return a>0?a:-a; }

int main(int argc, char const *argv[])
{
	const double q = (sqrt(5.0)+1)/2.;
	for(int a, b; ~scanf("%d%d", &a, &b); ){
		int k = abs(b-a);
		if( min(a,b)==(int)(k*q) ){
			printf("0\n");
		} else {
			printf("1\n");
		}
	}
	return 0;
}