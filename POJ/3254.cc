#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d", &m, &n);

	const int MAXN = 1111;
	static int p[MAXN]; // p存储所有的可行状态
	int k = 1 << n, pos = 0; // pos是可行状态的数量
	// 预处理所有的单行可行状态(压缩状态)
	for ( int i = 0; i < k; ++ i )
	{
		if ( !(i & (i<<1)) )
		{
			p[pos++] = i;
		}
	}

	// 读入矩阵
	int h[15] = {0};
	for ( int i = 0; i < m; ++ i )
	{
		for ( int j = 0; j < n; ++ j )
		{
			scanf("%d", &k);
			h[i] += k << j;  // 求第i行的状态h[i]
		}
	}

	// 特殊处理第一行的DP值
	static int dp[15][MAXN];
	for ( int j = 0; j < pos; ++ j )
	{
		dp[0][j] = ( (h[0] & p[j]) == p[j]) ? 1 : 0;
	}

	const int MOD = 100000000;

	// DP求2~n-1行的值
	for ( int i = 1; i < m; ++ i )
	{
		for ( int j = 0; j < pos; ++ j )
		{
			if ( (h[i] & p[j]) != p[j] ) // 如果h[i]不是p[j]的子集 则状态p[j]不可行
			{
				continue;
			}
			for ( int k = 0; k < pos; ++ k )
			{
				if ( dp[i-1][k] && (p[k]&p[j])==0 ) // 判断状态p[k]和状态p[j]是否冲突
				{
					dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
				}
			}
		}
	}

	int ans = 0;
	for ( int j = 0; j < pos; ++ j )
	{
		if ( dp[m-1][j] )
		{
			ans = (ans + dp[m-1][j]) % MOD;
		}
	}

	printf("%d\n", ans);

	return 0;
}