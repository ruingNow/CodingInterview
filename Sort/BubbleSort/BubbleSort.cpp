/*******************************************************
冒泡排序

算法思想:假设待排序表长为length，从前往后（从后往前）两两比较相邻元素的值，
若为逆序，即arr[i] > arr[i+1]，则交换他们，直到序列比较完。我们称它为一趟
冒泡，结果将最大元素交换到最后一个位置（最大的元素如气泡一样逐渐网上浮，直到
浮出水面）。下一趟冒泡时，前一趟确定的最大元素不再参与比较，待排序列减少一个
元素，每趟冒泡的结果把最大元素放到了最终位置，这样最多做length-1趟冒泡就能
把所有元素排好序。

空间效率：仅使用了一个辅助单元，空间复杂度为O(1)
时间效率：当初始序列有序时，第一趟冒泡后flag为false，直接跳出循环，比较次数为
n-1，移动次数为0，从而最好情况下时间复杂度为O(n);
当初始序列为逆序时，需要进行n-1趟排序，第i趟排序要进行n-i次比较，而且每次比较
都必须移动3个元素，故：
比较次数 = (n-1) + (n-2) + ... + (n-i) + 1 =  [n(n-1)]/2
移动次数 = 3[n(n-1)]/2

从而最坏情况下时间复杂度为O(n*n),平均时间复杂度也为O(n*n)

稳定性：由于当i>j 且arr[i] = arr[j]时，元素不交换，从而冒泡排序是一个稳定的排
序算法。
********************************************************/

#include <iostream>
using namespace std;

#define SWAP(x, y) {x = x ^ y; y = x ^ y; x = x ^ y;}

//从前往后两两比较，每次找最大元素
void BubbleSort(int arr[], int length)
{
    if(arr == nullptr || length <= 0)
        return;

    bool flag = false;
    for(int i = 0; i < length - 1; ++i)
    {
        flag = false;
        for(int j = 0; j < length - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])//若为逆序
            {
                SWAP(arr[j], arr[j + 1]);//交换
                flag = true;
            }
        }
		if(flag == false)//本趟遍历后没有发生交换，说明已经有序
            return;
    }
}

//从后往前两两比较，每次找最小元素
void BubbleSort1(int arr[], int length)
{
    if(arr == nullptr || length <= 0)
        return;

    bool flag = false;
    for(int i = 0; i < length - 1; ++i)
    {
        flag = false;
        for(int j = length - 1; j > i; --j)
        {
            if(arr[j - 1] > arr[j])
            {
                SWAP(arr[j - 1], arr[j]);
                flag = true;
            }
        }

		if(flag == false)//本趟遍历后没有发生交换，说明已经有序
            return;
    }
}

//===================测试代码============================
void Test(char* testName, int arr[], int length, int result[])
{
    printf("%s begin: ", testName);

    BubbleSort1(arr, length);

    if(arr == nullptr && result == nullptr)
    {
        printf("Passed.\n");
        return;
    }

    if(arr == nullptr || result == nullptr)
    {
        printf("Failed.\n");
        return;
    }

    for(int i = 0; i < length; ++i)
    {
        if(arr[i] != result[i])
        {
            printf("Failed.\n");
            return;
        }
    }
     
    printf("Passed.\n");
   /* for(int i = 0; i < length; ++i)
    {
        printf("%d ",arr[i]);
    }*/
}

void Test1()
{
    int arr[] = {1,3,5,2,6,5,6,7};
    int result[] = {1,2,3,5,5,6,6,7};

    Test("Test1", arr, sizeof(arr)/sizeof(int), result);
}

void Test2()
{
    int arr[] = {1,2,3,4,5};
    int result[] = {1,2,3,4,5};

    Test("Test2", arr, sizeof(arr)/sizeof(int), result);
}

void Test3()
{
    int* arr = nullptr;
    int* result = nullptr;

    Test("Test3", arr, 0, result);
}

int main(void)
{
    Test1();
    Test2();
    Test3();

}