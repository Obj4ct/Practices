// ��������
// ���д������ڶ�����ۣ�֮���ÿһ��������һ���İ�ۡ�
// ����ĳ��Ʒ��ԭ���� a Ԫ��������Ҫ���� b ������Ʒ�������Ҫ������Ǯ��
// ��������
// ���������� a �� b ��������������1 �� a��b �� 10��
// �������
// ��һ���������Ҫ����Ǯ����������λС����
// ��������
// 8 4
// �������
// 15.00

#include <iostream>

// ʹ�������ռ䣬������д
using namespace std;

int main() 
{
    // �Ż�������������Ч��
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b; // a: ԭ��, b: ��������
    cin >> a >> b;

    double total_cost = 0.0;
    double current_price = a; // ��һ����Ʒ��ԭ��

    // ��һ����Ʒ
    total_cost += current_price;

    // �ӵڶ�����Ʒ��ʼ����
    for (int i = 2; i <= b; ++i) 
    {
        current_price /= 2.0; // ÿһ������һ���İ��
        total_cost += current_price;
    }

    // �����������Ϊ��λС��
    printf("%.2f\n", total_cost);

    return 0;
}