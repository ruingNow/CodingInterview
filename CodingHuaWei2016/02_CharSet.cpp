/***********************************************************
[编程题] 字符集合
时间限制：1秒
空间限制：32768K
输入一个字符串，求出该字符串包含的字符集合

输入描述:
每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。


输出描述:
每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
***********************************************************/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string inputStr;
    getline(cin, inputStr);

    char result[53];
    int index = 0;
    bool visLower[26] = {false};
    bool visUpper[26] = {false};

	
    for(string::size_type i = 0; i < inputStr.size(); ++i)
    {
		
        if(!visLower[inputStr[i] - 'A'] && inputStr[i] <= 'Z')
        {
            visLower[inputStr[i] - 'A'] = true;
            result[index++] = inputStr[i];
		
        }
		if(!visUpper[inputStr[i] - 'a'] && inputStr[i] >= 'a')
        {
            visUpper[inputStr[i] - 'a'] = true;
            result[index++] = inputStr[i];
        }
    }
	result[index] = '\0';
    cout << result << endl;
    
    return 0;
}