#include <stdio.h>
#define MAX_NUM 100011

int num[MAX_NUM];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int s, t; scanf("%d",&t);
	for(s = 0; s < t; s++) {
		int n, i;
		scanf("%d",&n);
		for(i = 0; i < n; i++)
			scanf("%d",num+i);
		int max, sum, sta, end, x, y; 
		sta = end = x = y =0;
		max = sum = num[0]; 
		for(i = 1; i < n; i++){
			if(sum < 0) {
				x = y = i;
				sum = num[i];
			} else {
				y = i;
				sum += num[i];
			}
			if(sum > max){
				max = sum;
				sta = x;
				end = y;
			}
		}
		printf("Case %d:\n", s+1);
		printf("%d %d %d\n", max, sta+1, end+1);
		if(s+1 != t) printf("\n");
	}	
}