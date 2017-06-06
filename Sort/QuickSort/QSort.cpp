void QSort(int arr[],int low,int high)  
{  
    int first = low;  
    int last = high;  

    int left = low;  
    int right = high;  

    int leftLen = 0;  
    int rightLen = 0;  

    if (high - low + 1 < 10)  
    {  
        InsertSort(arr,low,high);  
        return;  
    }  

    //一次分割  
    int key = SelectPivotMedianOfThree(arr,low,high);//使用三数取中法选择枢轴  

    while(low < high)  
    {  
        while(high > low && arr[high] >= key)  
        {  
            if (arr[high] == key)//处理相等元素  
            {  
                swap(arr[right],arr[high]);  
                right--;  
                rightLen++;  
            }  
            high--;  
        }  
        arr[low] = arr[high];  
        while(high > low && arr[low] <= key)  
        {  
            if (arr[low] == key)  
            {  
                swap(arr[left],arr[low]);  
                left++;  
                leftLen++;  
            }  
            low++;  
        }  
        arr[high] = arr[low];  
    }  
    arr[low] = key;  

    //一次快排结束  
    //把与枢轴key相同的元素移到枢轴最终位置周围  
    int i = low - 1;  
    int j = first;  
    while(j < left && arr[i] != key)  
    {  
        swap(arr[i],arr[j]);  
        i--;  
        j++;  
    }  
    i = low + 1;  
    j = last;  
    while(j > right && arr[i] != key)  
    {  
        swap(arr[i],arr[j]);  
        i++;  
        j--;  
    }  
    QSort(arr,first,low - 1 - leftLen);  
    QSort(arr,low + 1 + rightLen,last);  
}  