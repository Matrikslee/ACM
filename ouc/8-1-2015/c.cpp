#include <stdio.h>
#include <queue>

#define MAXN 65535

struct node{
	int state, dis;
	node():state(0), dis(0){}
	node(int s, int d):state(s), dis(d){}
};

int main(int argc, char const *argv[]){
	int start = 0;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if('b'==getchar()){
				start |= 1<<(i*4+j);
			}
		}
		getchar();
	}
	int ans = -1;
	std::queue<node> q;
	static bool vis[MAXN+10];
	for(; !q.empty(); q.pop());
	for(q.push(node(start,0)),vis[start]=true; !q.empty(); q.pop()){
		node now = q.front();
		if(now.state==0 || now.state==MAXN){ 
			ans = now.dis;
			break;
		}
		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				int dis = now.dis+1;
				int ch = now.state^(1<<(i*4+j));
				if(i>0){ ch = ch^(1<<((i-1)*4+j)); }
				if(j>0){ ch = ch^(1<<(i*4 + j-1)); }
				if(i<3){ ch = ch^(1<<((i+1)*4+j)); }
				if(j<3){ ch = ch^(1<<(i*4 + j+1)); }
				if(!vis[ch]){
					q.push(node(ch,dis));
					vis[ch] = true;
				}
			}
		}
	}
	if(ans!=-1){
		printf("%d\n", ans);
	} else {
		printf("Impossible\n");
	}
	return 0;
}