#include <cstdio>

struct _dev{
	int price;
	int bandwith;
};

void sort(_dev *head, _dev *tail);

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m[111];
		scanf("%d", &n);
		_dev dev[111][111];
		for(int i=0; i<n; ++i){
			scanf("%d", m+i);
			for(int j=0; j<m[i]; ++j){
				scanf("%d%d", &dev[i][j].bandwith, &dev[i][j].price);
			}
			sort(dev[i],dev[i]+m[i]-1);
		}
		double ans=0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m[i]; ++j){  //两重循环保证每一个设备都被枚举到
				//以当前设备的带宽为最小带宽，初始化此次系统构成方案
				int minbandwith=dev[i][j].bandwith;
				int sumprice=dev[i][j].price, k, r;
				for(k=0; k<n; ++k){
					if(k==i) { continue; } //当前设备所在的种类直接不考虑
					for(r=0; r<m[k]; ++r){
						//判断设备的带宽是否满足要求，满足要求，则选择这个设备，
						//因为按照价格排了顺序，所以第一个满足要求的设备价格一定最小，
						if(minbandwith<=dev[k][r].bandwith) {
							sumprice += dev[k][r].price;
							break;
						}
					}
					//如果第k中设备里找不到符合要求的设备
					//说明当前带宽的系统无法被构成,跳过该方案
					if(r==m[k]){ break; }
				}
				//判断设备数量是否达到要求，数量不够，说明系统无法构成
				if(k<n) { continue; }
				//数量达到要求，更新结果。
				if(minbandwith/(double)sumprice>ans) {
					ans=minbandwith/(double)sumprice;
				}
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}

void swap(_dev *a, _dev *b)
{
	int tmpbandwith=a->bandwith; 
	a->bandwith=b->bandwith;
	b->bandwith=tmpbandwith;
	int tmpprice=a->price;
	a->price=b->price;
	b->price=tmpprice;
}

void sort(_dev *head, _dev *tail)
{
	_dev *left=head, *right=tail;
	int midprice=(head+(tail-head)/2)->price;
	while(left<right){
		while(left->price<midprice) { ++left; }
		while(right->price>midprice) { --right; }
		if(left<=right){ swap(left++,right--); }
	}
	if(left<tail) { sort(left, tail); }
	if(right>head) { sort(head, right); }
}
