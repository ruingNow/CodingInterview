/*********************************************************
[编程题] 序列和
时间限制：1秒
空间限制：32768K
给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
例如 N = 18 L = 2：
5 + 6 + 7 = 18 
3 + 4 + 5 + 6 = 18
都是满足要求的，但是我们输出更短的 5 6 7

输入描述:
输入数据包括一行：
两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)


输出描述:
从小到大输出这段连续非负整数，以空格分隔，行末无空格。如果没有这样的序列或者找出的序列长度大于100，则输出No
*********************************************************/

/*
等差数列求和。 

求出a1的表达式
该题可理解为“一段长度大于等于L的等差数列之和等于N”的过程。
S =n(a1+an) / 2
= n(a1+a1+(n-1)d) / 2 
= n(2a1+n-1) / 2 
= N
得：a1= (2N-n^2+n) / (2n)
则：只需检测数列首项a1是否满足非负整数即可。
*/

#include<iostream>

using namespace std;

int main(void)
{
    int N, L;
    while(cin >> N >> L)
    {
        bool found = false;
        for(int i = L; i <= 100; ++i)
        {
            if((2*N - i*i + i)%(2*i) == 0 && (2*N - i*i+i) >= 0)
            {
                int a1 = (2*N - i*i + i)/(2*i);
                for(int j = 0; j < i - 1; ++j)
                {
                    cout << a1 + j << " ";
                }
                cout << a1 + i - 1 << endl; 
                found = true;
                break;
            }
        }
        if(!found)
            cout << "No" << endl;
    }
    
    return 0;
}