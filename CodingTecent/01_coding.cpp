/***************************************************************
[编程题] 编码
时间限制：1秒
空间限制：32768K
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, 
yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，
输入是任意一个编码，输出这个编码对应的Index. 
输入描述:
输入一个待编码的字符串,字符串长度小于等于100.


输出描述:
输出这个编码的index

输入例子1:
baca

输出例子1:
16331

算法思想：计算出相邻2个同位数编码之间的距离，保存于base[4]中：

base[4] = 1, 即aaaa与aaab之间相隔；base[3] = base[4]*25+1，即aaa与aab之间相隔；base[2] = 25*base[3] + 1，即aa与ab之间相隔；base[1] = 25*base[2]+1，即a与b之间相隔

给定一个字符编码，从高位向低位扫描。对第i位找出相同位数的，且前面i-1位相同，且第i位是a的编码之间的距离

例如baca：

第一步：找出b的位置，即与a之间的距离d1=(‘b’-‘a’)*base[1] + 1

第二步：找出ba的位置，即与ba之间的距离d2 = (‘a’-‘a’)*base[2] + 1

第三步：找出bac的位置，即与baa之间的距离d3 = (‘c’-‘a’)*base[3] + 1

第四步：找出baca的位置，即与baca之间的距离d4 = (‘a’-‘a’)*base[4] + 1

即baca的Index = d1+d2+d3+d4-1
**************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int factor[4] = {25*25*25 + 25*25 + 25 + 1, 25*25 + 25 + 1, 25 + 1, 1};
    string inputStr;
    while(cin >> inputStr)
    {
        long long index = 0;
        string::size_type len = inputStr.length();
        if(len > 100)
        {
            cout << len << endl;
            break;
        }
        
        for(string::size_type i = 0; i < len; ++i)
        {
            index += (inputStr[i] - 'a') * factor[i] + 1;
        }
        cout << index - 1 << endl;
    }
    
    return 0;
}

/*
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char str[1010];
int base[4];

int main()
{
    while(cin>>str)
    {
        int len = strlen(str);
        base[3] = 1;
        for(int i=2;i>=0;i--)
        {
            base[i] = base[i+1]*25+1;
        }

        int _index = 0;
        for(int j=0;j<len;j++)
        {
            _index += ((str[j]-'a')*base[j]+1);
        }
        cout<<_index-1<<endl;
    }
    return 0;
}

*/