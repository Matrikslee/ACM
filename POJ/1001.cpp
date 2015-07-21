#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

struct pfloat{
	int digit[128], len, dot;
};

int buf[128];

void converttopfloat(char *s, pfloat *num);
void printpfloat(pfloat *cur);
void multi(pfloat *a, pfloat *b);

int main(int argc, char const *argv[])
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	pfloat *a = new pfloat;
	pfloat *b = new pfloat;
	char s[10]; int n;
	while(cin >> s >> n) {
		b->digit[0] = b->len = 1; b->dot = 0;
		memset(a, 0, sizeof(pfloat));
		converttopfloat(s, a);
		while(n--)multi(b,a);
		printpfloat(b);
	}
	delete a; delete b;
	return 0;
}

void converttopfloat(char *s, pfloat *num)
{
	char *p; 
	for(p = s+strlen(s)-1;p-s >= 0 && *p == '0'; --p);
	if(p-s >= 0) {
		for(;p-s >= 0; --p)
			if(*p != '.') {
				num->digit[num->len++] = *p - '0';
			} else {
				num->dot = num->len;
			}
	} else {
		num->len = num->dot = 0;
	}
}

void printpfloat(pfloat *cur)
{
	for(int i = cur->len; i > 0; cout << cur->digit[--i])
		 if(cur->dot == i) cout << '.';
	if(cur->len == 0) cout << 0;
	cout << endl;
}

void multi(pfloat *a, pfloat *b)
{
	memset(buf, 0, sizeof(pfloat));
	for(int i = 0; i < a->len; ++i)
		for(int j = 0; j < b->len; ++j) {
			buf[i+j] += a->digit[i] * b->digit[j];
			buf[i+j+1] += buf[i+j]/10;
			buf[i+j] %= 10;
		}

	int len = a->len + b->len - 1;
	int dot = a->dot + b->dot;
	while(buf[len] == 0 && len != dot) len--;
	while(buf[len]) len++;

	for(int i = 0; i < len; ++i) {
		a->digit[i] = buf[i];
	}

	a->len = len;
	a->dot = dot;
}