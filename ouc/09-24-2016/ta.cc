#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 800005
const long double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989;
using namespace std;
typedef long long ll;
struct complex
{
    long double r,i;
    complex(long double real=0.0,long double image=0.0){
        r=real; i=image;
    }
    // 以下为三种虚数运算的定义
    complex operator + (const complex o){
        return complex(r+o.r,i+o.i);
    }
    complex operator - (const complex o){
        return complex(r-o.r,i-o.i);
    }
    complex operator * (const complex o){
        return complex(r*o.r-i*o.i,r*o.i+i*o.r);
    }
}x1[N],x2[N];
ll sum[N]; // 结果存在sum里
void brc(complex *y,int l) // 二进制平摊反转置换 O(logn)
{
    register int i,j,k;
    for(i=1,j=l/2;i<l-1;i++)
    {
        if(i<j)  swap(y[i],y[j]); // 交换互为下标反转的元素
                                // i<j保证只交换一次
        k=l/2;
        while(j>=k) // 由最高位检索，遇1变0，遇0变1，跳出
        {
            j-=k;
            k/=2;
        }
        if(j<k)  j+=k;
    }
}
void fft(complex *y,int l,long double on) // FFT O(nlogn)
                            // 其中on==1时为DFT，on==-1为IDFT
{
    register int h,i,j,k;
    complex u,t;
    brc(y,l); // 调用反转置换
    for(h=2;h<=l;h<<=1) // 控制层数
    {
        // 初始化单位复根
        complex wn(cos(on*2*pi/h),sin(on*2*pi/h));
        for(j=0;j<l;j+=h) // 控制起始下标
        {
            complex w(1,0); // 初始化螺旋因子
            for(k=j;k<j+h/2;k++) // 配对
            {
                u=y[k];
                t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn; // 更新螺旋因子
            } // 据说上面的操作叫蝴蝶操作…
        }
    }
    if(on==-1)  for(i=0;i<l;i++) y[i].r/=l; // IDFT
}
int main(void)
{
    int l1,l2,l;
    register int i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d",&l1);
        l2=l1;
        l=1;
        ll temp;
        ll ans=0;
        while(l<=l1*2 || l<=l2*2)   l<<=1; // 将次数界变成2^n
                                        // 配合二分与反转置换
        for(i=0;i<l1;i++) // 倒置存入
        {
            scanf("%lld",&temp);
            ans+=temp*temp;
            x1[i].r=temp*1.0;
            x1[i].i=0.0;
        }
        for(;i<l;i++)    x1[i].r=x1[i].i=0.0;
        // 将多余次数界初始化为0
        for(i=0;i<l2;i++)
        {
            scanf("%lld",&temp);
            ans+=temp*temp;
            x2[l2-1-i].r=temp*1.0;
            x2[l2-1-i].i=0.0;
        }
        for(;i<l;i++)    x2[i].r=x2[i].i=0.0;
        fft(x1,l,1); // DFT(a)
        fft(x2,l,1); // DFT(b)
        for(i=0;i<l;i++) x1[i]=x1[i]*x2[i]; // 点乘结果存入a
        fft(x1,l,-1); // IDFT(a*b)
        for(i=0;i<l;i++) sum[i]=x1[i].r+0.5; // 四舍五入
        for(i=0;i<l1-1;i++)
            sum[i]+=sum[i+l1];
        sort(sum,sum+l1);
        printf("%lld\n",ans-2*sum[l1-1]);
    }
    return 0;
}
