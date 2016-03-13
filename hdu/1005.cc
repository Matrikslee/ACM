#include <stdio.h>
#define MOD 7

void calc(int a[][2], int b[][2])
{
	int c[2][2], i, j;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j];
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			a[i][j] = c[i][j] % MOD;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int a, b, n;
	while(scanf("%d%d%d", &a, &b, &n), (a||b||n))
	{
		if(n == 1 || n == 2){
			printf("%d\n", 1);
			continue;
		}
		a %= MOD; b %= MOD;
		int mat[2][2] = {0, b, 1, a};
		int ans[2][2] = {1, 1, 0, 0};
		for(--n; n; n >>= 1){
			if(n&1) calc(ans, mat);
			calc(mat, mat);
		}
		printf("%d\n",ans[0][0]);
	}
	return 0;
}