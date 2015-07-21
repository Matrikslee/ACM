#include <cstdio>

int main(int argc, char const *argv[]){
	int cnt[10] = {0}, n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	if( cnt[5] || cnt[7] ){
		printf("-1\n");
	}else if(cnt[1]-cnt[4]-cnt[3]<0){
		printf("-1\n");
	} else if(cnt[1]==cnt[2]+cnt[3]&&cnt[1]==cnt[4]+cnt[6]){
		for(; cnt[4]--;--cnt[2],printf("1 2 4\n"));
		for(; cnt[2]--;--cnt[6],printf("1 2 6\n"));
		for(; cnt[6]--;--cnt[3],printf("1 3 6\n"));
	} else {
		printf("-1\n");
	}
	return 0;
}