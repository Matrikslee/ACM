#include <cstdio>

int f[200][200], h[200][200];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int r, c;

int find(int, int);
int max(int, int);

int main(){
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &h[i][j]);

	int ans = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			ans = max(ans, find(i,j));

	printf("%d", ++ans);
}

int find(int x, int y)
{
	if(x < 0 || y < 0 || x >= r || y >= c) return 0;
	if(f[x][y] > 0)  return f[x][y];
	for (int i = 0; i < 4; i++)
		if(h[x + dx[i]][y + dy[i]] > h[x][y])
			f[x][y] = max(f[x][y], find(x + dx[i], y + dy[i]) + 1);
	return f[x][y];
}

int max(int a, int b) { return a > b ? a : b;}