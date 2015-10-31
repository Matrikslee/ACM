#include <stdio.h>
#include <algorithm>
#include <string.h>

using std::lower_bound;

int main(int argc, char const *argv[])
{
	int n, C = 0;
	while(~scanf("%d", &n))
	{
		const int MAXN = 500001;
		const int INF = 0x3f3f3f3f;
		static int dp[MAXN],r[MAXN];
		memset(dp, INF, sizeof(dp));
		for ( int i = 0; i < n; ++i )
		{
			int x,y;
			scanf("%d%d", &x, &y);
			r[x] = y;
		}
		for ( int i = 1; i <= n; ++i )
		{
			*lower_bound(dp, dp+n, r[i]) = r[i];
		}
		int len = lower_bound(dp, dp+n, INF)-dp;
		printf("Case %d:\n", ++C);
		if (len == 1)
		{
			printf("My king, at most 1 road can be built.\n\n");
		} else {
			printf("My king, at most %d roads can be built.\n\n", len);
		}
	}
	return 0;
}