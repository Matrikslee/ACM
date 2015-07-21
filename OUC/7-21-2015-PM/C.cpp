#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[]){
	int r,h,ans=0;
	scanf("%d%d",&r,&h);
	ans += (h/r)*2, h%=r;
	if(2*h<r){
		ans += 1;
	} else if(2*h<sqrt(3)*r){
		ans += 2;
	} else {
		ans += 3;
	}
	printf("%d\n", ans);
	return 0;
}