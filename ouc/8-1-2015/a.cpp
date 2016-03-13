#include <stdio.h>

double fabs(double a){ return a<0?-a:a; }

int main(int argc, char const *argv[]){
	for(double a, b; ~scanf("%lf%lf",&a,&b); ){
		if(fabs(a-b)<1e-10){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
