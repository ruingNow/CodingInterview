/*******************************************************************
编程题：简单错误记录

开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325


输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子:
E:\V1R2\product\fpgadrive.c 1325

输出例子:
fpgadrive.c 1325 1

思路：
建一个结构体fileErrorLog，包含文件名，行号，错误数量
结果数据集vector result,
对于输入的每一个对，得到 然后和res里面的每条记录比较，看是否存在一条记录其<文件名,行号>和输入相等，
若是，则记录errorNum++；否则，将输入添加到res中；这样处理完所有输入之后，
对vector按照fileErrorLog的errorNum字段进行排序，
sort(result.begin(), ressult.end(),Compare)
其中 Compare函数为：
static bool Compare(const ErrorLog& a, const ErrlrLog& b)
{
   return a.errorNum>b.errorNum;
}
*****************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct fileErrorLog
{
    string fileName;
    int    lineNum;
    int    errorNum;
};

fileErrorLog createErrorLog(string name, int line)
{
    fileErrorLog log;
    auto nameSize = name.size();
    int index = -1;
    for(int i = nameSize - 1; i >= 0; --i)
    {//寻找\下标
        if(name[i] == '\\')
        {
            index = i;
            break;
        }
    }
    name = name.substr(index + 1);//截取文件名
   
    log.fileName = name;
    log.lineNum = line;
    log.errorNum = 1;

    return log;
}

void RecordErrorLog(fileErrorLog log, vector<fileErrorLog> &result)
{
    int size = result.size();
    bool isRepeat = false;
    for(int i = 0; i < size; ++i)
    {
        if(log.fileName == result[i].fileName && log.lineNum == result[i].lineNum)
        {
            result[i].errorNum ++;
            isRepeat = true;
            break;
        }
    }
    if(!isRepeat)
    {
        result.push_back(log);
    }
}

static bool Compare(const fileErrorLog &a,const fileErrorLog &b)
{
    return a.errorNum > b.errorNum;
}

int main(void)
{
    string name;
    int line;
    vector<fileErrorLog> result;
    while(cin >> name >> line)
    {
        fileErrorLog log = createErrorLog(name, line);
        RecordErrorLog(log,result);
    }

    sort(result.begin(), result.end(), Compare);//升序排序

    for(auto i = 0; i < result.size(); ++i)
    {
        if(i >= 8)
            break;
        auto size = result[i].fileName.size();
        if(size > 16)
            result[i].fileName = result[i].fileName.substr(size - 16);

        cout << result[i].fileName << " " << result[i].lineNum << " " << result[i].errorNum << endl;
    }

 //   system("paruse");
    return 0;
}