#include<iostream>

using namespace std;

int main(){



    //sscanf��sprintf��������Ķ������ַ���
    int year,month,day,hour,minute,second;
    //Ҫ���������ָ�������ݣ�����ûָ����Ӧ����format��ԭ��д�����������ʱ����Ҫ//��--�Լ� �� ���ţ���Ӧ����Ӧλ��ԭ��д��
   
   /*  char *arr = "2022//7--14 11:42:33";
    sscanf(arr,"%d//%d--%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second); */
    
    sscanf("2022//7--14 11:42:33","%d//%d--%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second); 
    printf("time = %d-%d-%d %d:%d:%d\n",year,month,day,hour,minute,second);
    char buf[100];
    sprintf(buf,"������%s,СʱΪ[%d],����Ϊ[%d],����Ϊ[%d]","����",hour,minute,second);//�ַ������ֵȲ�ͬ�ĸ�ʽ����ַ���
    puts(buf);
    system("pause");
    return 0;
}




/* time = 2022-7-14 11:42:33
СʱΪ[11],����Ϊ[42],����Ϊ[33] */