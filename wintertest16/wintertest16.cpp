// wintertest16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c0w4r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;//长度最小的子数组
void numsinput(vector<int>& nums)
{
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cin >> *a;
    }
}
//int minSubArrayLen(int target, vector<int>& nums)//一种较为费时的做法。
//{
//    int slow = 0, fast = 0, temp = 0, sum = 0, min = 0;
//    while (fast < nums.size())
//    {
//        sum = sum + nums[fast];
//        if (sum < target)
//        {
//            ++fast;
//        }
//        else
//        {
//            temp = fast - slow + 1;
//            if (min == 0 || temp < min)
//            {
//                min = temp;
//            }
//            sum = 0;
//            temp = 0;
//            fast = slow + 1;
//            ++slow;
//        }
//    }
//    return min;
//}
int minSubArrayLen(int target, vector<int>& nums)//滑动窗口法O(n)
{
    int result = INT32_MAX;
    int i = 0;
    int temp = 0;
    int sum = 0;
    for (int j = 0; j < nums.size(); ++j)
    {
        sum = sum + nums[j];
        while (sum >= target)
        {
            temp = j - i + 1;
            if (temp < result)
            {
                result = temp;
            }
            sum = sum - nums[i];
            ++i;
        }
    }
    return result == INT32_MAX ? 0 : result;
}
int main()
{
    vector<int> nums;
    int target;
    numsinput(nums);
    cout << "input target:";
    cin >> target;
    int result=minSubArrayLen(target, nums);
    cout << "--------------------" << endl;
    cout << result;
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
