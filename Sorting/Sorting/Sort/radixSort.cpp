#include "sort.h"


int _getMaxBit (int data[], int arrayLength);
void radixSort (int array[], int arrayLength);

int _getMaxBit (int data[], int arrayLength)
{
    // get max value
    int maxValue = data[0];

    for(int i = 1; i < arrayLength; i++)
    {
        if(maxValue < data[i])
        {
            maxValue = data[i];
        }
    }

    // get max bit
    int num_bits = 1;
    int p = 10;

    while(maxValue >= p)
    {
        maxValue /= 10;
        num_bits++;
    }

    return num_bits;
}

void radixSort (int array[], int arrayLength)
{
    // 获取最大元素的位数（循环 num_bits次）
    int num_bits = _getMaxBit (array, arrayLength);

    // 临时数组，保存每次循环结果
    int *temp = new int[arrayLength];

    // 桶，记录循环时某一位的元素个数
    int *count = new int[10];

    // 基数（1,10,10,...）
    int radix = 1;

    // 余数
    int digit;

    // 循环num_bits次
    for(int i = 0; i < num_bits; i++)
    {
        // 清空计数数组
        for(int j = 0; j < 10; j++)
            count[j] = 0;

        //获取每个桶中元素的个数
        for(int j = 0; j < arrayLength; j++)
        {
            digit = (array[j] / radix) % 10;
            count[digit]++;
        }

        // 将count数组作用从记录个数转换到 temp数组的索引，为下一步复制元素到temp做准备
        for(int j = 1; j < 10; j++)
            count[j] = count[j] + count[j - 1];

        // 将元素复制到temp中
        for(int j = arrayLength - 1; j >= 0; j--)
        {
            digit = (array[j] / radix) % 10;
            temp[count[digit] - 1] = array[j];
            count[digit]--;
        }

        // 排好一位序的数组复制到原数组
        for(int j = 0; j < arrayLength; j++)
            array[j] = temp[j];

        radix = radix * 10;
    }
    delete[] temp;
    delete[] count;
}

