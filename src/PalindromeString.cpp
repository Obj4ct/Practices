//回文字符串
//题目描述：判断一个字符串是否是回文字符串，即正读和反读都一样
#include <iostream> 
#include <string>
using namespace std;

// 判断一个字符串是否是回文
bool isPalindromeString(string str)
{

    // 如果字符串为空，则返回false
    if (str.empty())
    {
        return false;
    }
    // 获取字符串的长度
    int len = str.length();
    // 遍历字符串的前半部分
    for (int i = 0; i < len / 2; i++)
    {
        // 如果字符串的前半部分和后半部分不相等，则返回false
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    // 如果字符串的前半部分和后半部分相等，则返回true
    return true;
}

int main()
{
    
    // 定义一个字符串变量
    string str;
    // 从标准输入读取一个字符串
    cin >> str;
    // 判断字符串是否为回文
    if (isPalindromeString(str))
    {
        // 如果是回文，输出true
        cout << "true" << endl;
    }
    else
    {
        // 如果不是回文，输出false
        cout << "false" << endl;
    }
}