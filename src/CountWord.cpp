
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 转小写函数
string toLower(string s)
{
    // 遍历字符串中的每个字符
    for (char c : s)
        // 如果字符是大写字母，则将其转换为小写字母
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
    // 返回转换后的字符串
    return s;
}
void fun01(int n)
{
        // 定义最多20个单词及其计数
    string w[20] = {""}; // w0 ~ w19
    int cnt[20] = {0};

    // 遍历输入的单词
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        // 将单词转换为小写
        s = toLower(s);

        bool found = false;
        // 遍历已记录的单词
        for (int j = 0; j < 20; ++j)
        {
            // 如果找到相同的单词，则计数加1
            if (w[j] == s)
            {
                cnt[j]++;
                found = true;
                break;
            }
            // 如果没有找到相同的单词，则将新单词记录下来，计数为1
            else if (w[j] == "" && !found)
            {
                w[j] = s;
                cnt[j] = 1;
                found = true;
                break;
            }
        }
    }

    // 找最大值
    int maxIndex = 0;
    for (int i = 1; i < 20; ++i)
    {
        // 如果找到计数更大的单词，则更新最大值
        if (cnt[i] > cnt[maxIndex])
        {
            maxIndex = i;
        }
    }

    // 输出出现次数最多的单词
    cout << w[maxIndex] << endl;
}
void fun02(int n)
{
     // 如果n小于1或者大于100，输出"Invalid input"并返回1
    if (n < 1 || n > 100)
    {
        cout << "Invalid input" << endl;
        return;
    }

    // 定义一个map，用于存储单词和出现次数
    map<string, int> cnt;
    // 定义一个变量，用于存储最大出现次数
    int max_count = -1;

    // 循环n次
    for (int i = 0; i < n; i++)
    {
        // 输入一个字符串s
        string s;
        cin >> s;
        // 如果s的长度大于30，输出"Word too long"并返回1
        if (s.length() > 30)
        {
            cout << "Word too long" << endl;
            return;
        }
        // 将s转换为小写
        //transform 是 C++ STL 中的一个算法，用来对一段范围内的元素逐个进行操作，并写入目标位置。
        //transform(起始位置, 结束位置, 输出位置, 操作函数);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // 将s和出现次数存入map中
        cnt[s]++;
        // 更新最大出现次数
        max_count = max(max_count, cnt[s]);
    }

    // 定义一个变量，用于存储出现最大次数的单词数量
    int max_num = 0;
    // 定义一个变量，用于存储出现最大次数的单词
    string result;

    // 遍历map中的所有元素
    for (const auto &p : cnt)
    {
        // 如果某个单词的出现次数等于最大出现次数
        if (p.second == max_count)
        {
            // 将该单词存入result中
            result = p.first;
            // 更新出现最大次数的单词数量
            max_num++;
        }
    }

    // 如果出现最大次数的单词数量为1，输出该单词
    if (max_num == 1)
    {
        cout << result << '\n';
        // 否则，输出"Unexpected: multiple max"
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
    // 调用函数fun01
    fun01(n);
    // 调用函数fun02
    fun02(n);
}





