#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max;
char max_str[20];

struct Node{
	int num;
	struct Node *next[26];
};

struct Node tr[1111], *pbuf=tr;

void ins(char *s)
{
	struct Node *hbuf = tr;
	char *ps;
	for(ps = s; *ps; ps++){
		int x = *ps-'a';
		if(hbuf->next[x]==0)
			hbuf->next[x] = ++pbuf;
		hbuf = hbuf->next[x];
	}
	if(++hbuf->num > max) {
		max = hbuf->num;
		strcpy(max_str, s);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(1){
		int n, i;
		char s[20];
		scanf("%d",&n);
		if(n == 0) break;
		pbuf = tr; max = 0;
		memset(tr, 0, sizeof(tr));
		for(i = 0; i < n; i++){
			scanf("%s", s);
			ins(s);
		}
		printf("%s\n", max_str);
	}
}