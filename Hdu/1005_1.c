#include <stdio.h>
#define MOD 7

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int a, b, n, i, F, f[60];
	while(scanf("%d%d%d", &a, &b, &n), (a||b||n))
	{
		f[1] = f[2] = 1;
		for(i = 3; i < 50; i++)
			f[i] = (a*f[i-1] + b*f[i-2]) % MOD;
		printf("%d\n",f[n%49]);
	}
	return 0;
}