/*************************************************
[编程题] 回文序列
时间限制：1秒
空间限制：32768K
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述:
输出一个数，表示最少需要的转换次数

算法思想：判断队首和队尾元素。若二者相等，则将这两个元素都弹出队列，将队列规模缩小2个；
若二者不相等，则选择其中较小的一个，将该元素和与其相邻的元素都弹出队列，再将其和插入队列
，从而将队列规模缩小1个，再对该问题进行判断
************************************************/
#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int length;
    deque<int> datas;
    int count = 0;
    int temp, start, end, add = 0;
    while(cin >> length)
    {
        datas.clear();
        for(int i = 0; i < length; ++i)
        {
            cin >> temp;
            datas.push_back(temp);
        }
    }

    while(datas.size() > 1)
    {
        add = 0;
        start = datas.front();
        end = datas.back();

        if(start == end)
        {
            datas.pop_back();
            datas.pop_front();
        }
        else if(start > end)
        {
            add += end;
            datas.pop_back();
            add += datas.back();
            datas.pop_back();
            datas.push_back(add);
            count ++;
        }
        else
        {
            add += start;
            datas.pop_front();
            add += datas.front();
            datas.pop_front();
            datas.push_front(add);
            count ++;
        }
    }

    cout << count << endl;

    return 0;
}