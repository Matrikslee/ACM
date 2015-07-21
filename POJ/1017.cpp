#include <cstdio>

int main(int argc, char const *argv[])
{
	const int u[4]={0,5,3,1};
	int a, b, c, d, e, f, rem, ans;
	while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)) {
		if(!a && !b && !c && !d && !d && !e && !f) { break; }
		ans = f+e+d+(c+3)/4;
		rem = d*5+u[c%4];
		b>rem?ans+=(b-rem+8)/9:0;
		rem = (ans-f)*36-e*25-d*16-c*9-b*4;
		a>rem?ans+=(a-rem+35)/36:0;
		printf("%d\n", ans);
	}
	return 0;
}