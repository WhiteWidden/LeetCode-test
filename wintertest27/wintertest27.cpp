// wintertest27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;//轮转数组
int getrand(int min, int max)
{
    return (rand() % (max - min) + min + 1);
}
void numsinput(vector<int>& nums)
{
    srand(time(0));
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        *a = getrand(0, 10);
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
void rotate(vector<int>& nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    numsoutput(nums);
    int k;
    cout << "input k:";
    cin >> k;
    rotate(nums, k);
    numsoutput(nums);
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
