// wintertest29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;//买卖股票的最佳时机II
int getrand(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}
void pricesinput(vector<int>& prices)
{
    srand(time(0));
    cout << "input day:";
    int day;
    cin >> day;
    prices.resize(day);
    for (auto a = prices.begin(); a != prices.end(); ++a)
    {
        *a = getrand(1, 10);
    }
    for (auto a = prices.begin(); a != prices.end(); ++a)
    {
        cout << *a << " ";
    }
    cout << endl;
}
int maxProfit(vector<int>& prices)//贪心，狠狠的贪心
{
    /*  int profit = 0;以下代码的简化形式
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] - prices[i-1] > 0) 
            {
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;*/
    int sum = 0;
    int slow = 0;
    int fast = 0;
    while (fast < prices.size() - 1 && slow < prices.size())
    {
        if (prices[fast] > prices[slow])
        {
            sum = sum + prices[fast] - prices[slow];
            slow = fast;
        }
        ++fast;
        if (prices[fast] <= prices[slow])
        {
            ++slow;
        }
    }
    if (prices[fast] > prices[slow])
    {
        sum = sum + prices[fast] - prices[slow];
    }
    return sum;
}
int main()
{
    vector<int> prices;
    pricesinput(prices);
    int pro = maxProfit(prices);
    cout << pro << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
