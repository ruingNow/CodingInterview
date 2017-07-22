/************************************************************************
[编程题] 进制转换
时间限制：1秒
空间限制：32768K
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。


输出描述:
输出该数值的十进制字符串。
************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;
/* 直接使用库函数
int main(void)
{
    char inputNum[100];

    while(cin >> inputNum)
    {
        cout << strtol(inputNum, NULL, 16) << endl;
    }
    
    return 0;
}
*/

long long convert(string inputStr)
{
    string::size_type len = inputStr.length();
    if(len == 0)
        return 0;

    //去掉字符串之间空格
    int k = 0;
    while(inputStr[k++] == ' ')
    {
    }
    if(k > 1)
    {
        inputStr = inputStr.substr(k);
    }

    //去掉16进制标识符0x
    if(len == 2 && inputStr[0] == '0' && (inputStr[1] == 'X' || inputStr[1] == 'x'))
    {
        return 0;
    }
    else if(len > 2)
    {
        if(inputStr[0] == '0' && (inputStr[1] == 'X' || inputStr[1] == 'x'))
            inputStr = inputStr.substr(2);
    }

    long long result = 0;
	len = inputStr.length();


    for(string::size_type  i = 0; i < len; ++i)
    {
		int j = len - i - 1;
        if(inputStr[j] >= '0' && inputStr[j] <= '9')
        {
            result += (inputStr[j] - '0') * (long long)pow(16, i);
        }
        else if(inputStr[j] >= 'A' && inputStr[j] <= 'F')
        {
            result += (inputStr[j] - 'A' + 10) * (long long)pow(16, i);
        }
        else if(inputStr[j] >= 'a' && inputStr[j] <= 'f')
        {
            result += (inputStr[j] - 'a' + 10) * (long long)pow(16, i);
        }
        else//非法字符
            return 0;
    }

    return result;
}


int main(void)
{
    string inputStr;
    while(cin >> inputStr)
    {
       cout << convert(inputStr) << endl;
    }

	system("pause");
	return 0;
}