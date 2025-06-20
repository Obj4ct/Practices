// 你想开发一个非常特别的游戏，游戏中的玩家名称(可能包含空格)必须正着读和反着读都一样，否则不能进入这个游戏。为了确保玩家们都能使用自己喜欢的名字，你决定写一个程序来检査给定的昵称是否满足这个要求。(其实就是回文字符串)
// 输入格式:输入一个昵称，可能包含空格(大小写敏感)。
// 输出格式:
// 如果昵称是回文，输出“Yes";如果不是回文，输出“No"例如:
// 输入:
// l           e            v  e                         l
// 输出:
// Yes
// 输入:
// le vel
// 输出:
// yes
// 输入:
// leve l
// 输出:
// Yes
// 输入:
// He11o
// 输出:
// No
// 提示:输入的昵称可以有好多个空格，但是在判断是否是回文时忽略空格。
// 代码提示:string newstr="";定义一个空字符串,长度为0,可以把旧的字符串通过循环存进新的字符串里面去,""中间没有空格，有空格这个字符串长度就不是0了!
#include <iostream> // 用于输入输出
#include <string>   // 用于字符串操作
#include <cctype>
int main()
{
    // 优化输入输出，提高效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string original_nickname;
    // 使用 getline 读取一整行，包括空格
    std::getline(std::cin, original_nickname);

    std::string processed_nickname = ""; // 用于存储移除空格后的字符

    // 遍历原始字符串，将非空格字符添加到新字符串
    // 使用范围for循环（C++11及以上）
    for (char c : original_nickname)
    {   
        // 将字符转换为小写，以便不区分大小写
        c=tolower(c);
        // 如果字符不是空格，则添加到 processed_nickname
        if (c != ' ')
        {
            processed_nickname += c;
        }
    }

    // 手动反转 processed_nickname
    std::string reversed_nickname = "";
    // 从 processed_nickname 的末尾开始向前遍历，并添加到 reversed_nickname
    for (int i = processed_nickname.length() - 1; i >= 0; --i)
    {
        reversed_nickname += processed_nickname[i];
    }

    // 比较处理后的字符串和反转后的字符串
    if (processed_nickname == reversed_nickname)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
