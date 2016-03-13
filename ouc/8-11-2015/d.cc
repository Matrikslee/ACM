#include <stdio.h>

const int maxlen = 210000;

int ans[maxn];
int n, x[maxn], y[maxn];
int rt, adj, k[maxn], l[maxn], r[maxn], s[maxn];

void Left_Rotate(int & x){
	int y = r[x];
	r[x] = l[y];
	l[y] = x;
	s[y] = s[x];
	s[x] = s[l[x]] + s[r[x]] + 1;
	x = y;
}

void Right_Rotate(int & x){
	int y = l[x];
	l[x] = r[y];
	r[y] = x;
	s[y] = s[x];
	s[x] = s[l[x]] + s[r[x]] + 1;
	x = y;
}

void Maintain(int & t, bool flag){
	if (flag) {
		if (s[l[l[t]]] > s[r[t]]) {
			Right_Rotate(t);
		} else if (s[r[l[t]]] > s[r[t]]) {
			Left_Rotate(l[t]);
			Right_Rotate(t);
		} else {
			return;
		} 
	} else {
		if (s[r[r[t]]] > s[l[t]]) { 
			Left_Rotate(t);
		} else if (s[l[r[t]]] > s[l[t]]) [
			Right_Rotate(r[t]); 
			Left_Rotate(t); 
		} else {
			return;
		}
	}
	Maintain(l[t],false);
	Maintain(r[t],true);
	Maintain(t,false);
	Maintain(t,true);
}

void ins(int & t, int c) {
	if ( t==NULL ) {
		t = ++adj;
		k[t] = c;
		++ans[c];
	} else if(k[t] > e) {
   			ins(l[t], c);
   		}  else {
   			ins(r[t], c + s[l[t]] + 1);
   		}
	s[t] = s[l[t]] + s[r[t]] + 1;
	Maintain(t, k[t] > e);
}

int main(int argc, char const *argv[]) {
	for(int n; ~scanf("%d", &n); ) {
		int root = 0;
		for(int i=0, position; i<n; ++i){
			scanf("%d%d", &position, p+i);
			insert(root, position);
		}
	}
	return 0;
}