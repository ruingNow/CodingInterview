/*******************************************************************
美团点评上有很多餐馆优惠券，用户可以在美团点评App上购买。每张优惠券有一个唯一的正整数编号。
当用户在相应餐馆就餐时，可以在餐馆使用优惠券进行消费。优惠券的购买和使用按照时间顺序逐行记
录在日志文件中，运营人员会定期抽查日志文件看业务是否正确。业务正确的定义为：一个优惠券必须
先被购买，然后才能被使用。

某次抽查时，发现有硬盘故障，历史日志中有部分行损坏，这些行的存在是已知的，但是行的内容读不
出来。假设损坏的行可以是任意的优惠券的购买或者使用。

现在问这次抽查中业务是否正确。若有错，输出最早出现错误的那一行，即求出最大s，使得记录1到s-1
满足要求；若没有错误，输出-1。

输入描述:
m 分别表示 m (1 ≤ m ≤ 5 * 10^5) 条记录。

下面有m行，格式为：

I x （I为Input的缩写，表示购买优惠券x）；

O x（O为Output的缩写，表示使用优惠券x）；

? （表示这条记录不知道）。

这里x为正整数，且x ≤ 10^5 。


输出描述:
-1 或 x(1 ≤ x ≤ m) 其中x为使得1到x-1这些记录合法的最大行号。

输入例子:
0
1
O 1
2
？
O 1
3
I 1
？
O 1
2
I 2
O 1

输出例子:
-1
1
-1
-1
2
******************************************************************/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
int cnt[MAXN],la[MAXN];
int main()
{
    int m;
    scanf("%d",&m);
    set<int> mark;
    for(int i=1;i<=m;i++)
    {
        char ty[5];
        scanf("%s",ty);
        if(*ty!='?')
        {
            int x;
            scanf("%d",&x);
            cnt[x]+=(*ty=='I' ? 1 : -1);
            if(cnt[x]<0 || cnt[x]>1)
            {
                if(mark.lower_bound(la[x])==mark.end())
                    return 0*printf("%d\n",i);
                mark.erase(mark.lower_bound(la[x]));
                cnt[x]=min(max(cnt[x],0),1);
            }
            la[x]=i;
        }
        else mark.insert(i);
    }
    return 0*printf("-1\n");
}