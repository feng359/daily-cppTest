#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //������ߵ�������Χ��ʼ��
    char arr[10] = {2, 4, 5, 73, 44, 86, 23, 67, 100, 44};
    vector<int> vec(arr, arr + 10);

    cout << "��ʼvec��Ԫ��Ϊ:";
    for_each(vec.begin(), vec.end(), [](int a)
             { cout << a << " "; });
    cout << endl;

    cout << "ɾ��Ԫ��73��vec��Ԫ��Ϊ:";
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (73 == *it)
        {
            vec.erase(it);
            break;  ////�˴�ɾ��ָ��Ԫ�غ��öԺ����Ԫ�ؽ��в��������ر��������λ�ã�ֱ���˳�ѭ������
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

    cout<<"��1�������vec��Ԫ��Ϊ��";
    for(auto it = vec.rbegin(); it != vec.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //have bug
    /* cout<<"��2�������vec��Ԫ��Ϊ��";
    for(auto it = vec.end()--;it != vec.begin()++;it--){
        cout<<*it<<" ";
    }
    cout<<endl;
 */

    system("pause");
    return 0;
}