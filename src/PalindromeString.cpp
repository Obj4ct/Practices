//�����ַ���
//��Ŀ�������ж�һ���ַ����Ƿ��ǻ����ַ������������ͷ�����һ��
#include <iostream>
#include <string>
using namespace std;

bool isPalindromeString(string str)
{

    if (str.empty())
    {
        return false;
    }
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    
    string str;
    cin >> str;
    if (isPalindromeString(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}