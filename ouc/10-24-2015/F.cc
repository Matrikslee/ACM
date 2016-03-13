#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

const int MAXN = 22;
const int MAXM = 1111;

int dp[MAXM][MAXN];
int value[MAXN], weight[MAXN];

int max(int a, int b);

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		for ( int i = 0; i < N; ++ i) 
		{
			cin >> value[i] >> weight[i];
		}
		int maxW;
		cin >> maxW;
		memset(dp, 0x0, sizeof(dp));
		for ( int i = 0; i < N; ++ i)
		{
			for ( int j = maxW; j >= weight[i]; --j )
			{
				for ( int k = K; k > 0; -- k )
				{
					dp[j][k] = max(dp[j][k], dp[j-weight[i]][k-1]+value[i]);
				}
			}
		}
		cout << dp[maxW][K] << endl;
	}
	return 0;
}

inline int max(int a, int b)
{
	return a>b?a:b;
}