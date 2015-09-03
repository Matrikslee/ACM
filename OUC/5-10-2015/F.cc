#include <cstdio>
#define	 MAX_LEN 111

int main(int argc, char const *argv[])
{
	int n, x, ans[MAX_LEN] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &x);
			if(x!=-1){
				ans[i] |= x;
				ans[j] |= x;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d ", ans[i]);
	}
	return 0;
}