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
        // ��ȡ��ŦԪ
        int _index = (rand () % (right - left + 1)) + left;
        pivot = array[_index];

        // ����ŦԪ�������ұ�
        swap (array, _index, right);

        // С����ŦԪ��Ԫ������
        int storeIndex = left;

        // �������������飬С����ŦԪ��Ԫ�ط����������
        for(i = left; i < right; i++)
        {
            if(array[i] < pivot)
            {
                // ��СԪ���û�����ߣ�ͬʱ��С����ŦԪ��������һ
                swap (array, i, storeIndex);
                storeIndex++;
            }
        }

        // ����ŦԪ�û���������ȷλ��
        swap (array, storeIndex, right);

        // �Ի��ֺõ�Ԫ�ؽ����������
        _randQSort (array, left, storeIndex - 1);
        _randQSort (array, storeIndex + 1, right);
    }
    else
        insertionSort (array + left, right - left + 1);
}


// ����ŦԪ���������
//void _randQSort (int array[], int left, int right)
//{
//    int i;
//    int pivot;
//
//    if(left + Cutoff <= right)
//    {
//        // ��ȡ��ŦԪ
//        int _index = (rand () % (right - left + 1)) + left;
//        pivot = array[_index];
//
//        // ����ŦԪ���������
//        swap (array, _index, left);
//
//        // С����ŦԪ��Ԫ������
//        int storeIndex = left + 1;
//
//        // �������������飬С����ŦԪ��Ԫ�ط����������
//        for(i = left + 1; i <= right; i++)
//        {
//            if(array[i] < pivot)
//            {
//                // ��СԪ���û�����ߣ�ͬʱ��С����ŦԪ��������һ
//                swap (array, i, storeIndex);
//                storeIndex++;
//            }
//        }
//
//        // ����ŦԪ�û���������ȷλ��
//        swap (array, storeIndex -1, left);
//
//        // �Ի��ֺõ�Ԫ�ؽ����������
//        _randQSort (array, left, storeIndex-2);
//        _randQSort (array, storeIndex, right);
//    }
//    else
//        insertionSort (array + left, right - left + 1);
//}
