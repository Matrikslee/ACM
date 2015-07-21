#include <cstdio>
#define pi 3.14159265357

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int n, i = 0;
	for(scanf("%d", &n); i < n; ++i){
		double x, y;
		scanf("%lf%lf", &x, &y);
		double r = x*x + y*y;
		double s = pi*r;
		double tmp = 0;
		while(++tmp*100 < s) ;
		printf("Property %d: This property will begin eroding in year %.0f.\n", i+1, tmp);
	}
	printf("END OF OUTPUT.");
	return 0;
}