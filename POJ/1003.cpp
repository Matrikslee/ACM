#include <cstdio>

#define MAX_LEN 333

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	for(double que; scanf("%lf", &que) && que != 0;) {		int cnt = 1;
		for(double sum = 0; sum < que; sum += 1./++cnt);
		printf("%d card(s)\n", cnt-1);
	}

	return 0;
}
