#include <cstdio>
#include <cstring>
#define MAXN 22222

struct node {
	int value;
	node *next[26];
	node(){
		value = 0;
		for(int i=0; i<26; ++i){
			next[i] = NULL;
		}
	}
	~node(){
		for(int i=0; i<26; ++i){
			delete next[i];
		}
	}
};

void insert(node *root, char s[]);
char *get(node *root, char ss[]);

int main(int argc, char const *argv[]) {
	int cnt = 0;
	static char s[MAXN][22];
	node *root = new node();
	for(; ~scanf("%s", s[cnt]); insert(root, s[cnt++]));
	for(int i=0; i<cnt; printf("%s %s\n", s[i], get(root, s[i])), ++i);
	delete root;
	return 0;
}

void insert(node *root, char s[]){
	node *p  = root;
	for(char *ps = s;*ps != '\0'; ++ps){
		int v=*ps-'a';
		if(p->next[v]==NULL){
			p->next[v] = new node();
		}
		p=p->next[v];
		++p->value;
	}
}

char *get(node *root, char ss[]){
	static char st[MAXN];
	node *p  = root;
	for(int i=0, len=strlen(ss); i<len; st[++i]='\0'){
		p = p->next[(st[i]=ss[i])-'a'];
		if( p->value==1 ) {
			st[++i] = '\0';
			break; 
		}
	}
	return st;
}