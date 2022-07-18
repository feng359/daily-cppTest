#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //数组或者迭代器范围初始化
    char arr[10] = {2, 4, 5, 73, 44, 86, 23, 67, 100, 44};
    vector<int> vec(arr, arr + 10);

    cout << "初始vec中元素为:";
    for_each(vec.begin(), vec.end(), [](int a)
             { cout << a << " "; });
    cout << endl;

    cout << "删除元素73后vec中元素为:";
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (73 == *it)
        {
            vec.erase(it);
            break;  ////此处删除指定元素后不用对后面的元素进行操作，不必保存迭代器位置，直接退出循环即可
        }
        it++;
    }

    for (auto it = vec.begin(); it != vec.end(); it++)
    {

        cout << *it << " ";
    }
    cout << endl;

    //注意erase后返回的迭代器是删除元素的下一个元素迭代器，要想erase后进行++it正常删除
    //后面位置的元素则erase后将it迭代器减一，归位到当前删除元素的位置，经过下一步的it++此时的位置就是被删除元素的下一个位置
    //否则经过下一步的it++此时的位置是被删除元素的下下一个元素位置;
    cout << "删除重复元素44后vec中元素为:";
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

    cout<<"法1逆序输出vec中元素为：";
    for(auto it = vec.rbegin(); it != vec.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //have bug
    /* cout<<"法2逆序输出vec中元素为：";
    for(auto it = vec.end()--;it != vec.begin()++;it--){
        cout<<*it<<" ";
    }
    cout<<endl;
 */

    system("pause");
    return 0;
}