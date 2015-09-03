#include <cstdio>
#define abs(x) ({(x)<0?-(x):(x);})
#define max(i,j) ({int _ = (i), __ = (j); _ > __ ? _ : __;})

int main(int argc, char const *argv[])
{
	char ch; 
	int inside = 0, outside = 0, ans = 0;
	while(scanf("%c", &ch) != EOF && (ch == '-'||ch=='+')){
		if(ch == '+') { 
			inside++;
			if(outside>0) { outside--; }
			else { ans++; }
		}else {
			outside++;
			if(inside>0) { inside--; }
			else { ans++; }
		}
	}
	printf("%d", ans);
	return 0;
}