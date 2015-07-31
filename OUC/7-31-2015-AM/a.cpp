#include <stdio.h>

typedef long long int64;

long long P;

void multi(int64 a[][2], int64 b[][2]){
	int64 c[2][2];
	c[0][0] = a[0][0]*b[0][0]%P+a[0][1]*b[1][0]%P;
	c[0][1] = a[0][0]*b[0][1]%P+a[0][1]*b[1][1]%P;
	c[1][0] = a[1][0]*b[0][0]%P+a[1][1]*b[1][0]%P;
	c[1][1] = a[1][0]*b[0][1]%P+a[1][1]*b[1][1]%P;
	a[0][0] = c[0][0]%P, a[0][1] = c[0][1]%P;
	a[1][0] = c[1][0]%P, a[1][1] = c[1][1]%P;
}

int calc(int64 value, int index){
	int64 ans = 1;
	while(index!=0){
		if(index&1){ ans *= value; }
		value *= value, index /= 2;
		value %= P, ans %= P;
	}
	return ans%P;
}

int m_calc(int64 v[][2], int index){
	int64 c[2][2] = {1,0,0,1};
	while(index!=0){
		if(index&1){ multi(c,v); }
		multi(v,v); index /= 2;
	}
	v[0][0] = c[0][0]%P; v[0][1] = c[0][1]%P;
	v[1][0] = c[1][0]%P; v[1][1] = c[1][1]%P;
}

int main(int argc, char const *argv[]){
	for(int x, y1, y2, z1, z2; ~scanf("%d%d%d", &x, &y1, &z1); ){
		if(x==-1 && y1==-1 && z1==-1){ break; }
		scanf("%d%d%lld", &y2, &z2, &P);
		int q = (calc(x, y1)+z1-1)%P;
		int64 A[2][2] = {{0,q+1},{1,q}}, ans=1;
		int64 B[2][2] = {{0,q+1},{1,q}};
		m_calc(A,z2);
		for(int i=0; i++<y2; multi(B,B));
		multi(A, B);
		printf("%lld\n", A[1][0]);
	}
	return 0;
}