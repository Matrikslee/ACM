#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

const int INF = 0x3f3f3f3f;
const int MAXN = 22;
const int MAXM = 1111;

inline int max(int a, int b)
{
	return a>b?a:b;
}

inline int min(int a, int b)
{
	return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	for (int n; cin >> n && n; )
	{
		int g[MAXN] = {0};
		int hire, salary, fire, up = -INF;
		cin >> hire >> salary >> fire;
		for (int i = 1; i <= n; ++i)
		{
			cin >> g[i];
			up = max(up, g[i]);
		}
		static int dp[MAXN][MAXM];
		memset(dp, INF, sizeof(dp));
		dp[1][g[1]] = g[1]*(hire+salary);
		for (int i = 2; i <= n; ++i)
		{
			for (int j = g[i]; j <= up; ++j)
			{
				for (int k = g[i-1]; k <= up; ++k)
				{
					int delta = j*salary+(k>j?fire*(k-j):hire*(j-k));
					dp[i][j] = min(dp[i][j], dp[i-1][k]+delta);
				}
			}
		}
		int ans = INF;
		for (int i = g[n]; i <= up; ++i)
		{
			ans = min(ans, dp[n][i]);
		}
		cout << ans << endl;
	}
	return 0;
}