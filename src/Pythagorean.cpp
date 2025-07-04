// 勾股数是很有趣的数学概念。如果三个正整数 a,b,c，满足 a^2+b^2=c^2，而且 1≤a≤b≤c，我们就将 a,b,c 组成的三元组 (a,b,c) 称为勾股数。你能通过编程，数数有多少组勾股数，能够满足 c≤n 吗？

// 输入格式
// 输入一行，包含一个正整数 n。约定 1≤n≤1000。

// 输出格式
// 输出一行，包含一个整数 C，表示有 C 组满足条件的勾股数。

// 输入输出样例
// 输入 
// 5
// 输出
// 1
// 输入
// 13
// 输出
// 3
// 说明/提示
// 【样例解释 1】
// 满足 c≤5 的勾股数只有 (3,4,5) 一组。
// 【样例解释 2】
// 满足 c≤13 的勾股数有 3 组，即 (3,4,5)、(6,8,10) 和 (5,12,13)。
#include <iostream>
using namespace std;

int main()
{
    // 定义变量n，用于存储输入的整数
    int n;
    // 从标准输入流中读取整数n
    cin >> n;
    // 定义变量count，用于存储满足条件的整数对的数量
    int count = 0;
    // 外层循环，遍历从1到n的所有整数
    for (int a = 1; a <= n; a++)
    {
        // 中层循环，遍历从a到n的所有整数
        for (int b = a; b <= n; b++)
        {
            // 内层循环，遍历从b到n的所有整数
            for (int c = b; c <= n; c++)
            {
                // 判断是否满足勾股定理
                if (a * a + b * b == c * c)
                {
                    // 如果满足，则计数器加1
                    count++;
                }
            }
        }

    }
    // 输出满足条件的整数对的数量
    cout << count << endl;
}