/*********************************************************************
[编程题] 页码统计
时间限制：1秒
空间限制：32768K
牛牛新买了一本算法书，算法书一共有n页，页码从1到n。牛牛于是想了一个算法题目：在这本算法书页码中0~9每个数字分别出现了多少次？ 
输入描述:
输入包括一个整数n(1 ≤ n ≤ 1,000,000,000)


输出描述:
输出包括一行10个整数，即0~9这些数字在页码中出现的次数，以空格分隔。行末无空格。
*******************************************************************/

/*
算法思想：按位数某个数字出现过多少次。也就是说，固定某一位上的某个数，看看此时有几种情况。

举个栗子： 
对统计1~785012中5出现的个数 
我们先考虑5在低位第三位出现的次数，我们就将第三位固定为5：XXX5XX。 
此时，问题就转化为，“X”处一共有多少种组合方式。 
高位的3位可以从000到785之间，低位的2位可以从00到99之间。 
但是，当高3位为785时，7855XX无论如何都超过了785012，因此，高三位可以选择的只有000~784（共785个数字），高三位和低二位一共有785*100种组合方式。

我们再考虑5在低位第四位出现的次数，我们就将第四位固定为5：XX5XXX。 
与前面相同，高位的二位可以从00到78之间，低位的三位可以从000到999之间。 
当高位是00到77时，与前面一种情况是相同的，一共可以组合出78*1000种情况。 
当高位是78时，785XXX就有超过785012的可能了，后三位的选择局限在000到012之间，共13中情况。 
两者结合就是：78*1000+13

最后考虑5在低位第5位出现的次数，我们就将第五位固定为5：X5XXXX。 
与前面相同，最高位可以从0取到7，低四位可以从0000取到9999. 
当最高位为0到6时，与第一种情况相同，一共可以组合出7*10000中情况。 
当高位是7时，与前面的情况不同的是，75XXXX是不会越界的，后四位可以从0000取到9999，所以可以组合出10000中情况。 
两者结合就是：7*10000+10000

设我们讨论的当前位的值为A，我们统计的数字为B，我们前面讨论的三种情况，其实分别是：A小于B时，A等于B时，A大于B时。
*/
#include <iostream>

using namespace std;


long long int cal(long long int page, int data)
{
    long long int num = 0;
    long long int temp = 1;
    long long int orig = page;

    while(page != 0)
    {
        if(page % 10 > data)
        {
            num += (page / 10 + 1) * temp;
        }
        else if(page % 10 < data)
        {
            num += (page / 10) * temp;
        }
        else
        {
            num += (page / 10) * temp + (orig % temp + 1);
        }
        temp *= 10;
        page /= 10;
    }

    return num;
}

long long int cal0(long long int page)
{
    long long int num = 0;
    long long int temp = 1;
    long long int orig = page;
    while(page != 0)
    {
        if(page % 10 == 0)
        {
            num += (page / 10 - 1)*temp + (orig % temp + 1);
        }
        else
        {
            num += (page / 10) * temp;
        }
        page /= 10;
        temp *= 10;
    }

    return num;
}

int main(void)
{
    long long int n;
    cin >> n;

    cout << cal0(n);

    for(int i = 1; i <= 9; ++i)
    {
        cout << " " << cal(n, i);
    }

	
    return 0;
}