#include "sort.h" 

// 当子数组数目太少时，直接使用插入排序
#define Cutoff 3

void quickSort (int array[], int arrayLength);

int _median3 (int array[], int left, int right);
void _QSort (int array[], int left, int right);

// 三数中值分割，使得 “左 < 中 < 右”，然后将 “中” 和“后”置换
int _median3 (int array[], int left, int right)
{
    int center = (left + right) / 2;

    // make array[left] <= array[center] <= array[right]
    if(array[left] > array[center])
        swap (array, left, center);
    if(array[left] > array[right])
        swap (array, left, right);
    if(array[center] > array[right])
        swap (array, center, right);

    // 将中值置换到最后一位
    swap (array, center, right - 1);

    return array[right - 1];
}

void _QSort (int array[], int left, int right)
{
    int i, j;
    int pivot;

    if(left + Cutoff <= right)
    {
        // 获取枢纽元
        pivot = _median3 (array, left, right);

        // 索引值
        i = left;
        j = right - 1;

        for(;;)
        {
            // 移动游标
            while(array[++i]<pivot) {}
            while(array[--j]>pivot) {}

          
            if(i < j)
                // 交换元素，将小于枢纽元的元素放在左边，大于枢纽元的元素放在右边
                swap (array, i, j);
            else
                // 两个子集划分完成后，退出循环
                break;
        }

        // 将枢纽元置换到合适的位置
        swap (array, i, right - 1);

        _QSort (array, left, i - 1);
        _QSort (array, i + 1, right);
    }
    else
        insertionSort (array + left, right - left + 1);
}

void quickSort (int array[], int arrayLength)
{
    _QSort (array, 0, arrayLength - 1);
}
