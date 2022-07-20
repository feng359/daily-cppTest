#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //������ߵ�������Χ��ʼ��;�����ų�ʼ����
    int arr[13] = {2, 4, 5, 73, 44, 86, 23, 86, 67, 5, 100, 23, 44};
    vector<int> vec(arr, arr + 10);

    cout << "��ʼvec��Ԫ��Ϊ:";
    // \�ɷָ�һ�д��룬���һ�д���ܳ���������Ҫ��λ�ü���б��\,ע��\���治���ٸ��κδ����ע��
    for_each(vec.begin(), vec.end(),\
             [](int a){ cout << a << " "; });
    cout << endl;

    cout << "vec����reverse��Ϊ:"; //
    reverse(vec.begin(), vec.end());
    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    //ָ����Χ����ҿ�������begin,endģʽ��ż����Ԫ������ǰ��ɶԻ���λ�ã�������Ԫ�����м��Ԫ��λ�ò���
    cout << "vec��ָ����Χit.begin-it+4����reverse��Ϊ:";
    vector<int>::iterator ite = vec.begin();
    reverse(ite, ite + 4);
    for_each(vec.begin(), vec.end(), [](int val)
             { cout << val << " "; });
    cout << endl;

    cout << "ɾ��Ԫ��73��vec��Ԫ��Ϊ:";
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (73 == *it)
        {
            vec.erase(it);
            break; ////�˴�ɾ��ָ��Ԫ�غ��öԺ����Ԫ�ؽ��в��������ر��������λ�ã�ֱ���˳�ѭ������
        }
        it++;
    }

    for (auto it = vec.begin(); it != vec.end(); it++)
    {

        cout << *it << " ";
    }
    cout << endl;

    //ע��erase�󷵻صĵ�������ɾ��Ԫ�ص���һ��Ԫ�ص�������Ҫ��erase�����++it����ɾ��
    //����λ�õ�Ԫ����erase��it��������һ����λ����ǰɾ��Ԫ�ص�λ�ã�������һ����it++��ʱ��λ�þ��Ǳ�ɾ��Ԫ�ص���һ��λ��
    //���򾭹���һ����it++��ʱ��λ���Ǳ�ɾ��Ԫ�ص�����һ��Ԫ��λ��;
    cout << "ɾ���ظ�Ԫ��44��vec��Ԫ��Ϊ:";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (44 == *it)
        {
            it = vec.erase(it);
            it--;
        }
    }

    for (auto elem : vec)
    {

        cout << elem << " ";
    }
    cout << endl;

    cout << "��1�������vec��Ԫ��Ϊ��";
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // have bug
    /* cout<<"��2�������vec��Ԫ��Ϊ��";
    for(auto it = vec.end()--;it != vec.begin()++;it--){
        cout<<*it<<" ";
    }
    cout<<endl;
 */

    // sort()������������ʡ�ԣ�Ĭ���������У�Ҳ������������Ϊless<int>()��
    //�����������int�������е�Ԫ������,��int���������Ϳ�ʡ��,������Ϊgreater<int>()
    //����Ƚϵ�Ԫ�ز����������ͣ���ṹ�������������������Ӧ����дһ������ֵΪbool�ĺ������ص�,
    //������return a<b����a>b����
    cout << "vec����sort����less<int>()ģʽ��Ϊ:";
    sort(vec.begin(), vec.end()); //��ͬ��sort(vec.begin(),vec.end(),less<int>());
    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "vec����sort����greater<int>()ģʽ��Ϊ:";
    sort(vec.begin(), vec.end(), greater<>()); //������greater�����������Ԫ��������Ϊ�����������ʡ��
    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    // unique()������sort()ʹ�÷�ʽ��Ҳ���������������Ԫ�����Զ������ͣ��������������ʡ�ԣ����Զ������ͣ�����Ҫ��дһ������ֵΪbool���Զ���ȥ�ط�ʽ,
    // unique��û��ɾ���ظ�Ԫ�أ��ǽ����ظ�Ԫ���Ƶ�ǰ�棬�ظ�Ԫ���Ƶ����棬���ص���ȥ��֮�����һ��Ԫ�ص���һ��λ�ã�
    //Ҳ�������λ�ü��ǲ��ظ�Ԫ�ص�endλ�ã�Ҳ���ظ�Ԫ�ص�beginλ��,��ʹ��eraseɾ���ظ��Ŀռ䣨����Ԫ�أ�,vec��size��end��ı�
    cout << "vec����uniqueȥ��֮��Ϊ:";
    auto it1 = unique(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
    cout << "ȥ��֮���ظ�Ԫ��Ϊ:";
    for_each(vec.begin(), it1, [](int val)
             { cout << val << " "; });
    cout << endl;
    cout << "ȥ��֮���ظ�Ԫ��Ϊ:";
    for_each(it1, vec.end(), [](int val)
             { cout << val << " "; });
    cout << endl
         << "����vec.erase()ɾ��vec�о���uniqueȥ��֮������û������ظ�Ԫ�غ�Ϊ:";
    vec.erase(it1, vec.end()); // unique�ƶ���������ظ�Ԫ�ز������ˣ�vec.size()�ı䣬vec.end()�ı�;
    for (auto idx = vec.begin(); idx != vec.end(); idx++)
    {
        cout << *idx << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}


/* ��ʼvec��Ԫ��Ϊ:2 4 5 73 44 86 23 86 67 5 
vec����reverse��Ϊ:5 67 86 23 86 44 73 5 4 2
vec��ָ����Χit.begin-it+4����reverse��Ϊ:23 86 67 5 86 44 73 5 4 2
ɾ��Ԫ��73��vec��Ԫ��Ϊ:23 86 67 5 86 44 5 4 2
ɾ���ظ�Ԫ��44��vec��Ԫ��Ϊ:23 86 67 5 86 5 4 2
��1�������vec��Ԫ��Ϊ��2 4 5 86 5 67 86 23
vec����sort����less<int>()ģʽ��Ϊ:2 4 5 5 23 67 86 86
vec����sort����greater<int>()ģʽ��Ϊ:86 86 67 23 5 5 4 2
vec����uniqueȥ��֮��Ϊ:86 67 23 5 4 2 4 2
ȥ��֮���ظ�Ԫ��Ϊ:86 67 23 5 4 2
ȥ��֮���ظ�Ԫ��Ϊ:4 2
����vec.erase()ɾ��vec�о���uniqueȥ��֮������û������ظ�Ԫ�غ�Ϊ:86 67 23 5 4 2
�밴���������. . .  */