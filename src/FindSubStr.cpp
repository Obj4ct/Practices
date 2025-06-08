/*
已知由小写字母组成的两个字符串a和b，问a的子串中有多少个也同时是b的子串。在统计过程中，如果遇到a的子串重复多次出现，则算作一个。

注意几个事项：任意字符串都是自己的子串，空字符串是任意字符串的子串。

输入描述一个正整数n，表示案例的数量。（n<=50）

每组案例中有两个由小写字母组成的字符串a和b。（字符串长度均不大于100）

输出描述针对每组案例，输出一个整数，表示满足条件的子串数量。

每组案例输出完都要换行。

样例输入
1
banana ban
样例输出
7

解释：

字符串 a 是 "banana"，字符串 b 是 "ban"。

首先，我们列出 a ("banana") 的所有不重复子串：

长度 0: ""
长度 1: a, b, n
长度 2: ba, an, na
长度 3: ban, ana, nan
长度 4: bana, anan
长度 5: banan
长度 6: banana
接下来，我们列出 b ("ban") 的所有不重复子串：

长度 0: ""
长度 1: b, a, n
长度 2: ba, an
长度 3: ban
现在，我们找出 a 的子串中，哪些也同时出现在 b 的子串列表中：

"" (在 a 中，也在 b 中) - 符合
a (在 a 中，也在 b 中) - 符合
b (在 a 中，也在 b 中) - 符合
n (在 a 中，也在 b 中) - 符合
ba (在 a 中，也在 b 中) - 符合
an (在 a 中，也在 b 中) - 符合
ban (在 a 中，也在 b 中) - 符合
na (在 a 中，不在 b 中)
ana (在 a 中，不在 b 中)
nan (在 a 中，不在 b 中)
bana (在 a 中，不在 b 中)
anan (在 a 中，不在 b 中)
banan (在 a 中，不在 b 中)
banana (在 a 中，不在 b 中)
统计符合条件的子串数量："", "a", "b", "n", "ba", "an", "ban"。

总共有 7 个。
*/
#include <iostream>  // 用于输入输出，如 cin, cout
#include <string>    // 用于 string 类
#include <set>       // 用于 set 容器，存储唯一的字符串

// 使用命名空间，方便书写
using namespace std;

// 函数：获取一个字符串的所有唯一子串
set<string> getAllUniqueSubstrings(const string &s)
{
    set<string> substrings;

    // 添加空字符串（根据题目要求，空字符串是任意字符串的子串）
    substrings.insert("");

    // 遍历所有可能的起始位置
    for (int i = 0; i < s.length(); ++i)
    {
        // 遍历所有可能的结束位置 (从当前起始位置到字符串末尾)
        for (int j = i; j < s.length(); ++j)
        {
            // 从 s 的索引 i 开始，长度为 (j - i + 1) 的子串
            substrings.insert(s.substr(i, j - i + 1));
        }
    }
    return substrings;
}

int main()
{
    // 优化输入输出，在处理大量数据时提高效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // cin.tie(NULL) 可以加速 cin 的输入速度
    int n; // 案例数量
    cin >> n;

    // 循环处理每个案例
    while (n--)
    {
        string a, b;
        cin >> a >> b;

        // 1. 获取字符串 a 的所有唯一子串
        set<string> a_substrings = getAllUniqueSubstrings(a);

        // 2. 获取字符串 b 的所有唯一子串
        set<string> b_substrings = getAllUniqueSubstrings(b);

        int count = 0; // 统计符合条件的子串数量

        // 3. 遍历 a 的所有唯一子串，检查它们是否也在 b 的子串集合中
        for (const string &sub : a_substrings)
        {
            // 使用 count 方法在 set 中查找子串是否存在
            if (b_substrings.count(sub))
            {
                count++;
            }
        }

        // 输出结果，每组案例后换行
        cout << count << endl;
    }

    return 0;
}