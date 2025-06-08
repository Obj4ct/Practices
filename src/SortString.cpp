// 问题描述将m个字符串按照以下规则排序：
// 1、先按照字符串长度的奇偶性排序：字符串长度是偶数的排在前面，字符串长度是奇数的排在后面。
// 2、对于字符串长度都是偶数的字符串，大写字母字符多的排前面；如果大写字母字符一样多，那么字符串值比较大的排前面。
// 3、对于字符串长度都是奇数的字符串，小写字母字符多的排前面；如果小写字母字符一样多，那么字符串值比较小的排前面。
// 把排序后的字符串依次输出出来。
// 输入描述只有一组案例。
// 一个正整数m，表示字符串的数量。然后是m个不含空格、'\t'、'\n'的字符串。（m<=100)
// 输出描述按照指定要求排序后，把排序后的字符串依次输出出来，每个字符串输出完都要换行。
// 样例输入
// 6
// AAA
// BBBBB
// AAAA
// CCCdd
// AAaa
// ABBA

// 样例输出
// ABBA
// AAAA
// AAaa
// CCCdd
// AAA
// BBBBB

#include <iostream>  // 用于输入输出，比如 cin 和 cout
#include <vector>    // 用于 std::vector，存储字符串的容器
#include <string>    // 用于 std::string，处理字符串
#include <algorithm> // 用于 std::sort，排序算法
#include <cctype>    // 用于 std::isupper 和 std::islower，检查字符大小写

int main()
{
    // 优化输入输出，这能让程序在处理大量数据时跑得更快，
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;                               // 声明一个整数变量 m，用于存储字符串的数量
    std::cout << "请输入字符串的数量: "; // 提示用户输入
    std::cin >> m;                       // 从键盘读取一个整数，存入 m

    std::vector<std::string> strings(m); // 创建一个名为 strings 的容器，可以存放 m 个字符串

    std::cout << "请输入 " << m << " 个字符串 (每个字符串输入后按回车):" << std::endl;
    // 循环 m 次，每次读取一个字符串
    for (int i = 0; i < m; ++i)
    {
        std::cin >> strings[i]; // 读取第 i 个字符串
    }

    // --- 核心部分：使用 Lambda 表达式作为排序规则 ---
    // std::sort 需要三个参数：
    // 1. 容器的开始位置 (strings.begin())
    // 2. 容器的结束位置 (strings.end())
    // 3. 比较函数 (Lambda 表达式)

    // 不带自定义比较函数（默认升序排序）：
    // std::sort(起始迭代器, 结束迭代器);
    // 例如：std::sort(my_vector.begin(), my_vector.end());
    // 这种用法会根据元素类型的默认 < 运算符（小于运算符）进行升序排序。对于数字，就是从小到大；对于字符串，就是按字典序从小到大。
    // 带自定义比较函数（可实现升序或降序)
    std::sort(strings.begin(), strings.end(),
              // 这是一个 Lambda 表达式的定义：
              // []           - 捕获列表，这里是空的，表示不从外部捕获变量 问在其定义范围之外（但它能看到的）的变量。
              // 想象一下 Lambda 表达式是一个小盒子，它有自己的参数（像 (const std::string& s1, const std::string& s2)），但有时候它还需要用到它外面的一些数据。捕获列表就是告诉这个小盒子，它需要把哪些外部数据“装”进来，以便在内部使用。
              //[]：不捕获任何外部变量。
              // [var]：按值捕获 var。
              // [&var]：按引用捕获 var。
              // [=]：按值捕获所有在 Lambda 中使用的外部变量。
              // [&]：按引用捕获所有在 Lambda 中使用的外部变量。
              // (const std::string& s1, const std::string& s2) - 参数列表，表示它接收两个字符串 s1 和 s2 进行比较
              // { ... }      - 函数体，包含了我们所有的比较逻辑
              [](const std::string &s1, const std::string &s2)
              {
                //true 表示：s1 应该排在 s2 的前面。
                //false 表示：s1 不应该排在 s2 的前面。
                  bool s1_is_even_len = (s1.length() % 2 == 0); // 判断 s1 长度是否为偶数
                  bool s2_is_even_len = (s2.length() % 2 == 0); // 判断 s2 长度是否为偶数

                  // 规则1：先按照字符串长度的奇偶性排序
                  // 偶数长度排前面，奇数长度排后面。
                  if (s1_is_even_len && !s2_is_even_len)
                  {
                      return true; // s1 是偶数，s2 是奇数，s1 应该排在前面
                  }
                  if (!s1_is_even_len && s2_is_even_len)
                  {
                      return false; // s1 是奇数，s2 是偶数，s2 应该排在 s1 前面 (所以 s1 不应该排前面)
                  }

                  // 如果两个字符串的长度奇偶性相同
                  if (s1_is_even_len&&s2_is_even_len)
                  { 
                      // 规则2：对于偶数长度的字符串
                      // 大写字母多的排前面；大写字母一样多，则字符串值大的排前面。

                      // 计算 s1 中大写字母的数量
                      int uc1 = 0;
                      for (char c : s1)
                      { // 遍历 s1 中的每个字符
                          if (std::isupper(c))
                          { // 如果字符是大写字母
                              uc1++;
                          }
                      }

                      // 计算 s2 中大写字母的数量
                      int uc2 = 0;
                      for (char c : s2)
                      {
                          if (std::isupper(c))
                          {
                              uc2++;
                          }
                      }

                      if (uc1 > uc2) // s1 的大写字母更多
                      {
                         return true; // s1 应该排在 s2 前面
                      }
                      else if (uc1 < uc2) // s2 的大写字母更多
                      {
                         return false; // s1 不应该排在 s2 前面 (即 s2 应该排在 s1 前面)
                      }
                      else // uc1 == uc2，大写字母数量相同
                      {
                         return s1 > s2; // 按照字符串值（字典序）大的排前面
                      }
                  }
                  else if(!s1_is_even_len&&!s2_is_even_len)
                  {   // 此时 s1 和 s2 都 是奇数长度
                      // 规则3：对于奇数长度的字符串
                      // 小写字母多的排前面；小写字母一样多，则字符串值小的排前面。

                      // 计算 s1 中小写字母的数量
                      int lc1 = 0;
                      for (char c : s1)
                      {
                          if (std::islower(c))
                          { // 如果字符是小写字母
                              lc1++;
                          }
                      }

                      // 计算 s2 中小写字母的数量
                      int lc2 = 0;
                      for (char c : s2)
                      {
                          if (std::islower(c))
                          {
                              lc2++;
                          }
                      }
                    if (lc1 > lc2) // s1 的小写字母更多
                    {
                        return true; // s1 应该排在 s2 前面
                        /* code */
                    }
                    else if (lc1 < lc2) // s2 的小写字母更多
                    {
                        return false; // s1 不应该排在 s2 前面 (即 s2 应该排在 s1 前面)

                    }
                    else
                    {
                        return s1 < s2; // 按照字符串值（字典序）小的排前面
                    }
                  }
              } // Lambda 表达式到此结束
    ); // std::sort 函数调用到此结束

    std::cout << "\n排序后的字符串为:" << std::endl;
    // 依次输出排序后的字符串
    for (const std::string &s : strings)
    {
        std::cout << s << std::endl;
    }

    return 0; // 程序成功执行
}