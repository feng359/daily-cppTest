#include <iostream>

using namespace std;

//+��������Ҫ������������������֤��Ա�����������涨��������涨����������ǣ������������涨��ʱʹ�������������������涨��û���κ�����Ч��һ���ģ�
//�ٴ���֤��Ա��������ͨ���������𣺽����Ա������һ������������������������this,
//�ǳ�Ա����,�������������������������Ҫдȫ������漰�������������˽�����ݳ�Ա�������������������ʱΪfriend��Ԫ��������ͨ����ҲҪͨ������������˽�����ݣ�������ֱ�ӷ������˽������
class Complex
{
public:
	Complex(int a = 0, int b = 0) :a(a), b(b) {}
	void print()
	{
		cout << a <<"\t" << b << endl;
	}

	void print(Complex & obj);
//  friend Complex operator+(Complex& a, Complex& b);  //ע�⣺��Ԫ��������ĳ�Ա������������������ʵ��,ֻҪ������������ʵ�ֵĺ���
    //��û�������������,c��������������дȫ

  /*   Complex operator+(Complex& rhs){    //������ʵ�ֵģ���������������������������һ����ֻ��Ҫд�Ҳ�����

        return Complex(this->a+rhs.a,this->b+rhs.b);
        
    } */


	Complex operator+(Complex &obj);

protected:
	int a;
	int b;
};


/* Complex operator+(Complex& a, Complex& b) {  ע�⣺operator+��ʱ��������ĳ�Ա����������Ҫ�������˽�����ݳ�Աa��b��˱�������������Ϊ��Ԫ��
												//���ҷ������˽�����ݳ�Ա������ֱ�ӷ���eg:a,����Ҫͨ������������eg:a.a ǰһ��a�Ƕ��󣬺�һ��a�����ݳ�Ա			
	//return Complex(a.a + b.a, a.b + b.b);   //����ֱ������������������
	Complex c(a.a + b.a, a.b + b.b);         //Ҳ���Զ���һ����ʱ����c��Ȼ������������ٷ���
	return c;                               
} */


	Complex Complex::operator+(Complex &obj){
		return Complex(this->a+obj.a,this->b+obj.b);
	}

	void Complex::print(Complex & obj){
			cout<<obj.a<<"\t"<<obj.b<<endl;
	}

int main()
{
	Complex one(1, 1);
	Complex two(2, 0);
	Complex three;
	three = one + two;   //�����three��һ���࣬�������ǿ����ƶ����غ����ķ�����һ����
	three.print();
	//one.print(three);//û���壬���������������ⶨ��
	/*��ӡ���
	3	1
	*/
    system("pause");
	return 0;
}