#include <stdio.h>
#include <string.h>

int max(int a, int b);

int main(int argc, char const *argv[])
{
	int n, m, k, s;
	while(~scanf("%d%d%d%d", &n, &m, &k, &s))
	{
		const int MAXN= 111;
		static int a[MAXN], b[MAXN];
		for ( int i = 1; i <= k; ++ i )
		{
			scanf("%d%d", a+i, b+i);
		}
		//DP
		static int dp[MAXN][MAXN];
		memset(dp, 0x0, sizeof(dp));
		for ( int j = 1; j <= s; ++ j )
		{
			for ( int x = 1; x <= k; ++ x )
			{
				for ( int i = m; i >= b[x]; -- i )
				{
					dp[i][j] = max(dp[i][j], dp[i-b[x]][j-1]+a[x]);
				}
			}
		}
		int i = 0;
		while ( i <= m )
		{
			if( dp[i][s] >= n )
			{
				break;
			}
			++ i;
		}
		int ans = (i>m?-1:m-i);
		printf("%d\n", ans);
	}
	return 0;
}

inline int max(int a, int b)
{
	return a>b?a:b;
}