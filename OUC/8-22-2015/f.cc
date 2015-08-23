#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	for ( int n, m; ~scanf("%d%d", &n, &m); ) {
		double tmp = n, ans = n;
		for ( int i = 1; i < m ;  ++ i ) {
			ans += tmp = sqrt(tmp);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}