// wintertest25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//删除有序数组中的重复项II
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
    sort(nums.begin(), nums.end());
}
int removeDuplicates(vector<int>& nums,int i)//i为每个元素最多可重复的次数
{
    if (nums.size() <= 2)
    {
        return nums.size();
    }
    int slow = 0;
    int fast = 1;
    int temp = i-1;
    while (slow < nums.size() && fast < nums.size())
    {
        if (nums[slow] != nums[fast])
        {
            temp = i-1;
            ++slow;
            nums[slow] = nums[fast];
        }
        else if (temp > 0)
        {
            ++slow;
            nums[slow] = nums[fast];
            --temp;
        }
        else 
        {
            --temp;
        }
        ++fast;
    }
    return slow + 1;
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    int length = removeDuplicates(nums,2);
    cout << length << endl;
    for (int i = 0; i < length; ++i)
    {
        cout << nums[i] << " ";
    }
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
