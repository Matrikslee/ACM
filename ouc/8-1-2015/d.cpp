#include <stdio.h>
#include <queue>

#define MAXN 65535

struct node{
	node* prev;
	int state, dis, x, y;
	node():state(0), dis(0), prev(NULL), x(0), y(0){}
	node(int s, int d, node* p):state(s), dis(d), prev(p), x(0), y(0){}
	node(int s, int d, node* p, int xx, int yy):state(s), dis(d), prev(p), x(xx), y(yy){}
};

void output(const node* p, int start);

int main(int argc, char const *argv[]){
	int start = 0;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if('+'==getchar()){
				start |= 1<<(i*4+j);
			}
		}
		getchar();
	}
	static bool vis[MAXN+10];
	static node Q[MAXN], *head=Q, *tail=Q;
	for(*tail++ = node(start,0,0), vis[start]=true; head!=tail; ++head){
		node* now = head;	
		if(now->state==0){
			break;
		}
		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				int dis = now->dis+1;
				int ch = now->state^1<<i*4+j;
				for(int k=0; k<4; ++k){
					ch = ch^1<<k*4+j;
					ch = ch^1<<i*4+k;
				}
				if(!vis[ch]){
					*tail++ = node(ch,dis,head,i,j);
					vis[ch] = true;
				}
			}
		}
	}
	output(head, start);
	return 0;
}

void output(const node* p, int start){
	// printf("%04X\n", p->state);
	static int ans;
	if(p->state != start){
		++ans;
		output(p->prev, start);
		printf("%d %d\n", p->x+1, p->y+1);
	} else {
		printf("%d\n", ans);
	}
}