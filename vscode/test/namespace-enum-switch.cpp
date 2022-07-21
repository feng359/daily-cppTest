#include <iostream>

using std::cout;
using std::endl;
using std::string;

// namespaceֻ����ȫ�ֶ��塢֧��Ƕ�׶��壨�����ں������ڶ��壬ֻ�ܿռ�Ƕ�׿ռ䣩����ʱ��ӳ�Ա

namespace myspace
{
    int val = 4;
    void func()
    {
        cout << "This is myspace!" << endl;
    }
}

//ע�⣺�����һ�������val��func������Ա����һ����ͬһ�������ռ䣬�������½��������ռ䣬�����Ѵ�����myspace�����ռ�Ļ������������show��Ա
//���£�myspace�����ռ乲��val,func,show������Ա��������ʱ��ӳ�Ա���ԡ�
namespace myspace
{
    void show()
    {
        cout << "Hello World!" << endl;
    }
}

// namespace�������ֿռ䣻���������ռ���ζ�������ռ��еķ���ֻ���ڱ��ļ��з��ʣ��൱�ڸ����������� static ���Σ�ֻ���ڵ�ǰ�ļ��ڷ��ʡ�
//���������ռ��еı����ص��ȫ�ֱ���һ��(��ζ�ſ���ֱ������ȫ�ֱ���һ������)��
namespace
{
    int value = 9;
    void print()
    {
        myspace::func();
        cout << " Hi , boy!" << endl;
    }
}

//�����ռ��Ƕ��ʹ��
namespace spaceA
{
    int number = 10;

    namespace spaceB
    {
        void func()
        {
            cout << "Hello,girl!" << endl;
        }
    }
}




// 1-ö��������һ��һ�������м����̶���ȡֵ������һ���������һ�ܵ����ڼ�;day����ö�����Ϳ�ȡ��һ�����յ��κ�һ�죻
//���Ƶļ���season����ȡ�����ﶬ�ĸ�ֵ��2-ö������ֵ��ö�ٵļ���ֵ�������ģ�һ���һ��ֵĬ��Ϊ0����һ��ֵ���μ�һ��
//���Ҫ�ı���ֵ����ֻ�����ڵ�һ��ֵ��ʾ������ֵ����������е�ֵ��Ĭ�����μ�һ��
void enum_test()
{

    // 1-�ȶ���ö������day���ٶ���ö�ٱ���d
    /* enum day1
    {
        mon,
        tue,
        wed,
        thu,
        fri,
        sat,
        sun
    };     //����mon��ֵ��Ĭ��mon=0,tue=1,wed=2,thu=3...�������μ�һ;
    enum day1 d1 = thu;
    cout << "enum day d = thu: " << d1 << endl; */
    //���Ϊ3

    enum day2
    {
        mon = 1,
        tue,
        wed,
        thu,
        fri,
        sat,
        sun
    }; //��mon��ֵ,������ֵ��mon�Ļ��������μ�һ��mon=1,tue=2,wed=3,thu=4...�������μ�һ;
    enum day2 d2 = thu;
    cout << "enum day d2 = thu : " << d2 << endl; //���Ϊ4

    //����ö�����ͺͱ������ٸ�ֵ
    enum season
    {
        spring,
        summer,
        autumn,
        winter
    } s;
    s = winter;
    cout << s << endl;


    //2-ö�ٱ����䵱switch()�еĲ���
    enum color
    {
        blue = 1,
        red,
        green,
        yellow
    };
    enum color favourate;

    //�������̶����ڹ���ϵͳ��ҳѡ��ܡ�
    while (true)
    {
        printf("����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  ");
        scanf("%d", &favourate); //�˾����д��whileѭ�����棬����һֱ��ӡ��һ������Ľ����
        if (99 == favourate)
        {
            break;
        }

        //switch����������int�ͱ���
        /*  int a;
         scanf("%d", &a);
         if (99 == a)
         {
             break; //�����˳�ѭ��
         } */
         //switch(a) 
         
        //case�����������һ�����,��Ҫд�ܶ���䣬�����case��ʹ�ü�{}����{}����д����
        switch (favourate)
        {
        case blue:    //�������ʹ��{}��
           {
             printf("��ϲ������ɫ����ɫ!\n");
            int b =4;
            cout<<b;
            break;
           }
        case red:
            printf("��ϲ������ɫ�Ǻ�ɫ!\n");
            break;
        case green:
            printf("��ϲ������ɫ����ɫ!\n");
            break;
        case yellow:
            printf("��ϲ������ɫ�ǻ�ɫ!\n");
            break;
        default:
            printf("���������ڴ������������룬���Ҫ�˳��������룬������ 99\n");
            break;
        }
    }
}

int main()
{
    //�����ռ��еĳ�Ա���÷�ʽ

    //��1��ֱ�ӵ���
    cout << myspace::val << endl;
    myspace::func();

    //��2��using ���� ָ������ ��ĳ��������ɼ�
    using myspace::func;
    using myspace::val;
    cout << val << endl;
    func();

    //��3��using ����ָ��ָ�������ռ�� ���з��� ��ĳ���������¿ɼ�
    using namespace myspace;
    cout << val << endl;
    func();
    myspace::show();

    //���������ռ��еĳ�Ա�ڱ��ļ���ȫ����Ч��ֱ�ӵ��á�
    cout << value << endl;
    print();

    //�����ռ��Ƕ��ʹ��
    cout << spaceA::number << endl;
    spaceA::spaceB::func();

    // enumö�����ͺ�switch��ʹ��

    enum_test();

    system("pause");
    return 0;
}

/* 4
This is myspace!
4
This is myspace!
4
This is myspace!
Hello World!
9
This is myspace!
 Hi , boy!
10
Hello,girl! 4
This is myspace!
4
This is myspace!
4
This is myspace!
Hello World!
9
This is myspace!
 Hi , boy!
10
Hello,girl!
enum day d2 = thu : 4
3
����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  3
��ϲ������ɫ����ɫ!
����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  1
��ϲ������ɫ����ɫ!
4����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  2
��ϲ������ɫ�Ǻ�ɫ!
����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  4
��ϲ������ɫ�ǻ�ɫ!
����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  5
���������ڴ������������룬���Ҫ�˳��������룬������ 99
����������ϲ������ɫ:1-blue,2-red,3-green,4-yellow-(99�˳�ϵͳ):  99*/