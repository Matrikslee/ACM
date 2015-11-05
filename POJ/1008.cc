#include <cstdio>
#include <cstring>

char monf[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
					"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

char days[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
					"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (; n-- > 0;){
		char inmonth[10];
		int  inday, inyear;
		scanf("%d%*s%s%d", &inday, inmonth, &inyear);
		long tot = inyear*365;
		for(int i = 0; i < 19; ++i){
			if(strcmp(monf[i], inmonth) == 0) 
				tot += i*20;
		}
		tot += inday;
		int outyear  = tot/260;
		int outname  = tot%20;
		int outdays  = tot%13; 
		printf("%d %s %d\n", ++outdays, days[outname], outyear);
	}
	return 0;
}