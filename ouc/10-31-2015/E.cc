#include <stdio.h>
#include <string.h>

inline int max(int a, int b)
{
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	double T; int N;
	while(~scanf("%lf%d", &T, &N) && N!=0)
	{
		int number = 0;
		const int MAXN = 33;
		int maxV = int(T*100);
		int Receipt[MAXN] = {0};
		for ( int i = 0; i < N; ++i )
		{
			int n;
			scanf("%d\n", &n);
			bool isOK = true;
			double sum = 0;
			int W[3] = {0};
			for ( int i = 0; i < n; ++i )
			{
				char c; double w;
				scanf("%c:%lf\n", &c, &w);
				if( (c>='A' && c<='C') )
				{
					W[c-'A'] += w;
					sum += w;
				} else {
					isOK = false;
					break;
				}
			}
			if( isOK && 1000-sum>=0 && 600-W[0]>=0 && 600-W[1]>=0 && 600-W[2]>=0 )
			{
				Receipt[++number] = int(sum*100);
			}
		}
		const int MAXW = 3111111;
		static int dp[MAXW];
		memset(dp, 0x0, sizeof(dp));
		for ( int i = 1; i <= number; ++i )
		{
			for ( int v = maxV; v>=Receipt[i]; --v )
			{
				dp[v] = max(dp[v], dp[v-Receipt[i]]+Receipt[i]);
			}
		}
		printf("%.2lf\n", 1.0*dp[maxV]/100);
	}
	return 0;
}