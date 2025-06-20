
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// תСд����
string toLower(string s)
{
    // �����ַ����е�ÿ���ַ�
    for (char c : s)
        // ����ַ��Ǵ�д��ĸ������ת��ΪСд��ĸ
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
    // ����ת������ַ���
    return s;
}
void fun01(int n)
{
        // �������20�����ʼ������
    string w[20] = {""}; // w0 ~ w19
    int cnt[20] = {0};

    // ��������ĵ���
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        // ������ת��ΪСд
        s = toLower(s);

        bool found = false;
        // �����Ѽ�¼�ĵ���
        for (int j = 0; j < 20; ++j)
        {
            // ����ҵ���ͬ�ĵ��ʣ��������1
            if (w[j] == s)
            {
                cnt[j]++;
                found = true;
                break;
            }
            // ���û���ҵ���ͬ�ĵ��ʣ����µ��ʼ�¼����������Ϊ1
            else if (w[j] == "" && !found)
            {
                w[j] = s;
                cnt[j] = 1;
                found = true;
                break;
            }
        }
    }

    // �����ֵ
    int maxIndex = 0;
    for (int i = 1; i < 20; ++i)
    {
        // ����ҵ���������ĵ��ʣ���������ֵ
        if (cnt[i] > cnt[maxIndex])
        {
            maxIndex = i;
        }
    }

    // ������ִ������ĵ���
    cout << w[maxIndex] << endl;
}
void fun02(int n)
{
     // ���nС��1���ߴ���100�����"Invalid input"������1
    if (n < 1 || n > 100)
    {
        cout << "Invalid input" << endl;
        return;
    }

    // ����һ��map�����ڴ洢���ʺͳ��ִ���
    map<string, int> cnt;
    // ����һ�����������ڴ洢�����ִ���
    int max_count = -1;

    // ѭ��n��
    for (int i = 0; i < n; i++)
    {
        // ����һ���ַ���s
        string s;
        cin >> s;
        // ���s�ĳ��ȴ���30�����"Word too long"������1
        if (s.length() > 30)
        {
            cout << "Word too long" << endl;
            return;
        }
        // ��sת��ΪСд
        //transform �� C++ STL �е�һ���㷨��������һ�η�Χ�ڵ�Ԫ��������в�������д��Ŀ��λ�á�
        //transform(��ʼλ��, ����λ��, ���λ��, ��������);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // ��s�ͳ��ִ�������map��
        cnt[s]++;
        // ���������ִ���
        max_count = max(max_count, cnt[s]);
    }

    // ����һ�����������ڴ洢�����������ĵ�������
    int max_num = 0;
    // ����һ�����������ڴ洢�����������ĵ���
    string result;

    // ����map�е�����Ԫ��
    for (const auto &p : cnt)
    {
        // ���ĳ�����ʵĳ��ִ������������ִ���
        if (p.second == max_count)
        {
            // ���õ��ʴ���result��
            result = p.first;
            // ���³����������ĵ�������
            max_num++;
        }
    }

    // ��������������ĵ�������Ϊ1������õ���
    if (max_num == 1)
    {
        cout << result << '\n';
        // �������"Unexpected: multiple max"
    }
    else
    {
        cout << "Unexpected: multiple max" << endl;
    }
}
int main()

{
    int n;
    cin >> n;
    // ���ú���fun01
    fun01(n);
    // ���ú���fun02
    fun02(n);
}





