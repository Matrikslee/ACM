#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

const int MAXN = 1111;

int h[MAXN], l[MAXN], r[MAXN];

int max(int a, int b);

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N, ans;
		cin >> M >> N;
		memset(h, 0x0, sizeof(h));
		h[0] = h[N+1] = ans = -1;
		for ( int i = 0; i < M; ++ i )
		{
			for ( int j = 1; j <= N; ++ j ) 
			{
				char c;
				cin >> c;
				h[j] = (c=='F'?h[j]+1:0);
			}
			for ( int j = 1; j <= N; ++ j )
			{
				l[j] = r[j] = j;
			}
			for ( int j = 1; j <= N; ++ j )
			{
				while(h[l[j]-1]>=h[j])
				{
					l[j] = l[l[j]-1];
				}
			}
			for (int j = N; j > 0; -- j )
			{
				while(h[r[j]+1]>=h[j])
				{
					r[j] = r[r[j]+1];
				}
			}
			for (int j = 1; j <= N; ++ j )
			{
				ans = max(ans, h[j]*(r[j]-l[j]+1));
			}
		}
		cout << ans*3 << endl;
	}
	return 0;
}

inline int max(int a, int b)
{
	return a>b?a:b;
}