#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //数组或者迭代器范围初始化;大括号初始化。
    int arr[10] = {2, 4, 5, 73, 44, 86, 23, 67, 100, 44};
    vector<int> vec(arr, arr + 10);

    cout << "初始vec中元素为:";
    // \可分割一行代码，如果一行代码很长，则在需要的位置加上斜杠\,注意\后面不可再跟任何代码或注释
    for_each(vec.begin(), vec.end(), [](int a)\    
             { cout << a << " "; });
    cout << endl;

    cout << "vec经过reverse后为:"; //
    reverse(vec.begin(), vec.end());
    for(auto elem:vec){cout<<elem<<" ";}
    cout << endl;
    
    

    //指定范围左闭右开，遵照begin,end模式，偶数个元素正好前后成对互换位置，奇数个元素最中间的元素位置不变
    cout<<"vec对指定范围it.begin-it+4进行reverse后为:"; 
    vector<int> ::iterator ite = vec.begin();
    reverse(ite,ite+4);
    for_each(vec.begin(),vec.end(),[](int val){cout<<val<<" ";});
    cout<<endl;


    cout << "删除元素73后vec中元素为:";
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (73 == *it)
        {
            vec.erase(it);
            break; ////此处删除指定元素后不用对后面的元素进行操作，不必保存迭代器位置，直接退出循环即可
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

    cout << "法1逆序输出vec中元素为：";
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // have bug
    /* cout<<"法2逆序输出vec中元素为：";
    for(auto it = vec.end()--;it != vec.begin()++;it--){
        cout<<*it<<" ";
    }
    cout<<endl;
 */

    // sort()第三个参数可省略，默认升序排列，也即第三个参数为less<int>()，
    //尖括号里面的int代表排列的元素类型,像int等内置类型可省略,降序则为greater<int>()
    //如果比较的元素不是内置类型，如结构体或类对象，则第三个参数应该自写一个返回值为bool的函数供回调,
    //规则是return a<b升序，a>b降序
    cout<<"vec经过sort升序less<int>()模式后为:";
    sort(vec.begin(),vec.end()); //等同于sort(vec.begin(),vec.end(),less<int>());
    for(auto elem :vec){cout<<elem<<" ";}
    cout<<endl;

    cout<<"vec经过sort降序greater<int>()模式后为:";
    sort(vec.begin(),vec.end(),greater<>()); //尖括号greater尖括号里面的元素类型若为内置类型则可省略
    for(auto elem :vec){cout<<elem<<" ";}
    
    
    system("pause");
    return 0;
}











