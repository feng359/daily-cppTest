#include <iostream>

using namespace std;

//�ص�����-callback function
//�ص�����Ҳ��һ����������һ����ͨ����ֱ�ӵ����������ڣ��ص���������ʱ����Ϊ��һ�������Ĳ���������������ã�
//����������ǻص���������ڵ�ַ���ú���ָ��ռλ����(����ָ�뱣��ľ��Ǻ�������ڵ�ַ�����������Ǻ�������ڵ�ַ����
//����ʱ��ֻ�ܴ��ص�������ڵ�ַ���������ɴ��Σ�������ú����ڲ�ʱ�����ûص��������ǵ����������ָ�룬��һ����ͨ�������÷�ʽ��ͬ�����������á�
int callBack(int val)
{

    return ++val;
}

void print(int (*callFunc)(int), int val)
{ //��һ������ָ��ռλ��������ʾ�ص���������ڵ�ַ��

    cout << "test print val = " << val << endl;
    cout << "callFunc val = " << callFunc(val) << endl; //����print���������ʱ��һ������÷���ͬ�����ûص��������ǵ��ú���ָ�롣
}

int main(int argc, char *argv[])
{

    print(callBack, 3); //ע�⣺�˴����ò���д���źͲ�����ֱ��д��������ڵ�ַ������print���������ʱ���ܺ�һ�����ŵ���ʹ�á�

    system("pause");
    return 0;
}

/* test print val = 3
callFunc val = 4 */