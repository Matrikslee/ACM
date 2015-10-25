#include <stdio.h>
#define MAXN 211111

int main(int argc, char const *argv[])
{
	int T, cnt = 1;
	for ( scanf("%d", &T); cnt <= T; ++cnt )
	{
		printf("Case #%d:\n", cnt);
		int Q, M;
		scanf("%d%d", &Q, &M);
		static int px[MAXN], ox[MAXN];
		int len = 1; 
		for ( ; len < Q; len *= 2 );
		for ( int i = 1; i <= len + Q; ++ i ) 
		{
			px[i] = ox[i] = 1;
		}
		for ( int i = 1; i <= Q; ++ i )
		{
			int o, x;
			scanf("%d%d", &o, &x);
			if ( o == 1 )
			{
				px[len+i] = x;
				for ( int now = len+i; now > 0; now/=2 )
				{
					ox[now] = px[now];
					int lson = now * 2, rson = lson + 1;
					if ( lson <= len+Q ) 
					{
						ox[now] = ox[now] * ox[lson] % M;
					}
					if ( rson <= len+Q ) 
					{
						ox[now] = ox[now] * ox[rson] % M;
					}
				}
			}
			if ( o == 2 )
			{
				px[len + x] = 1;
				for ( int now = len + x; now > 0; now/=2 )
				{
					ox[now] = px[now];
					int lson = now * 2, rson = lson + 1;
					if ( lson <= len+Q ) 
					{
						ox[now] = ox[now] * ox[lson] % M;
					}
					if ( rson <= len+Q ) 
					{
						ox[now] = ox[now] * ox[rson] % M;
					}

				}
			}
			printf("%d\n", ox[1]);
		}
	}
	return 0;
}