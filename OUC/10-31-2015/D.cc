#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	const int MAXN = 1111;
	static int a[MAXN];
	for ( int i = 0; i < n; ++ i )
	{
		scanf("%d", a+i);
	}
	static int f[MAXN];
	int ans = f[0] = 1;
	for ( int i = 1; i < n; ++ i )
	{
		int maxL = 0;
		for ( int j = 0; j < i; ++ j ) 
		{
			if ( a[i] > a[j] && maxL < f[j] )
			{
				maxL = f[j];
			}
		}
		f[i] = maxL + 1;
		if ( f[i]>ans )
		{
			ans = f[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}