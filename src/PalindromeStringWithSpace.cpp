// ���뿪��һ���ǳ��ر����Ϸ����Ϸ�е��������(���ܰ����ո�)�������Ŷ��ͷ��Ŷ���һ���������ܽ��������Ϸ��Ϊ��ȷ������Ƕ���ʹ���Լ�ϲ�������֣������дһ����������˸������ǳ��Ƿ��������Ҫ��(��ʵ���ǻ����ַ���)
// �����ʽ:����һ���ǳƣ����ܰ����ո�(��Сд����)��
// �����ʽ:
// ����ǳ��ǻ��ģ������Yes";������ǻ��ģ������No"����:
// ����:
// l           e            v  e                         l
// ���:
// Yes
// ����:
// le vel
// ���:
// yes
// ����:
// leve l
// ���:
// Yes
// ����:
// He11o
// ���:
// No
// ��ʾ:������ǳƿ����кö���ո񣬵������ж��Ƿ��ǻ���ʱ���Կո�
// ������ʾ:string newstr="";����һ�����ַ���,����Ϊ0,���԰Ѿɵ��ַ���ͨ��ѭ������µ��ַ�������ȥ,""�м�û�пո��пո�����ַ������ȾͲ���0��!
#include <iostream> // �����������
#include <string>   // �����ַ�������
#include <cctype>
int main()
{
    // �Ż�������������Ч��
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string original_nickname;
    // ʹ�� getline ��ȡһ���У������ո�
    std::getline(std::cin, original_nickname);

    std::string processed_nickname = ""; // ���ڴ洢�Ƴ��ո����ַ�

    // ����ԭʼ�ַ��������ǿո��ַ���ӵ����ַ���
    // ʹ�÷�Χforѭ����C++11�����ϣ�
    for (char c : original_nickname)
    {   
        // ���ַ�ת��ΪСд���Ա㲻���ִ�Сд
        c=tolower(c);
        // ����ַ����ǿո�����ӵ� processed_nickname
        if (c != ' ')
        {
            processed_nickname += c;
        }
    }

    // �ֶ���ת processed_nickname
    std::string reversed_nickname = "";
    // �� processed_nickname ��ĩβ��ʼ��ǰ����������ӵ� reversed_nickname
    for (int i = processed_nickname.length() - 1; i >= 0; --i)
    {
        reversed_nickname += processed_nickname[i];
    }

    // �Ƚϴ������ַ����ͷ�ת����ַ���
    if (processed_nickname == reversed_nickname)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
