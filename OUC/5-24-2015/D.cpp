#include <cstdio>
#define MAXN 111111

inline int min(int a, int b) { return a<b?a:b; }

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d%d", &n, &k);
	int  dis[MAXN] = {0};
	bool vis[MAXN] = {false};
	int  queue[MAXN], head=0, tail=0;
	queue[tail++] = n; vis[n] = true;
	while(head<tail){
		int curpoint = queue[head++];
		int curdis   = dis[curpoint];
		if(curpoint-1>=0 && !vis[curpoint-1]){
			queue[tail++] = curpoint-1;
			dis[curpoint-1] = curdis+1;
			vis[curpoint-1] = true;
			if(curpoint-1==k) { break; }
		}
		if(curpoint+1<MAXN && !vis[curpoint+1]){
			queue[tail++] = curpoint+1;
			dis[curpoint+1] = curdis+1;
			vis[curpoint+1] = true;
			if(curpoint+1==k) { break; }
		}
		if(curpoint*2<MAXN && !vis[curpoint*2]){
			queue[tail++] = curpoint*2;
			dis[curpoint*2] = curdis+1;
			vis[curpoint*2] = true;
			if(curpoint*2==k) { break; }
		}
	}
	printf("%d\n", dis[k]);
	return 0;
}