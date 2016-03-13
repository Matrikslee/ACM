#include <cstdio>
#define  max(i,j) ({int _ = (i), __ = (j); _ > __ ? _ : __;})
#define  MAX_LEN 111

int main(int argc, char const *argv[])
{
	int n, ans = 0, a[MAX_LEN]={0};
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a+i);
	}
	if(n<3 || n%2==0){
		printf("-1");
	} else {
		for(int i = n/2; i > 0; --i){
			int tmp  = max(a[i*2],a[i*2+1]);
			a[i*2+1] = max(0,a[i*2+1]-tmp);
			a[i*2]   = max(0,a[i*2]-tmp);
			a[i]     = max(0,a[i]-tmp);
			ans += tmp;
		}
		ans += a[1];
		printf("%d", ans);
	}
	return 0;
}