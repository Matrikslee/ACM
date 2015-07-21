#include <stdio.h>
#define	MAX_LEN 1100000

long num[MAX_LEN];

void swap(long* a, long* b) { int k = *a; *a = *b; *b = k; }
void sort(long a[], int l, int r);

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int m, n, i = 0;
	while(scanf("%d%d", &n, &m) != EOF){
		for(; i < n; ++i){
			scanf("%ld", num+i);
		}
		sort(num, 0, n-1);
		for(i = 0; i < m; i++){
			printf("%ld ", num[i]);
		}
		printf("\n");
	}
	return 0;
}

void sort(long a[], int l, int r)
{
	int i = l, j = r, k = a[(l+r)>>1];
	for(; i < j;) {
		while(a[i] > k) ++i;
		while(a[j] < k) --j;
		if(i <= j) {
			swap(a+i, a+j);
			++i, --j;
		}	
	}
	if(i < r) sort(a, i, r);
	if(j > l) sort(a, l, j);
}