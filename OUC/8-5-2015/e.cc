#include <stdio.h>
#include <string.h>

long long f[33][8];

int main(int argc, char const *argv[]){
	for(int w; ~scanf("%d%d",&w) && ~w; ){
		f[1][0] = 1;
		for(int i=1; i<=w+1; ++i) {
			for(int j=0;j<8; ++j) {
				if( f[i][j]!=0 ){
					
				}
			}
		}
		printf("%lld",f[w+1][0]);
	}
	return 0;
}