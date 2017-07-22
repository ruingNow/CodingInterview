/****************************************************************************
[编程题] 超级素数幂
时间限制：1秒
空间限制：32768K
如果一个数字能表示为p^q(^表示幂运算)且p为一个素数,q为大于1的正整数就称这个数叫做超级素数幂。现在给出一个正整数n,如果n是一个超级素数幂需要找出对应的p,q。 
输入描述:
输入一个正整数n(2 ≤ n ≤ 10^18)


输出描述:
如果n是一个超级素数幂则输出p,q,以空格分隔,行末无空格。
如果n不是超级素数幂，则输出No
****************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    int s = sqrt(n);
    for(int i = 2; i <= s; ++i)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    long long int n;
    cin >> n;

    int p, q;
    int ceil = log10(n) / log10(2);
    //N=p的q次方，显然p最小时q最大，因为最小的素数是2，所以q的上限也就是log2N即log10(n) / log10(2)
    
    for(q = 2; q <= ceil; ++q)
    {
        p = pow(n, 1.0/q);//double转换为int会丢失，所以下面要再次判断  p^q = n  ——>  p = n^(1/q)
        if(pow(p,q) == n && isPrime(p))
        {
            cout << p << " " << q << endl;
            break;
        }
    }
    if(q > ceil)
        cout << "No" << endl;

    return 0;
}