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

************************************************/

//C语言实现

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int Getcnt(int len, int *item)
{
    int front = 0;
    int end = len - 1;
    int count = 0;
    
    while(front < end)
    {
        if(item[front] < item[end])
		{
        	item[front + 1] +=item[front];
            front++;
            count++;
        }
        else if(item[front] > item[end])
		{
            item[end - 1] += item[end];
            end--;
            count++;
        }           
        else
        {
            front++;
            end--;
        }
    }
    
    return count;
}

int main(void)
{
    int len;
    scanf("%d",&len);
    int *item = (int *)malloc(sizeof(int)*len);
    
    for(int i=0;i<len;i++)
    	scanf("%d",&item[i]);
    
    printf("%d",Getcnt(len,item));
    
    free(item);
    return 0;
}    
