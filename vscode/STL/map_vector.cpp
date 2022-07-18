#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // map�ͼ�ֵ�ԵĻ����÷�

    // 1-map�ᰴ��key��������2-key�����ظ���value�����ظ���
    //�����ż�ֵ�Գ�ʼ���� ��ֵ�Ե�����д�����£�pair���÷���pair<string,int> p = ("����"��87)  p.first  p.second,����ʹ��������pair
    map<string, int> m = {pair<string, int>("����", 87),
                          make_pair("����", 76),
                          make_pair("�ֻ�", 76)};
    //�±긳ֵ�������ֵ��
    m["����"] = 83;

    //����ʱҲҪ�����ֵ��
    m.insert(pair<string, int>("����", 94)); //����m.insert(make_pair("����"��94));

    for_each(m.begin(), m.end(), [](pair<string, int> m)
             { cout << m.first << " " << m.second << endl; }); // map�Ĳ��������Ǽ�ֵ�ԡ�
    cout << endl;

    cout << "find�����Ƿ��� ���� �����" << endl;
    auto it = m.find("����"); // map��find(key)��Ա����,vectorû�С�
    if (it != m.end())
    {
        cout << "�������Ҵ��ڸ��������,��Ӧ�ķ���Ϊ��" << it->second << endl
             << endl;
    }
    else
    {
        cout << "�������Ҳ����ڸ��������" << endl
             << endl;
    }

 

    //boost-������Ƕ�׸���ʹ��
    //�ص㣺����Ƕ�׵�������Ҫ���������ʼ��������ʱ�������ڽ��б���������ʱ����Ƕ�׵�Ԫ��Ҫ���տ�ʼ����ʱ��Ԫ�����������գ���ȡ������ܵ���������������Ԫ��
    
    // vectorǶ��map
    // vecto��Ԫ��ʹ��ͬһ��map,��map��Ԫ��Ҳһ�α�һ�ζ࣬���ÿ�α���voctorԪ��ʱ������Ҫ��map��Ԫ�ؽ��б���
    vector<map<string, int>> vec;
    map<string, int> mm;
    mm.insert(pair<string, int>("����", 87));
    vec.push_back(mm); // vector�ĵ�һ��mapԪ�ش�ʱֻ������
    mm.insert(pair<string, int>("����", 76));
    vec.push_back(mm); // vector�ĵڶ���mapԪ�ش�ʱ�����򡢽���
    mm.insert(pair<string, int>("�ֻ�", 97));
    vec.push_back(mm); // vector�ĵ�����mapԪ���������򣬽�����ֻ�   --�����Ҫʹһ��Ԫ��map��ֻ��һ��Ԫ�أ���ÿ�ζ�����һ��map���������񱾴���ʹ����ͬһ��map������Ԫ�ز�������

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        //����һ��Ҳ��ֱ�Ӽ�дΪauto tmpMap = *it
        map<string, int> tmpMap = *it; // it��ʾָ��vector��ĳ��Ԫ�����λ�ã�*it��ʾĳ��Ԫ�ر����˴���ָmap������������map�����ļ�ֵ��Ԫ�أ��Լ�ֵ��Ԫ�ر���ʱ����ֵ��Ԫ�ز���first��second��Ա��
        for (auto ite = tmpMap.begin(); ite != tmpMap.end(); ite++)
        {
            cout << "vector-map.first: " << ite->first << " second: " << ite->second << endl;
        }
        cout << endl;
    }
    cout << endl;

    // vector��Ԫ����ͬ���͵Ĳ�ͬmap����ÿ��map��Ԫ�ض���һ���������vectorԪ��ʱ���ض�map���б�����
    vector<map<string, int>> vec1;
    map<string, int> m1;
    m1.insert(pair<string, int>("����", 87));
    vec1.push_back(m1); // vec1tor�ĵ�һ��mapԪ��ֻ������

    map<string, int> m2;
    m2.insert(pair<string, int>("����", 76));
    vec1.push_back(m2); // vec1tor�ĵڶ���mapԪ��ֻ�н���

    map<string, int> m3;
    m3.insert(pair<string, int>("�ֻ�", 97));
    vec1.push_back(m3); // vec1tor�ĵ�����mapԪ�ش�ʱ�ֻ�   --�����Ҫʹһ��Ԫ��map��ֻ��һ��Ԫ��

    for (auto it = vec1.begin(); it != vec1.end(); it++)
    {
        map<string, int> tmpMap = *it; // vector��Ԫ����map����������ͬ���͵�tmpMap����vector��Ԫ��map������(tmpMap.first�Ǵ����д����tmpMap��������û��first��Ա��ֻ��map�����е�Ԫ�ؼ�ֵ�Բ���first��second��Ա)��
        auto ite = tmpMap.begin();     //����vector��Ԫ��map�е�Ԫ�ظ�������һ������û��Ҫ��forѭ��������
        cout << "vector-map.first: " << ite->first << "\t second: " << ite->second << endl;
    }
    cout << endl;

    // mapǶ��map

    map<int, map<string, int>> m4;
    map<string, int> mm1 = {make_pair("����", 23)};
    m4.insert(make_pair(1, mm1));

    map<string, int> mm2 = {make_pair("̩��", 32)};
    m4.insert(make_pair(3, mm2));

    map<string, int> mm3 = {make_pair("����", 24)};
    m4.insert(make_pair(2, mm3));

    for (auto it = m4.begin(); it != m4.end(); it++)
    {
        map<string, int> tmpMap = it->second;
        auto ite = tmpMap.begin();
        cout << "map-map.first: " << it->first << "\tsecond.first: " << ite->first << "\tsecond.second: " << ite->second << endl;
    }
    cout << endl;


    // mapǶ��vector--ĳ�˶�Ӧ�ĸ��Ƴɼ�

    map<string, vector<int>> m5;

    vector<int> vv1 = {34, 22, 77, 44, 85};
    m5.insert(make_pair("����", vv1));

    vector<int> vv2 = {56, 21, 47, 89, 78};
    m5.insert(make_pair("����", vv2));

    vector<int> vv3 = {34, 22, 77, 44, 85};
    m5.insert(make_pair("����", vv3));

    for (auto it = m5.begin(); it != m5.end(); it++)
    {
        cout << "map-vector.first: " << it->first << "\tmap-vector.second: ";
        auto tmpVec = it->second; //������д����vector<int> tmpVec = it->second
        for (auto ite = tmpVec.begin(); ite != tmpVec.end(); ite++)
        {
            cout << *ite << " ";
        }
        cout << endl;
    }
    cout << endl;

    // mapǶ��map��Ƕ��vevtor ����-����-�ɼ�
    map<string, map<string, vector<int>>> mmmm;
    vector<int> vvv1 = {67, 22, 88, 44, 98};
    map<string, vector<int>> mmm1;
    mmm1.insert(make_pair("������", vvv1));
    mmmm.insert(make_pair("�ձ�", mmm1));

    vector<int> vvv2 = {78, 84, 34, 97, 45};
    map<string, vector<int>> mmm2;
    mmm2.insert(make_pair("������", vvv2));
    mmmm.insert(make_pair("����", mmm2));

    vector<int> vvv3 = {88, 90, 78, 99, 84};
    map<string, vector<int>> mmm3;
    mmm3.insert(make_pair("�����", vvv3));
    mmmm.insert(make_pair("�й�", mmm3));

    for (auto it1 = mmmm.begin(); it1 != mmmm.end(); it1++) //����map�ж��Ԫ�أ���Ҫ����for����
    {

        map<string, vector<int>> tmpMap = it1->second;
        auto it2 = tmpMap.begin(); //Ƕ�׵�mapֻ��һ��Ԫ��,û��Ҫ����for������ֱ��ȡ������ɡ�
        cout << "map.first: " << it1->first << "\t\tmap-map.first: " << it2->first << " "<< "\t\tmap-map-vector: ";
        vector<int> tmpVec = it2->second;
        for (auto it3 = tmpVec.begin(); it3 != tmpVec.end(); it3++) // vector���ж��Ԫ�أ���Ҫ����for����
        {     
            cout << *it3 << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}


//���н��������ʾ��
/* ���� 83
���� 76
���� 87
�ֻ� 76
���� 94

find�����Ƿ��� ���� �����
�������Ҵ��ڸ��������,��Ӧ�ķ���Ϊ��83

vector-map.first: ���� second: 87

vector-map.first: ���� second: 76
vector-map.first: ���� second: 87

vector-map.first: ���� second: 76
vector-map.first: ���� second: 87
vector-map.first: �ֻ� second: 97


vector-map.first: ����   second: 87
vector-map.first: ����   second: 76
vector-map.first: �ֻ�   second: 97

map-map.first: 1        second.first: ����      second.second: 23
map-map.first: 2        second.first: ����      second.second: 24
map-map.first: 3        second.first: ̩��      second.second: 32

map-vector.first: ����  map-vector.second: 34 22 77 44 85
map-vector.first: ����  map-vector.second: 34 22 77 44 85
map-vector.first: ����  map-vector.second: 56 21 47 89 78

map.first: ����         map-map.first: ������           map-map-vector: 78 84 34 97 45
map.first: �ձ�         map-map.first: ������           map-map-vector: 67 22 88 44 98
map.first: �й�         map-map.first: �����           map-map-vector: 88 90 78 99 84
 */