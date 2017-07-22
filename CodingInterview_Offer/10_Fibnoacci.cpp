//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
#include <cstdio>
long long Fibonacci_1(unsigned int n)
{//方法一：递归
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci_1(n-1) + Fibonacci_1(n-2);
}

long long Fibonacci_2(unsigned n)
{//方法二：循环
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;

    for(unsigned int i = 2; i <= n; ++i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}