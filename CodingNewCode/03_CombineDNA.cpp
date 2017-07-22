/********************************************************************
[编程题] DNA合成
时间限制：1秒
空间限制：32768K
DNA分子是以4种脱氧核苷酸为单位连接而成的长链，这4种脱氧核苷酸分别含有A,T,C,G四种碱基。
碱基互补配对原则：A和T是配对的，C和G是配对的。如果两条碱基链长度是相同的并且每个位置的
碱基是配对的，那么他们就可以配对合成为DNA的双螺旋结构。现在给出两条碱基链，允许在其中一
条上做替换操作：把序列上的某个位置的碱基更换为另外一种碱基。问最少需要多少次让两条碱基
链配对成功 

输入描述:
输入包括一行：
包括两个字符串,分别表示两条链,两个字符串长度相同且长度均小于等于50。


输出描述:
输出一个整数，即最少需要多少次让两条碱基链配对成功

水题 ，直接if判断 
********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string inputNDA1, inputNDA2;
    cin >> inputNDA1;
    cin >> inputNDA2;

    string::size_type len = inputNDA1.length();
 
    int num = 0;

    for(int i = 0; i < len; ++i)
    {
        if((inputNDA1[i] == 'A' && inputNDA2[i] == 'T') || (inputNDA1[i] == 'T' && inputNDA2[i] == 'A') || 
        (inputNDA1[i] == 'C' && inputNDA2[i] == 'G') || (inputNDA1[i] == 'G' && inputNDA2[i] == 'C'))
        {

        }
        else
            num ++;

    }

    cout << num << endl;

    return 0;

}