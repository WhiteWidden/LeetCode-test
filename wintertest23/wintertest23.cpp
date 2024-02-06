// wintertest23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

 

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cxqdh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//搜索插入位置(二分查找)
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
int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    if (target < nums[left])
    {
        return 0;
    }
    while (left <= right)
    {
        if (target == nums[(left + right) / 2])
        {
            return (left + right) / 2;
        }
        else if (target > nums[(left + right) / 2])
        {
            left = (left + right) / 2 + 1;
        }
        else
        {
            right = (left + right) / 2 - 1;
        }
    }
    return left;
}
int main()
{
    vector<int> nums;
    int target;
    numsinput(nums);
    cout << "input target:";
    cin >> target;
    int des = searchInsert(nums, target);
    cout << des;
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
