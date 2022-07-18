#include <iostream>

using namespace std;
class Person
{

public:
    Person(int age = 18, string name = " ") : _age(age), _name(name) {}
    void print(); 
    friend istream& operator>>(istream &ist, Person &obj);
    friend ostream& operator<<(ostream &ost, Person &obj);

private:
    int _age;
    string _name;
};

istream& operator>>(istream &ist, Person &obj)
{
    ist >> obj._age >> obj._name;
    return ist;
}
ostream& operator<<(ostream &ost, Person &obj){
    ost<<obj._age<<"\t"<<obj._name<<endl;
    return ost;

}

void Person::print() //��Ա������ֱ�ӷ������˽�����ݳ�Ա
{
    cout << _age <<"\t"<<_name << endl;
}
int main()
{
    Person  MM;
    Person  nn;
    cin>>MM>>nn;   //һ�����룺32 honghong 19 lili ��  �������룺32 honghong �س� 19 lili �س� �� �Ĵ����룬32�س���honghong �س���������
    cout<<MM<<nn<<endl;
    cout<<"print:"<<endl;
    MM.print();
    nn.print();
    system("pause");
    return 0;
}