#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Print0
{
public:
    void operator()(int val)
    {

        cout << val << " ";
    }
};

void print1(int val)
{
    cout << val << " ";
}

void test1()
{
    vector<int> vec1;
    for (int idx = 0; idx < 6; idx++)
    {
        vec1.push_back(rand() % 100);
    }
    for_each(vec1.begin(), vec1.end(), Print0()); //�º�����������߽ṹ�������ˣ������ţ�����ʱ�º�����Ҫд��������ͨ����ֱ��д����������
    cout << endl;
    for_each(vec1.begin(), vec1.end(), print1);
    cout << endl;
    cout<<"ʹ��lambda���ʽ����Ϊfor_each�ĵ�����������"<<endl;
    for_each(vec1.begin(),vec1.end(),[=](int x){cout<<x<<" ";});
    cout<<endl;

}

// transfor��һ������ת�Ƶ���һ�������У�Ҳ������ת�ƵĹ����ж�ԭ������Ԫ�ؽ���һЩ��������
// eg:�����һ���º���Transform()ԭ�ⲻ��ת�Ƶ���һ�������У��ڶ���trans��ͨ���������ԭ�����������ݽ����˼�5��������ת�Ƶ���һ��������

class Transform
{
public:
    int operator()(int val)
    {

        return val;
    }
};

int trans(int val)
{
    return val += 5;
}

int op_twosum(int i, int j)
{

    return i + j;
}

void test2()
{
    vector<int> vec2;
    for (int idx = 0; idx < 6; idx++)
    {
        vec2.push_back(rand() % 100); //�������е�Ԫ��ֵ��С�޶���0-99
    }


    //���������汾��transform�ģ��汾һ�������������汾�����ĸ������ǿɱ�ģ��������ս�Ҫ��Ԫ��ת�Ƶ��ĸ�����
    //�÷�1������һ������Ԫ�أ����ݵĺ�������ֻ��Ҫһ��Ԫ�ز�����trans����ֻ��Ҫһ����������һ��������Ԫ��ת�Ƶ���һ�������У�������ת�ƵĹ�������һЩ��������
    vector<int> vec3; //ת�ƺ��������СӦ�͵�һ��������Сһ�£�һ��Ҫ�ڵ�һ��������Ԫ�غ��ٽ����ⲽ����
    vec3.resize(vec2.size());

    //�˴���������Ҫ��������������ֻ��Ҫһ������Ҳ�ɣ���������������Ϊvec2.begin���ɣ�����vec2�е�Ԫ�ؾ������������ս���Ḳ��ԭ����Ԫ��
    transform(vec2.begin(), vec2.end(), vec3.begin(), Transform()); //�º�����������߽ṹ�������ˣ������ţ�����ʱ�º�����Ҫд��������ͨ����ֱ��д����������
    cout << "for_each()-Transform() = ";
    for_each(vec3.begin(), vec3.end(), print1);
    cout << endl;

    transform(vec2.begin(), vec2.end(), vec3.begin(), trans);   //���������ɻ�Ϊ����������[](int x){return x+5;} 
    cout << "for_each()-trans +5 = ";
    for_each(vec3.begin(), vec3.end(), print1);
    
    //�÷�2��������������Ԫ�أ����ݵĺ���������Ҫ����Ԫ�ز�����op_twosum������������vec2������Ԫ�غ�vec3������Ԫ����ӣ�����������¸���vec2����,����4��Ԫ����vec3.begin(),���ǽ��������vec3����--5������
    transform(vec2.begin(), vec2.end(), vec3.begin(), vec2.begin(), op_twosum);  //���������ɻ�Ϊlambda���ʽ��[](int,x,int,y){return x+y;}
    cout << "op_twosum :";
    for_each(vec2.begin(), vec2.end(), print1);
    cout << endl;
}

int main()
{

    test1();
    test2();

    system("pause");
    return 0;
}

/* ���Խ��������ʾ��
41 67 34 0 69 24
41 67 34 0 69 24
for_each()-Transform() = 78 58 62 64 5 45
for_each()-trans +5 = 83 63 67 69 10 50
op_twosum :161 121 129 133 15 95
�밴���������. . . */