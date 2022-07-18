
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{

    for (const auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}
         
int main()
{

    string str;
    vector<int> vec;
    cout<<"ÇëÊäÈëhello£º"<<endl;
    cin>>str;
    cout<<str<<endl;
    for (size_t idx = 1; idx <= 9; ++idx)
    {

        vec.push_back(idx);
    }
    print(vec);

    system("pause");
}
