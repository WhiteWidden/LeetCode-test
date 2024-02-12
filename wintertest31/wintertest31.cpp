// wintertest31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//跳跃游戏
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
    cout << endl;
}
bool canJump(vector<int>& nums)
{
    int road = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > road)
        {
            return false;
        }
        road = max(road, nums[i] + i);
    }
    return true;
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    cout << canJump(nums) << endl;
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
