// wintertest28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;//买卖股票的最佳时机
int getrand(int min, int max)
{
    return (rand() % (max - min) + min + 1);
}
void pricesinput(vector<int> &prices)
{
    srand(time(0));
    int n;
    cout << "input days:";
    cin >> n;
    prices.resize(n);
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
//int maxProfit(vector<int>& prices)//暴力法，O（n²）
//{
//    //int temp = prices[0];
//    int max = 0;
//    for (int i = 0; i < prices.size(); ++i)
//    {
//        for (int j = i + 1; j < prices.size(); ++j)
//        {
//            if (prices[j] - prices[i] > max)
//            {
//                max = prices[j] - prices[i];
//            }
//        }
//    }
//    return max;
//}
int maxProfit(vector<int>& prices)//贪心\动态规划
{
    int cost = 1000000;//记录前i天的最低成本
    int profit = 0;//记录前i天的最大利润
    for (int i = 0; i < prices.size(); ++i)
    {
        cost = min(cost, prices[i]);
        profit = max(profit, prices[i] - cost);
    }
    return profit;
}
int main()
{
    vector<int> prices;
    pricesinput(prices);
    int pro = maxProfit(prices);
    cout << "max profit:" << pro << endl;
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
