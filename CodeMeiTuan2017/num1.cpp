/*********************************************************
大富翁游戏，玩家根据骰子的点数决定走的步数，即骰子点数为1时可以走一步，
点数为2时可以走两步，点数为n时可以走n步。求玩家走到第n步（n<=骰子最大
点数且是方法的唯一入参）时，总共有多少种投骰子的方法。 
输入描述:
输入包括一个整数n,(1 ≤ n ≤ 6)


输出描述:
输出一个整数,表示投骰子的方法

输入例子:
6

输出例子:
32

算法思想：这道题是一道递归题，
f(n)=f(n-1)+f(n-2)+…+f(1)+1=2^(n-2)f(1)+2^(n-2)，且f(1)=1. 
=》f(n)=2^(n-1)
********************************************************/


#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    
    cout << (int)pow(2, n - 1);
    
    return 0;
    
}