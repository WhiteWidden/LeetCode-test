// wintertest33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。

根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。
如果 h 有多种可能的值，h 指数 是其中最大的那个。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//H指数
//寻找一个数 h，h 表示 citations 数组中至少有 h 个数，并且这 h 个数都大于等于 h。
void numsinput(vector<int>& nums)
{
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    cout << "input elements:";
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cin >> *a;
    }

}
int hIndex(vector<int>& citations)
{
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size() ; ++i)
    {
        if (citations[i] >= citations.size() - i)
        {
            return citations.size() - i;
        }
    }
    return 0;
}
int main()
{
    vector<int> citations;
    numsinput(citations);
    int result = hIndex(citations);
    cout << result << endl;
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
