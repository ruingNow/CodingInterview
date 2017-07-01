/****************************************************
给你六种面额 1、5、10、20、50、100 元的纸币，假设每种币值
的数量都足够多，编写程序求组成N元（N为0~10000的非负整数）
的不同组合的个数。 
输入描述:
输入包括一个整数n(1 ≤ n ≤ 10000)


输出描述:
输出一个整数,表示不同的组合方案数

输入例子:
1

输出例子:
1
****************************************************/
#include <iostream>

using namespace std;

#define TYPE 6
#define N 10000

int getTypes(int n)
{
    int coins[TYPE] = {1, 5, 10, 20, 50, 100};
    long dp[TYPE][N] = {0};

    for(int i = 0; i < TYPE; ++i)
        dp[i][0] = 1;
    for(int j = 0; j <= n; ++j)
        dp[0][j] = 1;

    for(int i = 1; i < TYPE; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int m = j / coins[i];
            for(int k = 0; k <= m; ++k)
                dp[i][j] = dp[i][j] + dp[i-1][j-k*coins[i]];
        }
    }
    return dp[TYPE - 1][n];
} 

int main(void)
{
    int n = 0;
    cin >> n;

    cout << getYypes(n) << endl;

    return 0;
}