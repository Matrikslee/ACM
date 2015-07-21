#include <cstdio>

int main(int argc, char const *argv[])
{
	int t;
	for(scanf("%d", &t);t; --t){
		int n, p[100];
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d", p+i);
		}
		bool bracket[100];
		int  len = 0, leftnum = 0;
		for(int i=0; i<n; ++i){
			while(leftnum<p[i]){
				bracket[len] = false;
				++leftnum;
				++len;
			}
			bracket[len++] = true;
		}
		int w[100], wlen = 0;
		int stack[100], top = 0;
		for(int i=0; i<len; ++i){
			if(bracket[i]){
				int cnt = 0;
				int left = stack[--top];
				for(int j=i; j>=left; --j){
					if(!bracket[j]) {
						++cnt;
					}
				}
				w[wlen++] = cnt;
			} else {
				stack[top++]=i;
			}
		}
		for(int i=0; i<wlen; ++i){
			printf("%d ", w[i]);
		} 
		printf("\n");
	}
	return 0;
}