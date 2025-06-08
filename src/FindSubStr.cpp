/*
��֪��Сд��ĸ��ɵ������ַ���a��b����a���Ӵ����ж��ٸ�Ҳͬʱ��b���Ӵ�����ͳ�ƹ����У��������a���Ӵ��ظ���γ��֣�������һ����

ע�⼸����������ַ��������Լ����Ӵ������ַ����������ַ������Ӵ���

��������һ��������n����ʾ��������������n<=50��

ÿ�鰸������������Сд��ĸ��ɵ��ַ���a��b�����ַ������Ⱦ�������100��

����������ÿ�鰸�������һ����������ʾ�����������Ӵ�������

ÿ�鰸������궼Ҫ���С�

��������
1
banana ban
�������
7

���ͣ�

�ַ��� a �� "banana"���ַ��� b �� "ban"��

���ȣ������г� a ("banana") �����в��ظ��Ӵ���

���� 0: ""
���� 1: a, b, n
���� 2: ba, an, na
���� 3: ban, ana, nan
���� 4: bana, anan
���� 5: banan
���� 6: banana
�������������г� b ("ban") �����в��ظ��Ӵ���

���� 0: ""
���� 1: b, a, n
���� 2: ba, an
���� 3: ban
���ڣ������ҳ� a ���Ӵ��У���ЩҲͬʱ������ b ���Ӵ��б��У�

"" (�� a �У�Ҳ�� b ��) - ����
a (�� a �У�Ҳ�� b ��) - ����
b (�� a �У�Ҳ�� b ��) - ����
n (�� a �У�Ҳ�� b ��) - ����
ba (�� a �У�Ҳ�� b ��) - ����
an (�� a �У�Ҳ�� b ��) - ����
ban (�� a �У�Ҳ�� b ��) - ����
na (�� a �У����� b ��)
ana (�� a �У����� b ��)
nan (�� a �У����� b ��)
bana (�� a �У����� b ��)
anan (�� a �У����� b ��)
banan (�� a �У����� b ��)
banana (�� a �У����� b ��)
ͳ�Ʒ����������Ӵ�������"", "a", "b", "n", "ba", "an", "ban"��

�ܹ��� 7 ����
*/
#include <iostream>  // ��������������� cin, cout
#include <string>    // ���� string ��
#include <set>       // ���� set �������洢Ψһ���ַ���

// ʹ�������ռ䣬������д
using namespace std;

// ��������ȡһ���ַ���������Ψһ�Ӵ�
set<string> getAllUniqueSubstrings(const string &s)
{
    set<string> substrings;

    // ��ӿ��ַ�����������ĿҪ�󣬿��ַ����������ַ������Ӵ���
    substrings.insert("");

    // �������п��ܵ���ʼλ��
    for (int i = 0; i < s.length(); ++i)
    {
        // �������п��ܵĽ���λ�� (�ӵ�ǰ��ʼλ�õ��ַ���ĩβ)
        for (int j = i; j < s.length(); ++j)
        {
            // �� s ������ i ��ʼ������Ϊ (j - i + 1) ���Ӵ�
            substrings.insert(s.substr(i, j - i + 1));
        }
    }
    return substrings;
}

int main()
{
    // �Ż�����������ڴ����������ʱ���Ч��
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // cin.tie(NULL) ���Լ��� cin �������ٶ�
    int n; // ��������
    cin >> n;

    // ѭ������ÿ������
    while (n--)
    {
        string a, b;
        cin >> a >> b;

        // 1. ��ȡ�ַ��� a ������Ψһ�Ӵ�
        set<string> a_substrings = getAllUniqueSubstrings(a);

        // 2. ��ȡ�ַ��� b ������Ψһ�Ӵ�
        set<string> b_substrings = getAllUniqueSubstrings(b);

        int count = 0; // ͳ�Ʒ����������Ӵ�����

        // 3. ���� a ������Ψһ�Ӵ�����������Ƿ�Ҳ�� b ���Ӵ�������
        for (const string &sub : a_substrings)
        {
            // ʹ�� count ������ set �в����Ӵ��Ƿ����
            if (b_substrings.count(sub))
            {
                count++;
            }
        }

        // ��������ÿ�鰸������
        cout << count << endl;
    }

    return 0;
}