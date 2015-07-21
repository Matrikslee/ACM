#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX_LEN 777777

using namespace std;

struct tire {
	tire *child[10];
	char str[10];
	int num;
};

const char map[26] = {'2','2','2','3','3','3','4','4','4',
					  '5','5','5','6','6','6','7','7','7',
					  '7','8','8','8','9','9','9'};

tire root[MAX_LEN], *pbuf = root;
bool flag = false;

void ins	(char* s );
void output (tire* rt);
void dispose(char* s );

int main(int argc, char const *argv[])
{
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int  n;
	char s[200];
	for(scanf("%d\n", &n); n--;){
		gets(s);
		dispose(s);
		ins(s);
	}
	if( flag == true ){
		output(root);
	} else 
		cout << "No duplicates. ";

	return 0;
}

void ins(char *s)
{
	tire* ptr = root;
	char* pst = s;
	for(; *pst != '\0'; ) {
		int ch = *pst++ - '0';
		if( ptr->child[ch] == NULL )
			ptr->child[ch] =  ++pbuf;
		ptr = ptr->child[ch];
	}

	strcpy(ptr->str, s);
	ptr->str[3] = '-';
	strcpy(ptr->str+4, s+3);

	if( ++ptr->num > 1 )
		flag = true;
}

void dispose(char *s)
{
	char b[200], *p = s, *pb = b;

	for( ; *p; ++p) {
		if( *p == '-' ) continue;
		if( *p >= 'A' && *p <= 'Z')
			*pb++  = map[*p-'A'];
		else *pb++ = *p;
	}
	*pb = '\0';

	strcpy(s, b);
}

void output(tire *rt)
{
	if( rt ) {
		for (int i = 0; i < 10; ++i){
			output(rt->child[i]);
		}
		if(rt->num > 1) {
			printf("%s %d\n", rt->str, rt->num);
		}
	}
}