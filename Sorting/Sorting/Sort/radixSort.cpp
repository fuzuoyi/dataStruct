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
    // ��ȡ���Ԫ�ص�λ����ѭ�� num_bits�Σ�
    int num_bits = _getMaxBit (array, arrayLength);

    // ��ʱ���飬����ÿ��ѭ�����
    int *temp = new int[arrayLength];

    // Ͱ����¼ѭ��ʱĳһλ��Ԫ�ظ���
    int *count = new int[10];

    // ������1,10,10,...��
    int radix = 1;

    // ����
    int digit;

    // ѭ��num_bits��
    for(int i = 0; i < num_bits; i++)
    {
        // ��ռ�������
        for(int j = 0; j < 10; j++)
            count[j] = 0;

        //��ȡÿ��Ͱ��Ԫ�صĸ���
        for(int j = 0; j < arrayLength; j++)
        {
            digit = (array[j] / radix) % 10;
            count[digit]++;
        }

        // ��count�������ôӼ�¼����ת���� temp�����������Ϊ��һ������Ԫ�ص�temp��׼��
        for(int j = 1; j < 10; j++)
            count[j] = count[j] + count[j - 1];

        // ��Ԫ�ظ��Ƶ�temp��
        for(int j = arrayLength - 1; j >= 0; j--)
        {
            digit = (array[j] / radix) % 10;
            temp[count[digit] - 1] = array[j];
            count[digit]--;
        }

        // �ź�һλ������鸴�Ƶ�ԭ����
        for(int j = 0; j < arrayLength; j++)
            array[j] = temp[j];

        radix = radix * 10;
    }
    delete[] temp;
    delete[] count;
}

