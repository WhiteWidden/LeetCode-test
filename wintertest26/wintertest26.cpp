// wintertest26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//多数元素(本题有多种做法，包括排序，分治等，其中时间复杂度最低的是摩尔投票法)
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
//int majorityElement(vector<int>& nums)//这是初步想到的解法，排序后找到出现次数大于n/2的数即为所求。
//{
//    sort(nums.begin(), nums.end());
//    int temp = 0;
//    int slow = 0;
//    int fast = 0;
//    while (slow < nums.size() && fast < nums.size())
//    {
//        if (nums[slow] == nums[fast])
//        {
//            ++temp;
//        }
//        else if (nums[slow] != nums[fast])
//        {
//            slow = fast;
//            temp = 1;
//        }
//        if (temp > nums.size() / 2)
//        {
//            return nums[slow];
//        }
//        ++fast;
//    }
//    return -11111111111111;
//}
//int majorityElement(vector<int> nums)//实际上排序后，本题所给出的众数大于n/2，所以中位数一定是众数。
//{
//    sort(nums.begin(), nums.end());
//    return nums[nums.size() / 2];
//}
int majorityElement(vector<int>& nums)//摩尔投票法时间复杂度O（n），空间复杂度O(1)
{
    int votes = 0;
    int target = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (votes == 0)
        {
            target = nums[i];
        }
        if (nums[i] == target)
        {
            ++votes;
        }
        else
        {
            --votes;
        }
    }
    return target;
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    int result = majorityElement(nums);
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
