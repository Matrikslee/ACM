#include <cstdio>
#define  abs(a) ({ (a)>0?(a):-(a); })

int main(int argc, char const *argv[])
{
	int n;
	char s1[3][100], s2[3][100], s3[3][100];
	for(scanf("%d", &n); n--;){
		int  u[20]={0}, d[20]={0};
		bool e[20]={false};
		for(int i=0; i<3; ++i){
			scanf("%s%s%s", s1[i], s2[i], s3[i]);
			for(int j=0; s1[i][j] && s2[i][j]; ++j){
				switch(s3[i][0]){
					case 'e':
						e[s1[i][j]-'A']=true;
						e[s2[i][j]-'A']=true;
						break;
					case 'u':
						u[s1[i][j]-'A']++;
						d[s2[i][j]-'A']++;
						break;
					case 'd':
						d[s1[i][j]-'A']++;
						u[s2[i][j]-'A']++;
						break;
					default:
						break;
				}
			}
		}
		int max=-1, ans=-1;
		for(int i=0; i<12; ++i){
			if(u[i]&&d[i]) { e[i]=true; }
			if(e[i]) { continue; }
			int tmp=abs(u[i]-d[i]);
			if(tmp>max){ max=tmp; ans=i; }
		}
		printf("%c is the counterfeit coin and it is %s.\n", 'A'+ans, u[ans]<d[ans]?"light":"heavy");
	}
	return 0;
}