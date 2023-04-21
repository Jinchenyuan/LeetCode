#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 冒泡
void bubble_sort(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        }
    }
}

// 归并排序
void merge(int *data, int start, int mid, int end, int *reg)
{
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (data[i] <= data[j])
            reg[k++] = data[i++];
        else
            reg[k++] = data[j++];
    }
    while (i <= mid)
        reg[k++] = data[i++];
    while (j <= end)
        reg[k++] = data[j++];
    for (i = 0; i < k; i++)
        data[start + i] = reg[i];
}

void merge_recursive(int *data, int start, int end, int *reg)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_recursive(data, start, mid, reg);
        merge_recursive(data, mid + 1, end, reg);
        merge(data, start, mid, end, reg);
    }
}

void merge_sort(int *data, int len)
{
    int reg[len];
    merge_recursive(data, 0, len - 1, reg);
}

// 堆排序
void max_heapify(int arr[], int start, int end)
{
    // 建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    // 若子节点指标在范围内才做比较
    while (son <= end)
    {                                                  
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else // 否则交换父子内容再继续子节点和孙节点比较
        { 
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len)
{
    int i;
    // 初始化，i从最后一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    // 先将第一个元素和已排好元素前一位做交换，再从新调整，直到排序完毕
    for (i = len - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

//希尔排序
void shell_sort(int arr[], int len)
{
    int gap, i, j, temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
    {
        for (i = gap; i < len; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;            
        }
    }
}

int main()
{
    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    int len = (int)sizeof(arr) / sizeof(*arr);
    shell_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
