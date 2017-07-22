/****************************************************************
[编程题] 循环单词
时间限制：1秒
空间限制：32768K
如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 
就是属于同一种循环单词。 现在给出n个单词，需要统计这个n个单词中有多少种循环单词。 
输入描述:
输入包括n+1行：

第一行为单词个数n(1 ≤ n ≤ 50)

接下来的n行，每行一个单词word[i]，长度length(1 ≤ length ≤ 50)。由小写字母构成


输出描述:
输出循环单词的种数

算法思想：把要测试的单词 重复下，如：picture ，变成 picturepicture
然后判断其他要测试的单词是不是这个串的子串（长度要先相等）
***************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int n, number = 0;
    cin >> n;

    vector<string> vecWords;
    vector<bool> check;
    string inputStr;


    while(cin >> inputStr)
    {
        vecWords.push_back(inputStr);
        check.push_back(false);
    }

    for(int i = 0; i < n; ++i)
    {
        if(!check[i])
        {
            string twoWords;
            twoWords = vecWords[i] + vecWords[i];
            for(int j = i+1; j < n; ++j)
            {
                if(!check[j])// 第i个单词和 后面的所有单词循环匹配 匹配到的是同一种 number只加一
                {
                    if((twoWords.find(vecWords[j]) != string::npos) && (vecWords[i].length() == vecWords[j].length()))
                    {//find 查找是不是子串 并且 两个单词长度相等
                        check[j] = true;
                    }
                }
            }
            number ++;
        }
    }

    cout << number << endl;


    return 0;
}