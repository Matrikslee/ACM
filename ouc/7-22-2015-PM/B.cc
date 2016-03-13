#include <cstdio>
#include <queue>
typedef unsigned long long uint64;

uint64 bfs(int n){
	uint64 ans;
	std::queue<uint64> q;
	for(;!q.empty();q.pop());
	for(q.push(1);!q.empty();){
		uint64 p = q.front(); q.pop();
		if(p%n==0) {
			ans = p;
			break;
		}
		q.push(p*10);
		q.push(p*10+1);
	}
	return ans;
}

int main(int argc, char const *argv[]){
	for(int n;~scanf("%d", &n) && n!=0; ){
		uint64 ans = bfs(n);
		printf("%llu\n", ans);
	}
	return 0;
}