#include <stdio.h>

const unsigned long long MOD = 1000000000000000;

int main(int argc, char const *argv[]){
	for(int i=1; i<20; ++i){
		long long x = 1;
		for(int j=0; j<i; ++j,x*=i,x%=MOD);
		for(;x>=10;x/=10);
		printf("%d\n", x);
	}
	return 0;
}