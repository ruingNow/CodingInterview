/*************************************************************
[编程题] 素数对
时间限制：1秒
空间限制：32768K
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
输入描述:
输入包括一个整数n,(3 ≤ n < 1000)


输出描述:
输出对数

输入例子1:
10

输出例子1:
2
*************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if(n == 2)
        return true;
    
    if(n < 2 || n % 2 == 0)
        return false;

    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
            return false;
    }

    return true;

}

int main(void)
{
    int n;
    while(cin >> n)
    {
        int sum = 0;
        if(n < 3 || n >= 1000)
        {
            cout << sum << endl;
            break;
        }

        if(isPrime(n - 2))
            sum++;

        for(int i = 3; i <= n/2; i += 2)
        {
            if(isPrime(i) && isPrime(n - i))
                sum++;
        }

        cout << sum << endl;
    }

    return 0;
}