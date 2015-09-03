#include <cstdio>
#define MAXLEN 111111

int main(int argc, char const *argv[])
{
	static char s[MAXLEN], t[MAXLEN];
	while(~scanf("%s%s", s, t)) {
		char *ps=s, *pt=t;
		while(*ps!='\0'&&*pt!='\0'){
			if(*ps==*pt){
				++ps;
			}
			++pt;
		}
		if(*ps=='\0'){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}