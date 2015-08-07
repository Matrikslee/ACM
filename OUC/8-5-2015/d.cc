#include <stdio.h>

int main(int argc, char const *argv[]){
	int T; for(scanf("%d", &T); T; --T){
		int a, b, x=1, y=1; scanf("%d%d", &a, &b);
		for(int i=2; i*i<=a; ++i){
			if(a%i==0){ x += i+a/i; }
			if(i*i==a){ x -= i;	}
		}
		for(int i=2; i*i<=b; ++i){
			if(b%i==0){ y += i+b/i; }
			if(i*i==b){ y -= i;	}
		}
		if( x==b && y==a ){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}