#include <cstdio>
#include <cstring>
#define MAXN 30
#define INF (1<<20)

inline int min(int a, int b){return a<b?a:b;}

int main(int argc, char const *argv[]){
	char s[MAXN],t[MAXN];
	while(~scanf("%s", s)){
		int n = strlen(s);
		for(int i=0; i<n; ++i){
			t[i] = s[i] -= '0';
		}
		int ans = INF, num=0;
		//第一位不翻
		for(int i=1; i<n; ++i){
			if(s[i-1]){
				s[i-1]=!s[i-1];s[i]=!s[i];s[i+1]=!s[i+1];
				++num;
			}
		}
		if(!s[n-1]){ ans = min(ans,num); }
		//第一位翻
		t[0] = !t[0], t[1]=!t[1], num = 1;
		for(int i=1; i<n; ++i){
			if(t[i-1]){
				t[i-1]=!t[i-1];t[i]=!t[i];t[i+1]=!t[i+1];
				++num;
			}
		}
		if(!t[n-1]){ ans = min(ans,num); }
		ans==INF||n==1?printf("NO\n"):printf("%d\n", ans);
	} 
	return 0;
}