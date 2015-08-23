#include <stdio.h>
#include <string.h>
#include <queue>
#define maxlen 1000000
#define maxl 55

struct _node{
    int value;
    struct _node *c[26];
} root[maxlen], *adj=root;

inline void Ins( char * s );
int Query( char s[] );

int main(int argc, char const *argv[]) {
    int T; for ( scanf("%d", &T); T; --T ) {
        adj = root;
        memset(root, 0x0, sizeof(root));
        int n; scanf("%d", &n);
        char s[maxl];
        for ( int i = 0; i < n; ++ i ) {
            scanf("%s", s);
            Ins(s);
        }
        scanf("%s", s);
        int ans = 0;
        for ( int i = 0, len = strlen(s); i < len; ++ i ) {
            _node * p = root;
            for ( int d = 0 ; p != NULL && i+d<len ; ++ d ) {
                ans += p->value;
                int idx = s[i+d] - 'a';
                p = p->c[idx];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

inline void Ins(char * s) {
    struct _node *p = root;
    for ( int i = 0; s[i]; ++ i ) {
        int tmp = s[i]-'a';
        if ( !p->c[tmp] ) {
            p->c[tmp] = ++adj;
        }
        p=p->c[tmp];
    }
    ++p->value;
}
