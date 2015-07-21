#include <cstdio>
#include <cstring>
#define  MAX_NUM 11111

struct adj{
	int point;
	adj *next;
} _adj[MAX_NUM*2], *pbuf=_adj;

int  personnum;
adj* head[MAX_NUM];
char name[MAX_NUM][22];

int  find(char const *s);
void link(int a, int b);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		char s[20];
		scanf("%s", s);
		int x = find(s);
		scanf("%s", s);
		int y = find(s);
		link(x,y);
		link(y,x);
	}
	printf("%d\n", personnum);
	for(int i=0; i<personnum; ++i){
		bool vis[MAX_NUM] = {false};
		int  ans = 0, maxfriendnum = 0;
		for(adj* p = head[i]; p!=NULL; p=p->next){
			vis[p->point] = true;
		}
		for(int j = 0; j<personnum; ++j){
			int curfriendnum = 0;
			if(i==j || vis[j]) { continue; }
			for(adj* p = head[j]; p!=NULL; p=p->next){
				if(vis[p->point]){ curfriendnum++; }
			}
			if(curfriendnum==maxfriendnum) { ans++; }
			else if(curfriendnum>maxfriendnum){
				maxfriendnum = curfriendnum;
				ans = 1;
			}
		}
		printf("%s %d\n", name[i], ans);
	}
	return 0;
}

int find(char const *s)
{
	int ans = 0;
	for(; ans<personnum && strcmp(name[ans],s)!=0; ++ans);
	if(ans==personnum) { strcpy(name[personnum++],s); }
	return ans;
}

void link(int a, int b)
{
	if(head[a]==NULL) {
		head[a] = pbuf;
	} else {
		pbuf->next    = head[a]->next;
		head[a]->next = pbuf;
	}
	pbuf++->point = b;
}