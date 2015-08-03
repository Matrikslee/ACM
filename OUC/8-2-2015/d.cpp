#include <stdio.h>

int ans(const int f[][3], int n){
	int num[10], len=0, ans=0;
	for(int x=n; x!=0; num[len++]=x%10, x/=10);
	for(int i=len-1,flag=0; i>=0; --i){
		if( flag ){
			ans += num[i]*(f[i][2]+f[i][0]*flag);
		} else {
			ans += num[i]*f[i][2]+f[i][0]*((num[i]>4)+(num[i]>2&&num[i+1]==6));
		}
		flag = flag||(num[i]==4 || num[i]==2&&num[i+1]==6);
	}
	return n-ans;
}

int main(int argc, char const *argv[]){
	int f[10][3] = {1};
	for(int i=1; i<7; ++i){
		f[i][0] = f[i-1][0]*9-f[i-1][1];
		f[i][1] = f[i-1][0];
		f[i][2] = f[i-1][0]+f[i-1][1]+f[i-1][2]*10;
	}
	for(int l, r; ~scanf("%d%d", &l, &r)&&(l+r); printf("%d\n", ans(f,r)-ans(f,l-1)));
	return 0;
}