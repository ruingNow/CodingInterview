/****************************************************************
给出两个字符串（可能包含空格）,找出其中最长的公共连续子串,输出其长度。 
输入描述:
输入为两行字符串（可能包含空格），长度均小于等于50.


输出描述:
输出为一个整数，表示最长公共连续子串的长度。

输入例子:
abcde
abgde

输出例子:
2

算法思想：这题其实是动态规划的变形经典题型，应用动态规划的思想，创建一个二维数组dp[n][n]，
其中dp[i][j]，表示取到s1[i]和取到s2[j]时的最大连续子串长度。如果s1[i]等于s2[j]，则
dp[i-1][j-1]等于取到s1[i-1]和取到s2[j-1]时的最大连续子串长度加1，即dp[i][j]=dp[i-1][j-1]+1。

假设两个字符串str1和str2，长度分别为m和n，则构建一个m*n的矩阵matrix，    
matrix[i][j]==1表示字符串str1中第i个字符与str2中第j个字符相等，为0则不相等。
统计矩阵matrix中每条斜线上1的连续最大个数就是str1和str2中公共连续子串的最大长度
例如：str1: abcde    str2: abgde 
matrix = [ 1  0  0  0  0 
           0  1  0  0  0
           0  0  0  0  0
           0  0  0  1  0
           0  0  0  0  1 ]
斜线上连续的1的最大个数为2，所以最长公共连续子串长度为2
****************************************************************/
#include <iostream>
#include <string>
using namespace std;
#define N 50

int maxSubLen(string sa, string sb)
{
    int maxtri[N][N] = {0};
    int max = 0;
    int la = sa.size();
    int lb = sb.size();

    if(la < 1 || lb < 1)
        return 0;

    for(int i = 0; i < la; ++i)
    {
        for(int j = 0; j < lb; ++j)
        {
            if(sa[i] == sb[j])
            {
                if(i == 0 || j == 0)
                    maxtri[i][j] = 1;
                else
                    maxtri[i][j] = maxtri[i-1][j-1] + 1;
            }
        }
    }

    for(int i = 0; i < la; ++i)
    {
        for(int j = 0; j < lb; ++j)
        {
            if(max < maxtri[i][j])
                max = maxtri[i][j];
        }
    }
    return max;
}

int main(void)
{
    string stra, strb;
    getline(cin, stra);
    getline(cin, strb);

    cout << maxSubLen(stra, strb) << endl;

    return 0;
}
