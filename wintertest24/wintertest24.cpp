// wintertest24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//合并两个有序数组
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
void numsoutput(vector<int>& nums)
{
    cout << "the nums:";
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cout << *a << " ";
    }
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    while (m > 0 || n > 0)
    {
        if (n == 0)
        {
            break;
        }
        if (m > 0 && nums1[m - 1] >= nums2[n - 1])
        {
            nums1[m + n - 1] = nums1[m - 1];
            --m;
        }
        else
        {
            nums1[m + n - 1] = nums2[n - 1];
            --n;
        }
    }
}
int main()
{
    vector<int> nums1, nums2;
    numsinput(nums1);
    numsinput(nums2);
    int m = nums1.size();
    int n = nums2.size();
    nums1.resize(m + n);
    merge(nums1, m, nums2, n);
    numsoutput(nums1);
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
