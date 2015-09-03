#include <stdio.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const double sm = 59./10, sh = 719./120, mh = 11./120;
	const double tsm = 360/sm, tsh = 360/sh, tmh = 360/mh;
	int cnt; double D, tot = 0;
	while(scanf("%lf", &D) != EOF && D != -1){
		double bsh = D / sh, bsm = D / sm, bmh = D / mh;
		double esh = sh - bsh, esm = sm - bsm, emh = mh - bmh;
		double bt1, bt2, bt3, et1, et2, et3;
		for(bt1 = bsh, et1 = esh; et1 < 43200; bt1 += tsh, et1 += tsh) {
			for(bt2 = bsm, et2 = esm; et2 < 43200; bt2 += tsm, et2 += tsm){
				if(et2 < bt1) continue;
				if(bt2 > et1) break;
				for(cnt = 0, bt3 = bmh, et3 = emh; et3 < 43200; cnt++, bt3 = emh + cnt*tmh, et3 = emh + cnt*tmh){
					if(et3 < bt1 || et3 < bt2) continue;
					if(bt3 > et1 || bt3 > et2) break;
					double max = bt1, min = et1;
					max = bt2 > max ? bt2 : max;
					max	= bt3 > max ? bt3 : max;
					min = et2 < min ? et2 : min;
					min = et3 < min ? et3 : min;
					tot += min-max;
				}
			}
		}
		tot /= 432;
		printf("%.3lf\n", tot);

	}
	return 0;
}