// 问题描述
// 超市促销，第二件半价，之后的每一件都是上一件的半价。
// 假设某商品的原价是 a 元，现在需要购买 b 件该商品，输出需要花多少钱。
// 输入描述
// 两个正整数 a 和 b 含义如描述。（1 ≤ a、b ≤ 10）
// 输出描述
// 在一行中输出需要花的钱数，保留两位小数。
// 样例输入
// 8 4
// 样例输出
// 15.00

#include <iostream>

// 使用命名空间，方便书写
using namespace std;

int main() 
{
    // 优化输入输出，提高效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b; // a: 原价, b: 购买数量
    cin >> a >> b;

    double total_cost = 0.0;
    double current_price = a; // 第一件商品的原价

    // 第一件商品
    total_cost += current_price;

    // 从第二件商品开始计算
    for (int i = 2; i <= b; ++i) 
    {
        current_price /= 2.0; // 每一件是上一件的半价
        total_cost += current_price;
    }

    // 设置输出精度为两位小数
    printf("%.2f\n", total_cost);

    return 0;
}