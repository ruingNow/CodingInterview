/*******************************************************
快速排序

算法思想:快速排序是对冒泡排序的一种改进。其基本思想是基于分治法的：在待排序表
L[1...n]中任取一个元素pivot 作为基准，通过一趟排序将待排序表划分为独立的两部
分L[1...k-1]和L[k+1...n]，使得L[1...k-1]中的元素都小于pivot，L[k+1...n]中
的元素都大于或等于pivot，则pivot放在了其最终位置L(k)上，这个过程叫做一趟快速
排序。而后分别递归地对两个子表重复上述过程，直至每部分内只有一个元素或空为止，
即所有元素都放在了其最终位置上。

空间效率：由于快排是递归的，需要借助一个递归工作栈来保存每一层递归调用的必要信
息，其容量应与递归调用的最大深度一致。
    最好情况下为log2(n+1);
    最坏情况下，因为要进行n-1次递归调用，所以栈的深度为O(n);
    平均情况下，栈深度为O(log2n).
    最坏为O(n),平均为O(log2n)。

时间效率：快排运行时间与划分是否对称有关，而后者又与具体的划分算法有关。快排最
坏情况发生在两个区域分别包含n-1和0和元素，这种最大程度的不对称性若发生在每一层
递归上，即对应初始排序表基本有序或者逆序时，最坏时间复杂度则为O(n2)。

优化：1.递归过程中划分子序列规模较小时，不再继续递归调用快排，可以采用直接插入
      排序进行后续工作。
      2.尽量选取一个可以将数据中分的中轴元素。如从序列的头、尾、中间选择一个中
      间值作为最终的中轴元素；或者随机选择一个，这样做使得最坏情况在实际排序过
      程中几乎不会发生。

      最理想状态下，即Partition()可以做到最平衡的划分中，得到子问题大小都不能
      大于n/2，这时候快排运行速度大大提升，时间复杂度为O(nlog2n)。

稳定性：不稳定。
********************************************************/

#include<iostream>
using namespace std;

#define SWAP(x, y) {x = x ^ y; y = x ^ y; x = x ^ y;}

int Partition(int arr[], int low, int high)
{
    int pivot = SelectPivotMedianOfThree(arr, low, high);//第一个元素为基准 划分
    while(low < high)
    {
        while(low < high && arr[high] >= pivot)
            --high;
        arr[low] = arr[high];//将比枢轴值小的元素移动到左端

        while(low < high && arr[low] <= pivot)
            ++low;

        arr[high] = arr[low];//将比枢轴值大的元素移动到右端
    }

    arr[low] = pivot;//枢轴元素存放到最终位置
    return low;      //返回存放枢轴的最终位置
}
//左边为轴
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotpos = Partition(arr, low, high);
        QuickSort(arr, low, pivotpos - 1);
        QuickSort(arr, pivotpos + 1, high);
    }
}

//中轴的选择 
/*函数作用：取待排序序列中low、mid、high三个位置上数据，选取他们中间的那个数据作为枢轴*/  
int SelectPivotMedianOfThree(int arr[],int low,int high)  
{  
    int mid = low + ((high - low) >> 1);//计算数组中间的元素的下标  

    //使用三数取中法选择枢轴  
    if (arr[mid] > arr[high])//目标: arr[mid] <= arr[high]  
    {  
        SWAP(arr[mid],arr[high]);  
    }  
    if (arr[low] > arr[high])//目标: arr[low] <= arr[high]  
    {  
        SWAP(arr[low],arr[high]);  
    }  
    if (arr[mid] > arr[low]) //目标: arr[low] >= arr[mid]  
    {  
        SWAP(arr[mid],arr[low]);  
    }  
    //此时，arr[mid] <= arr[low] <= arr[high]  
    return arr[low];  
    //low的位置上保存这三个位置中间的值  
    //分割时可以直接使用low位置的元素作为枢轴，而不用改变分割函数了  
} 

//===================测试代码============================
void Test(char* testName, int arr[], int low, int high, int result[])
{
    printf("%s begin: ", testName);

    QuickSort(arr, low, high - 1);
	
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

    for(int i = 0; i < high; ++i)
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

    Test("Test1", arr, 0, sizeof(arr)/sizeof(int), result);
}

void Test2()
{
    int arr[] = {1,2,3,4,5};
    int result[] = {1,2,3,4,5};

    Test("Test2", arr, 0, sizeof(arr)/sizeof(int), result);
}

int main(void)
{
    Test1();
    Test2();
	
}