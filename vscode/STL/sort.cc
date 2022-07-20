#include <iostream>

using namespace std;

//ð������
void bubble_sort(int arr[], int size)
{

    for (int idx = 0; idx < size - 1; idx++)  //��һ�˺��Լ��Ƚ�
    {

        for (int idy = 0; idy < size - 1 - idx; idy++) //ÿ�Ƚ�x�Σ�����x������Ԫ��λ�ں����x���̶�λ�ã�����һ�ξ���Ӧ����x�Ƚ�,
        {
            if (arr[idy] > arr[idy + 1])
            {
                int tmp = arr[idy];
                arr[idy] = arr[idy + 1];
                arr[idy + 1] = tmp;
            }
        }
    }
}


//��������(���ڷ���˼�룬��ð����������˸Ľ�)
int partion(int arr[], int left, int right)
{

    int pivot = arr[left]; //������ߵ�һ��Ԫ����Ϊ����ֵ����pivit,��ʱarr[left]���λ���൱�ڿ��ţ�ǡ�ø�������������ҵ���Ԫ���ڳ���λ��
    while (left < right)
    {
        while (arr[right] >= pivot && left < right) //�ȴ��������ұ�����ֵС��Ԫ��
            right--;
        arr[left] = arr[right];                 //�����������һ��������ֵ��pivot��С��Ԫ�ط���ǰ������ֵ�ڳ���λ����arr[left]����ʱarr[right]���λ�ÿ��Ÿ�������������ҵ���Ԫ���ڳ���λ��
        while (arr[left] < pivot && left < right) //�ٴ��������ұ�����ֵ���ڵ��ڵ�Ԫ��
            left++;
        arr[right] = arr[left]; //�����������ҵ���Ԫ�ط���ǰ������������ʱ�ڳ���λ��arr[right]�У�ͬʱΪ��һ�Σ����������ҵ���Ԫ��ŭ�ڳ���λ��arr[left]
    }
    arr[right] = pivot; //(������while����ʱ����ʱleft��rightָ��ͬһλ�ã���λ�ÿ��ţ����ʼ������ֵԪ��ŭpivit���ڴ�λ�ã�ֵ��ͬarr[left]=pivotҲ��
    return left;      // return rightҲ��
}

void quick_sort(int arr[], int left, int right)
{
    if (left < right) //�����if�жϱ߽���������ֹԽ�����
    {
        int piv = partion(arr, left, right); //�Գ�ʼ���е�������󣬲��ϵض����������еݹ����
        quick_sort(arr, left, piv - 1);
        quick_sort(arr, piv + 1, right);
    }
}

void bubbleSortTest()
{

    int arr[10] = {7, 8, 5, 1, 10, 3, 6, 2, 4, 9};

    cout << "�����ʼԪ��Ϊ:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;

    bubble_sort(arr, 10);

    cout << "����bubble_sort()��Ԫ��Ϊ:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;
}


void quickSortTest()
{

    int arr[10] = {4, 8, 5, 1, 9, 3, 6, 2, 7, 10};

    cout << "�����ʼԪ��Ϊ:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;

    quick_sort(arr, 0, 9);

    cout << "����quick_sort()��Ԫ��Ϊ:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;
}


int main()
{
    //ð������
    bubbleSortTest();

    //������˳��
    quickSortTest();

    system("pause");
    return 0;
}