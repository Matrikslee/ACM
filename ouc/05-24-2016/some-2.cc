#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>


using namespace std;

int mul[20];
char number[6000];

long long cal(int x,int y){
    if(x >= y)
        return 0;
    long long ans = 0;
    if(number[x] < '0' || number[x] > '9'){
        x ++;
    }
    if(number[y] < '0' || number[y] > '9'){
        y --;
    }
    ans = 0;
    long long tmp = number[x] - '0';
    x ++;
    while(x < y){
        if(number[x] == '+'){
            ans += tmp;
            tmp = number[x + 1] - '0';
            x += 2;
        }
        else{
            tmp *= (number[x+1] - '0');
            x+=2;
        }
    }
    ans += tmp;
    return ans;
}

int main()
{
    while(~scanf("%s",number+2)){
        long long ans = 0;
        int len = strlen(number+2) + 2;
        int mullen = 0;

        number[0] = '1';
        number[1] = '*';
        number[len] = '*';
        number[len + 1] ='1';
        number[len+2] = 0;
        len += 2;

        for(int i = 0 ; i < len ; i ++){
            if(i % 2 == 1 && number[i] == '*'){
                mul[mullen ++] = i;
            }
        }
        for(int i = 0 ; i < mullen ; i ++){
            for(int j = i + 1;  j < mullen ; j ++){
                long long x1 = cal(mul[i],mul[j]);
                int k = mul[i];
                while(k > 0 && number[k] == '*'){
                    x1 *= (number[k - 1] - '0');
                    k -= 2;
                }
                //printf("%d %lld\n",k,x1);
                long long x2 = cal(0,k);
                k = mul[j];
                while(k < len && number[k] == '*'){
                    x1 *= (number[k + 1] - '0');
                    k += 2;
                }
                //printf("%d %lld\n",k,x1);
                long long x3 = cal(k,len);
                x1 = x1 + x2 + x3;
                //printf("%d %d\n",mul[i],mul[j]);
                //printf("%lld %lld %lld\n",x1,x2,x3);
                if(ans < x1){
                    ans = x1;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
