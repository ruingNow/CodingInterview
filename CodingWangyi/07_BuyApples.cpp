/*************************************************************
[编程题] 买苹果
时间限制：1秒
空间限制：32768K
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。 
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果


输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

算法思想：简单题，有6i+8j=N，设计一个一i为增量的循环，遍历能够符合整数解的情况即可。
*************************************************************/
#include <iostream>
using namespace std;

bool isOdd(int n)
{
    if(n % 2 == 0)
        return false;
    else
        return true;
}

int bagNums(int n)
{
    int minBagNums = n;

    if(isOdd(n))
        return -1;

    for(int i = 0; i <= n/6; ++i)
    {
        if((n - 6*i)%8 == 0)
        {
            int j = (n - 6*i) / 8;
            minBagNums = (i + j) < minBagNums ? (i + j) : minBagNums;
        }
    }

    if(minBagNums != n)
        return minBagNums;
    else 
        return -1;
}

int main(void)
{
    int n;
    cin >> n;

    cout << bagNums(n) << endl;

    return 0;
}