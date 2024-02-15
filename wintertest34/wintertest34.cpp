// wintertest34.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//除自身以外数组的乘积
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
void numsoutput(vector<int>& nums)
{
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cout << *a << " ";
    } 
    cout << endl;
}
vector<int> productExceptSelf(vector<int>& nums)//利用前缀积，后缀积，做到边算边存，很精妙的做法。
{
    vector<int> answer;
    answer.resize(nums.size());
    int left = 1, right = 1;
    for (int i = 0; i < nums.size(); ++i)//前缀积
    {
        answer[i] = left;
        left *= nums[i];
    }
    for (int j = nums.size() - 1; j >= 0; --j)//后缀积
    {
        answer[j] *= right;
        right *= nums[j];
    }
    return answer;
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    vector<int> result = productExceptSelf(nums);
    numsoutput(result);
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
