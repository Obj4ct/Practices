//���������ַ���
//����һ���ַ��������������Ӵ�Ϊ�����ַ�����0��λ�ÿ�ʼ������Ϊ�����������Ӵ��������ַ�����abababa�������������Ӵ��У���a������aba������ababa������abababa���ȡ�
// ���һ���ַ���ͬʱ������������������
// �ַ��������ǻ����ַ�����
// ��0��λ��ʼ���������������Ӵ����ǻ����ַ�����
// ��Ƹ��ַ���Ϊ�����޵л����ַ�����
// ���ڣ�����һ���ַ������ж����Ƿ��������޵л����ַ�����
#include <iostream>
#include <string>
using namespace std;

// �ж�һ���ַ����Ƿ����
bool isPalindrome(const string &s)
{
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

// �жϴ�0��λ��ʼ���������������Ӵ��Ƿ��ǻ��Ĵ�
bool checkOddLengthSubstrings(const string &s)
{
    int len = s.size();
    for (int subLen = 1; subLen <= len; subLen += 2)
    {
        int start = 0;
        int end = subLen - 1;
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
    }
    return true;
}

// �ж��Ƿ�Ϊ�������޵л����ַ�����
bool isSuperPalindrome(const string &s)
{
    return isPalindrome(s) && checkOddLengthSubstrings(s);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << (isSuperPalindrome(s) ? "Yes" : "No") << "\n";
        
    }
    return 0;
}
