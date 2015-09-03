#include <stdio.h>
#include <string.h>
#define MAX_LEN 1100

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, casec=0, f=0, i;
	scanf("%d\n", &n);
	while(n--){
		char a[MAX_LEN], b[MAX_LEN],c[MAX_LEN];
		scanf("%s%s", a, b);
		int la = strlen(a)-1;
		int lb = strlen(b)-1;
		for(i = 0; la>=0 || lb>=0; i++, la--, lb--){
			if(la>=0&&lb>=0) {c[i]=a[la]+b[lb]-'0'+f;}
			if(la>=0&&lb<0) {c[i]=a[la]+f;}
			if(la<0&&lb>=0) {c[i]=b[lb]+f;}
			f = 0; if(c[i]>'9') c[i]-=10,f=1;
		}
		printf("Case %d:\n", ++casec);
		printf("%s + %s = ", a, b);
		if(f==1) putchar('1');
		while(i--) putchar(c[i]);
		if(n) printf("\n\n");
		else printf("\n"); 
	}
	return 0;
}