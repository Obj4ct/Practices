//�����ַ���
//��Ŀ�������ж�һ���ַ����Ƿ��ǻ����ַ������������ͷ�����һ��
#include <iostream> 
#include <string>
using namespace std;

// �ж�һ���ַ����Ƿ��ǻ���
bool isPalindromeString(string str)
{

    // ����ַ���Ϊ�գ��򷵻�false
    if (str.empty())
    {
        return false;
    }
    // ��ȡ�ַ����ĳ���
    int len = str.length();
    // �����ַ�����ǰ�벿��
    for (int i = 0; i < len / 2; i++)
    {
        // ����ַ�����ǰ�벿�ֺͺ�벿�ֲ���ȣ��򷵻�false
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    // ����ַ�����ǰ�벿�ֺͺ�벿����ȣ��򷵻�true
    return true;
}

int main()
{
    
    // ����һ���ַ�������
    string str;
    // �ӱ�׼�����ȡһ���ַ���
    cin >> str;
    // �ж��ַ����Ƿ�Ϊ����
    if (isPalindromeString(str))
    {
        // ����ǻ��ģ����true
        cout << "true" << endl;
    }
    else
    {
        // ������ǻ��ģ����false
        cout << "false" << endl;
    }
}