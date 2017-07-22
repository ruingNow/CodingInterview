/*****************************************************
[编程题] 删数
时间限制：1秒
空间限制：32768K
有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。

输入描述:
每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。


输出描述:
一行输出最后一个被删掉的数的原始下标位置。
*****************************************************/
#include <iostream>

using namespace std;

bool isEmpty(const int *a, int N, int &pos)
{
    bool result = false;
    int count = 0;
    for(int i = 0; i < N; ++i)
    {
        if(a[i] == 1)
        {
            count ++;
            pos = i;
        }    
    }
    if(count == 1)
        result = true;
    return result;
}

int main(void)
{
    int a[1000] = {0};
    int N;
    cin >> N;
    
    if(N > 1000)
        N = 1000;

    for(int i = 0; i < N; ++i)
        a[i] = 1;

    int index = 0;
    int k = 0;
    int pos = 0;
    while(!isEmpty(a, N, pos))
    {
		if(a[index] == 0)
		{
			if(index == N - 1)
                index = 0;
            else
                index++;
			continue;
		}
        if(k == 2)
        {
            a[index] = 0;
            k = 0;
          //  cout << index << endl;
            if(index == N - 1)
                index = 0;
            else
                index++;
            continue;
        }

        if(index == N - 1)
            index = 0;
        else
            index++;

        k++;
    }
    cout << pos << endl;

    return 0;
}