//超级回文字符串
//定义一个字符串的奇数长度子串为：以字符串第0号位置开始，长度为奇数的连续子串。例如字符串“abababa”的奇数长度子串有：“a”、“aba”、“ababa”、“abababa”等。
// 如果一个字符串同时满足以下两个条件：
// 字符串本身是回文字符串；
// 以0号位开始的所有奇数长度子串都是回文字符串；
// 则称该字符串为宇宙无敌回文字符串。
// 现在，给定一个字符串，判断它是否是宇宙无敌回文字符串。
#include <iostream>
#include <string>
using namespace std;

// 判断一个字符串是否回文
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

// 判断从0号位开始的所有奇数长度子串是否都是回文串
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

// 判断是否为“宇宙无敌回文字符串”
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
