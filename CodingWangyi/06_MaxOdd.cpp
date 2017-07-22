/**************************************************************
[编程题] 最大的奇约数
时间限制：1秒
空间限制：32768K
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7 
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。 
输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)


输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)
**************************************************************/
#include <iostream>

using namespace std;

//直接算 复杂度过大 超时
/*
int maxOdd(int N)
{
    if(N % 2 != 0)
        return N;
    else
    {
        for(int i = N / 2; i > 1; --i)
        {
            if((N%i == 0) && (i%2 != 0))
                return i;
            
        }
        return 1;
    }
}

int main(void)
{
    int N;
    cin >> N;

    int sum = 0;
    for(int i = 1; i <= N; ++i)
    {
        sum += maxOdd(i);
    }

    cout << sum << endl;

    return 0;
}*/

/*
考虑优化，设sum(i) = f(1) + f(2) + ... + f(i)；

求sum(i)的过程中，对于f(i), i 为奇数可以直接求，就是 i 本身。

问题就是求所有f(i), i为偶数的和。

因为要求的是最大奇约数，所以f(2k) = f(k)，所以f(2) + f(4) + ... + f(2k) = f(1) + f(2) + ... + f(k);

所以

sum(i) =  sum (i / 2) + 1 + 3 + ... + i - 1  （i 为偶数）

       =  sum (i - 1) + i （i 为奇数）

时间复杂度O(logn)，可以解决。


*/

long long sum(long long n)
{
    if(n == 1)
        return 1;
    if(n % 2 == 0)
    {
        return sum(n / 2) + n*n/4;
    }
    else
        return sum(n-1) + n;
}

int main(void)
{
    long long N;
    cin >> N;

    cout << sum(N) << endl;

    return 0;

}