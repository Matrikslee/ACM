#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	long a, b;
	while(scanf("%ld%ld", &a, &b) != EOF)
		printf("%ld\n", a+b);
	return 0;
}
