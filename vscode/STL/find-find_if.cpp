#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
    Person(string name,int age) : m_name(name),m_age(age) {}
    ~Person(void) {}
    bool operator==(const Person &rhs) const;
public:   //����Ҫ���óɹ��еģ��������ͨ���������ҵ����޷�����
    string m_name; // ����
    int m_age;//����
};

bool Person::operator==(const Person &rhs) const
{
    return (m_name == rhs.m_name && m_age == rhs.m_age);
}
void func0(){


    //������ͨ����ʱfind��ʹ��
    vector<int> vec = {3, 5, 6, 9, 7, 1};
      auto it = find(vec.begin(),vec.end(),9);
      if(it != vec.end()){
          cout<<"�ҵ�Ԫ�أ�"<<*it<<endl;
      }
      else{
          cout<<"Ԫ�ز�����"<<endl;
      } 

    vector<Person> vect = {Person("zhangsan",34), Person("lisi",24), Person("xiaocui",16)};
    Person one("lisi",24);
    auto it1 = find(vect.begin(), vect.end(), one);
    if (it1 != vect.end())
    {
        cout << "�ҵ������:name: " << it1->m_name<<",age: "<<it1->m_age<<endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }

}



//find_if--�˴�����find_if����������������ͨ������ȫ�֣����º������������󣩡�lambda(��������)���ֵ��÷�

//��ͨ����
bool lessThanFive(int val) {
	return val < 5;
}

//ν�ʣ���������Ϊbool�ķº���/��������
class LessThanFive {
public:
	bool operator()(int val) {
		return val < 5;
	}
};

//����������������Ԫ��
void func1() {
	vector<int> v;

	v.push_back(9);
	v.push_back(4);
	v.push_back(7);
	v.push_back(6);
	v.push_back(3);

	//�ص�����
	vector<int>::iterator pos = find_if(v.begin(), v.end(), lessThanFive);
	
	//ν��
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), LessThanFive());
	
	//����������lambda���ʽ��
    //vector<int>::iterator pos = find_if(v.begin(), v.end(), [](int val) {return val < 5;});
    if(pos == v.end()){cout<<"Ŀ��Ԫ�ز�����";};
	while(pos != v.end()) {
		cout << "Ŀ��Ԫ�ش��ڣ�" << *pos << endl;	//1
        pos = find_if(++pos,v.end(),[](int val){return val<5;}); //ѭ��ȷ������������������Ԫ�ش�ӡ�������˴���Ҫ�����ҷ�Χ�ı䣬��ʼλ��Ӧ�����Ѿ����ҵ�Ԫ�ص���һ��λ��
    }   //--һ��Ҫע�⣬++pos��֮ǰ�ҵ�Ԫ�ص���һλ�ã����ò��ҷ�Χ��find_if���ص�pos���²��ҵ���Ԫ��λ��
}		//��Ҫע�⣡++pos����ʹ��ǰ��++�����ʹ�ú���pos++���ǽ���ǰ�Ѳ��ҵ���λ����Ϊ��һ���µĿ�ʼλ�ã�����ʼ�մ�ӡ��һ��δ֪��Ԫ��������ѭ����	



class People {
public:
	string name;
	int age;

	People(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

//�ص�����
bool greaterThan20(const People &p) {
	return p.age > 20;
}

//ν�ʣ���������Ϊbool�ķº���/��������
class GreaterThan20 {
public:
	bool operator()(const People& p) {
		return p.age > 20;
	}
};

//�����Զ�����������Ԫ�أ�������operator==�����
void func2() {
	vector<People> v;
	People p1("Tom", 16);
	People p2("Jerry", 18);
	People p3("Jack", 20);
	People p4("Lucy", 22);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//�ص�����
	//vector<People>::iterator pos = find_if(v.begin(), v.end(), greaterThan20);

	//ν��
	//vector<People>::iterator pos = find_if(v.begin(), v.end(), GreaterThan20());

	//����������lambda���ʽ��
	vector<People>::iterator pos = find_if(v.begin(), v.end(), [](const People &p) {return p.age > 20; });

	if (pos != v.end()) {
		cout << "Ŀ��Ԫ�ش��ڣ� ������" << (*pos).name << "�����䣺" << pos->age << endl;	//������Lucy�����䣺22
	}
	else {
		cout << "Ŀ��Ԫ�ز�����.." << endl;
	}
}

int main()
{

/*     find������ָ��Ԫ���Ƿ���ڡ�find_if������������Ԫ���Ƿ���ڡ�
    ע1��ʹ��find�㷨ʱ�������ͷ�ļ�include <algorithm>��
    ע2�������Զ����������͵�Ԫ��ʱ�������Զ����������͵����У����������operator==��
    ��֪find�㷨Ӧ��αȽ������Զ����������͵Ķ���eg:����Ԫ��Ϊ��������ʵ���Ķ��� */

    //find
    func0();

    //find_if
    func1();
    func2();

    system("pause");
    return 0;
}