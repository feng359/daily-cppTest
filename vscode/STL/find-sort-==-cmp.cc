#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using person = struct p{
    string name;
    int age;
};
//����c++�д˴�using�÷���c��type�÷�һ��
/* typedef struct p{
    string name;
    int age;
}person;
 */

//����Ԫ��find�ĵ������������Զ���(�ṹ�塢��ȷ���������)��Ҫ����==
bool operator==(person a,person b){     
    return (a.name== b.name && a.age == b.age);
}

//�Ƚϵ�Ԫ�����Զ��壬��Ҫָ���ȽϷ�ʽ���˴�����������µ�������
bool cmp(person A,person B){
    return (A.age<B.age);
}


int main(){ 

    char arr[9] = {4,5,1,3,4,8,4,9,7};
    vector<int> vec(arr,arr+9);
    auto it  = find(vec.begin(),vec.end(),4);
    while(it != vec.end()){
        
        cout<<"���ڴ�Ԫ��: "<<*it<<endl;
        it = find(++it,vec.end(),4);
    }


    auto ite= find_if(vec.begin(),vec.end(),[](int val){return val>5;});
    if(ite == vec.end()) cout<<"���޴�ֵ��"<<endl;
    while(ite != vec.end()){    
        cout<<"���ڴ���5��Ԫ��: "<<*ite<<endl;
        ite = find_if(++ite,vec.end(),[](int val){return val>5;});
    }
   
    person p[3] = {{"lihua",34},{"jingjing",24},{"taohong",27}};
    person one = {"jingjing",24};

   auto it1 =  find(p,p+3,one);
   if(it1 != p+3){
    cout<<"name: "<<it1->name<<" "<<"age: "<<it1->age<<endl;
   }

    cout<<"sort: ";
    sort(p,p+3,cmp);
    for(size_t idx = 0;idx<3;idx++){
        cout<<p[idx].name<<" "<<p[idx].age<<endl;

    }    


    system("pause");
    return 0;
}