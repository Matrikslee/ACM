#include <cstdio>
#include <cstring>

#define MAX_LEN 5555
#define STR_LEN 55

int num[MAX_LEN], f[MAX_LEN];
char s[MAX_LEN][STR_LEN], t[STR_LEN];

void swap(int* a, int* b);
void trans(char *s, char *t);

int main(int argc, char const *argv[])
{
  int m, n;
  scanf("%d%d\n", &n, &m);
  for(int i = 0; i < m; ++i){
    gets(s[i]);
    trans(s[i], t);
    for(int j = 0; j < n; ++j){
      for(int k = j+1; k < n; ++k){
        if(t[j] > t[k]) num[i]++;
      }
    }
    f[i] = i;
  }
  for(int i = 0; i < m; ++i){
    int k = i;
    for(int j = i; j < m; ++j){
      if(num[f[j]] < num[f[k]])
        k = j;
    }
    swap(f+k, f+i);
  }
  for(int i = 0; i < m; ++i){
    printf("%s\n", s[f[i]]);
  }
  return 0;
}

void swap(int* a, int* b)
{ int k = *a; *a = *b; *b = k;}

void trans(char *s, char *t)
{
	for(char *p = s; *p != '\0'; ++p) {
		switch(*p){
			case 'A' : *t++ = '0'; break;
			case 'C' : *t++ = '1'; break;
			case 'G' : *t++ = '2'; break;
			case 'T' : *t++ = '3'; break;
			default : break;
		}
	}
}
