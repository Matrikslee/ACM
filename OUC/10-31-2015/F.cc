#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int MAXN = 32888;
	int value[3] = {1, 2, 3};
	static int dp[MAXN] = {1};
    for ( int i = 0; i < 3; ++i )
    {
    	for ( int j = value[i]; j < MAXN; ++j )
    	{
    	    dp[j] += dp[j - value[i]];
    	}
    }
    int n;
    while( ~scanf("%d", &n) )
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}