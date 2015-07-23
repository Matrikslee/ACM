#include <algorithm>
#include <iostream>
#include <math.h>
#define MAXN 1111

using std::cin;
using std::cout;
using std::endl;

struct D{ double left,right; };

bool cmp(const D &a, const D &b){ return a.left<b.left;}

int main(int argc, char const *argv[]){
	for(int n, r, caseNum=1;(cin >> n >> r) && n*r!=0; ++caseNum){
		bool hasAns = true;
		D v[MAXN];
		for(D* vt=v; vt-v<n; ++vt){
			int x,y; cin >> x >> y;
			if(fabs(y)>r){ hasAns = false; }
			double dx = sqrt(r*r-y*y);
			vt->left = x-dx, vt->right = x+dx;
		}
		cout << "Case " << caseNum << ": ";
		if(!hasAns){
			cout << "-1" << endl;
		} else {
			std::sort(v, v+n, cmp);
			D* now = v; int radio = 1;
			for(D *pos = v+1; pos-v<n; ++pos){
				if(now->right<pos->left){
					now = pos, ++radio;
				}else if(pos->right<now->right){
					now = pos;
				}
			}
			cout << radio << endl;
		}
	}
	return 0;
}