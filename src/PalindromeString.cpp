//回文字符串
//题目描述：判断一个字符串是否是回文字符串，即正读和反读都一样
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