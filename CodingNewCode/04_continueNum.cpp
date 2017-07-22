/********************************************************************
[编程题] 连续整数
时间限制：1秒
空间限制：32768K
牛牛的好朋友羊羊在纸上写了n+1个整数，羊羊接着抹除掉了一个整数，给牛牛猜他抹除掉的数字是什么。
牛牛知道羊羊写的整数神排序之后是一串连续的正整数，牛牛现在要猜出所有可能是抹除掉的整数。例如：
10 7 12 8 11 那么抹除掉的整数只可能是9
5 6 7 8 那么抹除掉的整数可能是4也可能是9

输入描述:
输入包括2行：

第一行为整数n(1 <= n <= 50)，即抹除一个数之后剩下的数字个数

第二行为n个整数num[i] (1 <= num[i] <= 1000000000)


输出描述:
在一行中输出所有可能是抹除掉的数,从小到大输出,用空格分割,行末无空格。如果没有可能的数，则输出mistake


直接进行判断
注意有数组中数的临界值，如 ： 1 1 则只输出2  不是 0 2
********************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 50

int main(void)
{
    int n;
    cin >> n;
    long long num[MAXN] = {0};

    for(int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    int blankNum = 0;
    bool hasNum = true;
    int outNum = 0;
    sort(num, num + n);

    for(int j = 0; j < n - 1; ++j)
    {
        if(num[j+1] - num[j] == 2)
        {
            blankNum++;
            outNum = (num[j+1] + num[j]) / 2;
        }
        if((num[j+1] - num[j]) > 2 || (num[j+1] - num[j] == 0))
        {
            hasNum = false;
            break;
        }
    }

    if(hasNum && (blankNum < 2))
    {
        if(blankNum == 1)
            cout << outNum << endl;
        if(blankNum == 0)
        {
            if(num[0] == 1)
                cout << num[n-1] + 1 << endl;
            else
                cout << num[0] - 1 << " " << num[n-1] + 1 << endl;
        } 
    }
    else
        cout << "mistake" << endl;

    return 0;
}