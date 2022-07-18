#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

class WordCount
{

public:
    void readFile(const char *filename);
    void writeFile(const char *filename);

private:
    map<string, int> m;
};

void WordCount::readFile(const char *filename)
{
    ifstream ifs(filename);
    if (!ifs.good())
    {
        cout << "ifstream open file error! " << endl;
    }

    string word;
    while (ifs >> word)
    {
        for(size_t i = 0;i<word.length();i++){  //�������еĴ�д�ַ�ת��ΪСд�ַ�
            if(isalpha(word[i])){
                if(isupper(word[i])){
                    word[i] = tolower(word[i]);
                }
            }
        }

        size_t id = word.length();
        if (isalpha(word[id--])) //���ʵ����һ���ַ����ַ�������β�����������ŵ��ʣ�����ȥ�����뼴��
        {
            m[word]++;
        }
        else
        {
            word.erase(id--);//���ʵ����һ���ַ��������ַ������Ǳ����ţ���Ҫ��ȥ
            m[word]++;
        }
    }
}

void WordCount::writeFile(const char *filename)
{
    ofstream ofs(filename);
    if (!ofs.good())
    {
        cout << "ofstream open file error!" << endl;
    }

    int count = 0;
    for_each(m.begin(), m.end(), [&ofs, &count](pair<string, int> mp) mutable
             { ofs<<mp.first<<" "<<mp.second<<endl;count+=mp.second; });
    cout << "���µ����ܹ���: " << count << "��" << endl;
}

int main(int argc, char *argv[]) //��char **argv
{

    if (3 != argc)
    {
        cout << "�������㣡" << endl;
    }
    
    WordCount w;
    time_t begin, end;

    time(&begin);
    w.readFile(argv[1]);  //argv[1]�ǳ������еĵڶ�������������·��eg��C:\\..\\..\\tmp.txt,Ҳ��ֱ��д��w.readFile("C:\\..\\..\\tmp.txt")�����������ʱ�������������
    w.writeFile(argv[2]); //argv[2]�ǳ������еĵ�������������ʾͳ�ƴ�Ƶ����������λ��
    time(&end);
    cout << "����ʱ���ܼ�Ϊ: " << begin - end << endl;
    
    system("pause");
    return 0;
}
