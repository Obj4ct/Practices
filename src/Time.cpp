// 小明在为自己规划学习时间。现在他想知道两个时刻之间有多少分钟，你能通过编程帮他做到吗？

// 输入格式
// 输入 4 行，第一行为开始时刻的小时，第二行为开始时刻的分钟，第三行为结束时刻的小时，第四行为结束时刻的分钟。输入保证两个时刻是同一天，开始时刻一定在结束时刻之前。时刻使用 24 小时制，即小时在 0 到 23 之间，分钟在 0 到 59 之间。

// 输出格式
// 输出一行，包含一个整数，从开始时刻到结束时刻之间有多少分钟。

// 输入输出样例
// 输入 
// 9
// 5
// 9
// 6

// 输出
// 1
// 输入
// 9
// 5
// 10
// 0

// 输出
// 55

#include <iostream>
using namespace std;

int main()
{
    // 定义开始时间和结束时间的小时和分钟
    int start_hour, start_minute, end_hour, end_minute;
    // 从标准输入读取开始时间和结束时间的小时和分钟
    cin >> start_hour >> start_minute >> end_hour >> end_minute;
    // 将开始时间和结束时间转换为分钟数
    int start_time = start_hour * 60 + start_minute;
    int end_time = end_hour * 60 + end_minute;
    // 输出结束时间与开始时间的分钟差
    cout << end_time - start_time << endl;
}