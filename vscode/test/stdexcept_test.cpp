#include <iostream>
#include <stdexcept>
using namespace std;

//using std::runtime_error;
using std::cout;
using std::endl;

int main()
{
    int a(4);
    int b=3;
    try{
 
      //ͨ�����²��ԣ�throw�����׳�const char* ������int�͵ȣ���Ҫע�⣬throw�׳�������һ��Ҫ��catch��׽�Ĳ�������һ�£�
      //try�׳��쳣��catch��׽�쳣���ӵ�һ��catchһֱ�ҵ���Ӧ���׳����쳣���ͣ�ִ������Ĵ��롣
      //if (a>b) throw "�Ƚϴ���";

     if(a>b){
        throw runtime_error("�Ƚϴ���"); // runtime_error���캯���Ĳ�������ֻ����const char *
      }
     
     
     //if(a>b) throw 9;
    }
    catch(const char*  e){    //catch�в�������Ӧ��throw�׳�����һ��
        //perror(e)��
        cout<<e<<endl;
    }
    catch(runtime_error &err){  //exception��ԭʼ���࣬ �˴������exception &errЧ����һ����
        cout<<err.what()<<endl;   //err��һ������.what()�Ƕ����ṩ�ĳ�Ա����
    }
    catch(int a){

      cout<<a<<endl;
    }
    system("pause");
}

