#include<cstdio>
#define max(i,j) ({int _ = (i), __ = (j); _ > __ ? _ : __;})
#define min(i,j) ({int _ = (i), __ = (j); _ < __ ? _ : __;})
#define swap(T,i,j) ({T _ = i; i = j; j = _;})
#define abs(x) ({(x) < 0 ? -(x) : (x) ;})
#define maxn 50010

int n, d, x, y, k;
int cnt, f[maxn], w[maxn], st[maxn];

int find(int x){  
    int y = f[x];
    if ( f[x]!=x ) {
        f[x] = find(f[x]);
    }
    w[x]=(w[x]+w[y])%3;
    return f[x];
}

bool merge(int x, int y, int d){
    int fx = find(x), fy = find(y);
    if (d == 1){
        if (fx == fy) {
            if(w[x] == w[y]) {
                return 1;
            } else {
                return 0;
            }
        } else {
            f[fx] = fy;
            w[fx] = (w[y] - w[x] + 3) % 3;
            return 1;
        }
    }
    if (d == 2) {
        if(fx == fy){
            if( (2 - w[x] + w[y]) % 3 == 0 ) {
                return 1;
            } else { 
                return 0;
            }
        } else {
            f[fx] = fy;
            w[fx] = (w[y] - w[x] + 2) % 3; 
            return 1;
        }
    }
}

int main(int argc, char const *argv[]){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; f[i++]=i);
    for (int i = 1; i <= k; ++i) { 
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || y > n) {
            ++cnt;
        } else if(d == 2 && x == y){
            ++cnt;
        } else if(!merge(x,y,d)) {
            ++cnt;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
