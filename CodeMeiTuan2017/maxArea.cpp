/************************************************************
给定一组非负整数组成的数组h，代表一组柱状图的高度，其中每个柱子的宽度
都为1。 在这组柱状图中找到能组成的最大矩形的面积（如图所示）。 入参h
为一个整型数组，代表每个柱子的高度，返回面积的值。 
输入描述:
输入包括两行,第一行包含一个整数n(1 ≤ n ≤ 10000)
第二行包括n个整数,表示h数组中的每个值,h_i(1 ≤ h_i ≤ 1,000,000)


输出描述:
输出一个整数,表示最大的矩阵面积。

输入例子:
6
2 1 5 6 2 3

输出例子:
10

算法思想：用数学点的描述就是，找所给数组的一个连续子数组，使该子数组的最小值与数组长度乘积最大。

一个线性算法是用堆栈来保存当前可能的矩形（高度和起始位置）。从左到右扫描，对一个元素，如果

a）大于栈顶元素， push；

b）小于的话，pop所有的大于它的元素，计算面积，更新最大值。这时如果堆栈空，push一个新的元素，
高度等于当前元素，起始位置为0；否则，push当前元素高度和栈顶的起始位置。

***********************************************************/
#include <iostream>
#include <stack>

using namespace std;

int MaxArea(int *num, int len)
{
    if(num == nullptr || len < 1)
        return 0;

    stack<int> numStack;
    stack<int> indStack;
    numStack.push(num[0]);
    indStack.push(0);

    int lastPopInd = 0;
    int maxMul = num[0];

    for(int i = 1; i < len; ++i)
    {
        if(num[i] > numStack.top())
        {   
            numStack.push(num[i]);
            indStack.push(i);
        }
        else if(num[i] < numStack.top())
        {
            while(!numStack.empty() && num[i] < numStack.top())
            {//pop所有的大于它的元素，计算面积，更新最大值
                int numPop = numStack.top();
                lastPopInd = indStack.top();
                maxMul = (numPop * (i - lastPopInd)) > maxMul ? (numPop * (i - lastPopInd)) : maxMul;
                numStack.pop();
                indStack.pop();
            }
            if(numStack.empty() || num[i] > numStack.top())
            {//pop完所有大于它的元素之后，push当前元素和栈顶起始位置
                numStack.push(num[i]);
                indStack.push(lastPopInd);
            }
        }
    }
    while(!numStack.empty())
    {
        int numPop = numStack.top();
        lastPopInd = indStack.top();
        maxMul = (numPop * (len - lastPopInd)) > maxMul ? (numPop * (len - lastPopInd)) : maxMul;
        numStack.pop();
        indStack.pop();
    }
    return maxMul;
}

int main(void)
{
    int arr[10000] = {0};
    int len;
    cin >> len;
    for(int i = 0; i < len; ++i)
    {
        cin >> arr[i];
    }

    cout << MaxArea(arr, len) << endl;
    return 0;
}