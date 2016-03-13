#include <iostream>
#include <string.h>

const int MAXN = 222;
const int MAXM = 2222;

using std::cin;
using std::cout;
using std::endl;

int value[MAXM];
int weight[MAXM];
int dp[MAXN];

inline int max(int a, int b)
{
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int T;
	for ( cin>>T; T; --T)
	{
		int n, m, cnt = 0;
		cin >> n >> m;
		for ( int i = 0; i < m; ++ i)
		{
			int v, w, c;
			cin >> v >> w >> c;
			for ( int j = 0; j < c; ++ j )
			{
				weight[cnt] = w;
				value[cnt] = v;
				++cnt;
			}
		}
		memset(dp, 0x0, sizeof(dp));
		for ( int i = 0; i < cnt; ++ i) 
		{
			for ( int j = n; j >= value[i]; -- j )
			{
				dp[j] = max(dp[j], dp[j-value[i]]+weight[i]);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}