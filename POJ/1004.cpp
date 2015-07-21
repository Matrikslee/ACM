#include <cstdio>

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	float x, sum = 0;
	for(int i = 0; i < 12; ++i){
		scanf("%f", &x);
		sum += x;
	}
	printf("$%.2f\n", sum/12);
}
