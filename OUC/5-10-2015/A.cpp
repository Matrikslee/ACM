#include <cstdio>
#include <cstring>
#define MAX_LEN 5555

int  ans[MAX_LEN][MAX_LEN];
bool is[MAX_LEN][MAX_LEN];

int main(int argc, char const *argv[])
{
	char s[MAX_LEN];
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		ans[i][i] = is[i][i] = true;
	}
	for(int l = 1; l <= len; ++l){
		for(int i = 0; i < len-l; ++i){
			int j = i+l;
			if((l==1||is[i+1][j-1])&&s[i]==s[j]){
				is[i][j] = true;
			}
		}
	}
	for(int l = 1; l <= len; ++l){
		for(int i = 0; i < len-l; ++i){
			int j = i+l;
			ans[i][j] = ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1]+is[i][j];
		}
	}
	int n, l, r;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &l, &r);
		printf("%d\n", ans[l-1][r-1]);
	}
	return 0;
}