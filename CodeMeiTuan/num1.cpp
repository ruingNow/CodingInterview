/**********************************************************
给定两个整数 l 和 r ，对于所有满足1 ≤ l ≤ x ≤ r ≤ 10^9 的 x ，
把 x 的所有约数全部写下来。对于每个写下来的数，只保留最高位的那个
数码。求1～9每个数码出现的次数。
输入描述:
一行，两个整数 l 和 r (1 ≤ l ≤ r ≤ 10^9)。

输出描述:
输出9行。

第 i 行，输出数码 i 出现的次数。

输入例子:
1 4
输出例子:
4
2
1
1
0
0
0
0
0
**********************************************************/

#include <iostream>
#include <math.h>
using namespace std;

/*
int firstNumber(int num)
{
    if(num < 1)
        return 0;
    while(num >= 10)
        num /= 10;
    
    return num - 1;
}

int main(void)
{
    int max = 0;
    int min = 0;
    int number = 0;
	int k = 0;
    int timesOfNumber[9] = {0};
    cin >> min >> max;
    for(int i = min; i <= max; ++i)
    {
        for(int j = 1, k = i/2; j <= k; ++j)
        {
            if(i % j == 0)
            {
                number = firstNumber(j);
                timesOfNumber[number] ++;
            }
        }
        number = firstNumber(i);
        timesOfNumber[number] ++;
    }

    for(int i = 0; i < 9; ++i)
        cout << timesOfNumber[i] << endl;

	getchar();
    return 0;
}
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(ll n,ll m)
{
    if(n==0 || m==0)return 0;
    ll res=0,t=0;
    m=min(n,m);
    for(t=1;t<=m && t*t<=n;t++)
        res+=n/t;
    for(ll i=n/t;i>=n/m;i--)
        res+=(min(m,n/i)-n/(i+1))*i;
    return res;
}
ll sum(ll n,ll tl,ll tr)
{
    return get(n,tr)-get(n,tl-1);
}
ll cal(ll l,ll r,ll tl,ll tr)
{
    return sum(r,tl,tr)-sum(l-1,tl,tr);
}
ll pw[15],res[15];
int main()
{
    for(int i=(pw[0]=1);i<15;i++)
        pw[i]=10*pw[i-1];
    ll l,r;
    scanf("%lld%lld",&l,&r);
    for(int i=0;i<=9;i++)
        for(int j=1;j<=9;j++)
            res[j]+=cal(l,r,j*pw[i],(j+1)*pw[i]-1);
    for(int i=1;i<=9;i++)
        printf("%lld\n",res[i]);
    return 0;
}

/*
#include<iostream>  
#include<algorithm>  
#include<stdio.h>  
#include<string.h>  
#include<queue>  
using namespace std;  
typedef long long ll;  
const int mx = 1e5+10;  
int n,m,len,mid;  
ll cnt[11];  
char str[15];  
ll get_sum(int l,int r,int x){  
    ll ans = 0;  
    r = min(r,x);   
    int k = x/r,mod = x%r;  
    while(1){  
        int d = (r-mod)/(k+1);  
        if(d*(k+1)<r-mod) d++;  
        if(r-d<l) break;  
        ans += k*d;  
        mod = (k*d+mod)%(r-d);  
        r = r - d;  
        k = d==1? x/r:k+1;  
    }  
    ans+=(r-l+1)*k;  
    return ans;  
}  
void work(int x,int v){  
    for(int i=1;i<10;i++){  
        int rode = 1;  
        while(1ll*i*rode<=x){  
            int rr = i*rode+rode-1;  
            cnt[i] += v*get_sum(i*rode,rr,x);  
            rode*=10;  
        }  
    }     
}  
int main(){  
    while(~scanf("%d%d",&n,&m)){  
        memset(cnt,0,sizeof(cnt));  
        work(m,1);   
        work(n-1,-1);  
        for(int i=1;i<10;i++)  
        printf("%lld\n",cnt[i]);  
    }  
    return 0;  
}  */
