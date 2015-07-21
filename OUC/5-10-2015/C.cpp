#include <cstdio>
#define	MAX_LEN 11111

int main(int argc, char const *argv[])
{
	int tot, a, b, aget, bget;
	a = b = aget = bget = 0;
	scanf("%d", &tot);
	for(int i = 0; i < tot; ++i){
		int flag, x ,y;
		scanf("%d%d%d", &flag, &x, &y);
		if(flag == 1){
			aget += x;
			a++;
		} else {
			bget += x;
			b++;
		}
	}
	if(aget*2 >= a*10){
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}
	if(bget*2 >= b*10){
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}
	return 0;
}