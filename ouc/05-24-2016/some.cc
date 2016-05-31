#include <stdio.h>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define INF 100000000
map<int,int>cnt;
map<int,int>penalty;
queue<string>program;
int tmp[300]={0},now[30]={0};

int getPenalty(int x){
    int ans = 0;
    while(x!=0) {
        ans += x&1;
        x >>= 1;
    }
    return ans;
}

int main(){
    char temp_s[20];
    int n,m,k=0;
    int totPenalty = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp[i]);
        if(!cnt[tmp[i]]) {
            penalty[tmp[i]] = getPenalty(tmp[i]);
        }
        cnt[tmp[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<k;j++)
        {
            if(now[j]==tmp[i])
            {
                --cnt[tmp[i]];
                flag=true;
                sprintf(temp_s,"print(%c)\n",j+'a');
                program.push(temp_s);
                break;
            }
        }
        if(flag==false)
        {
            if(k<m)
            {
                --cnt[tmp[i]];
                now[k]=tmp[i];
                totPenalty += penalty[now[k]];
                sprintf(temp_s,"%c=%d\n",k+'a',tmp[i]);
                program.push(temp_s);
                sprintf(temp_s,"print(%c)\n",k+'a');
                program.push(temp_s);
                k++;
            }
            else
            {
                int temp=-1;
                for(int h=0;h<m;h++)
                {
                    if(!cnt[now[h]])
                    {
                        temp = h;
                        break;
                    }
                }
                if(temp!=-1) {
                    --cnt[tmp[i]];
                    now[temp] = tmp[i];
                    totPenalty += penalty[tmp[i]];
                    sprintf(temp_s, "%c=%d\n",temp+'a',tmp[i]);
                    program.push(temp_s);
                    sprintf(temp_s,"print(%c)\n",temp+'a');
                    program.push(temp_s);
                    continue;
                }
                int minn = 0;
                for(int h=1;h<k;h++){
                    if(penalty[now[minn]]>penalty[now[h]]) {
                        minn = h;
                    }
                }
                --cnt[tmp[i]];
                now[minn]=tmp[i];
                totPenalty += penalty[tmp[i]];
                sprintf(temp_s,"%c=%d\n",minn+'a',tmp[i]);
                program.push(temp_s);
                sprintf(temp_s,"print(%c)\n",minn+'a');
                program.push(temp_s);
            }
        }
    }
    int len = program.size();
    printf("%d %d\n", len, totPenalty);
    for ( int i = 0; i < len; ++i ) {
        printf("%s", program.front().c_str());
        program.pop();
    }
    return 0;
}
