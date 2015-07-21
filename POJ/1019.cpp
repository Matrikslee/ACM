#include <cstdio>
#include <cmath>
#define MAX_NUM 32000

int calc(int len, int pos);

int main(int argc, char const *argv[])
{
	long long a[MAX_NUM]={0,1}, b[MAX_NUM]={0,1};
	for(int i=2; i<MAX_NUM; ++i){
		a[i]=a[i-1]+(int)log10(1.*i)+1;
		b[i]=b[i-1]+a[i];
	}
	int t;
	scanf("%d", &t);
	while(t--){
		long n,cnt=0;
		scanf("%ld", &n);
		while(b[cnt+1]<n) { ++cnt; }
		printf("%d\n", calc(cnt+1,n-b[cnt]));
	}
	return 0;
}

int calc(int len, int pos)
{
	int cnt=1;
	while(cnt<len&&pos>0){
		int tmp = (int)log10(1.*cnt)+1;
		if(tmp>=pos){
			while(pos<tmp--){ cnt/=10; }
			return cnt%10;
		}else { pos-=tmp; ++cnt; }
	}
	return len%10;
}