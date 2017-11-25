#include "sort.h"

#define Cutoff 3

void randomQuickSort (int array[], int arrayLength);
void _randQSort (int array[], int left, int right);

void randomQuickSort (int array[], int arrayLength)
{
    srand ((unsigned) time (0));
    _randQSort (array, 0, arrayLength - 1);
}

void _randQSort (int array[], int left, int right)
{
    int i;
    int pivot;

    if(left + Cutoff <= right)
    {
        // 获取枢纽元
        int _index = (rand () % (right - left + 1)) + left;
        pivot = array[_index];

        // 将枢纽元放在最右边
        swap (array, _index, right);

        // 小于枢纽元的元素索引
        int storeIndex = left;

        // 遍历整个子数组，小于枢纽元的元素放在数组左边
        for(i = left; i < right; i++)
        {
            if(array[i] < pivot)
            {
                // 将小元素置换到左边，同时将小于枢纽元的索引加一
                swap (array, i, storeIndex);
                storeIndex++;
            }
        }

        // 将枢纽元置换到数组正确位置
        swap (array, storeIndex, right);

        // 对划分好的元素进行随机快排
        _randQSort (array, left, storeIndex - 1);
        _randQSort (array, storeIndex + 1, right);
    }
    else
        insertionSort (array + left, right - left + 1);
}


// 将枢纽元放在最左端
//void _randQSort (int array[], int left, int right)
//{
//    int i;
//    int pivot;
//
//    if(left + Cutoff <= right)
//    {
//        // 获取枢纽元
//        int _index = (rand () % (right - left + 1)) + left;
//        pivot = array[_index];
//
//        // 将枢纽元放在最左边
//        swap (array, _index, left);
//
//        // 小于枢纽元的元素索引
//        int storeIndex = left + 1;
//
//        // 遍历整个子数组，小于枢纽元的元素放在数组左边
//        for(i = left + 1; i <= right; i++)
//        {
//            if(array[i] < pivot)
//            {
//                // 将小元素置换到左边，同时将小于枢纽元的索引加一
//                swap (array, i, storeIndex);
//                storeIndex++;
//            }
//        }
//
//        // 将枢纽元置换到数组正确位置
//        swap (array, storeIndex -1, left);
//
//        // 对划分好的元素进行随机快排
//        _randQSort (array, left, storeIndex-2);
//        _randQSort (array, storeIndex, right);
//    }
//    else
//        insertionSort (array + left, right - left + 1);
//}
