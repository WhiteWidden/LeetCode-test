// wintertest30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//两数之和
int target;
void input(vector<int>& nums)
{
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    cout << "input elements:";
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cin >> *a;
        //*a = distance(a, nums.begin());
    }
}
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result = { -1,-1 };
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int left = 0;
    int right = temp.size() - 1;
    while (left < right)
    {
        if (temp[left] + temp[right] > target)
        {
            --right;
        }
        else if (temp[left] + temp[right] < target)
        {
            ++left;
        }
        else
        {
            result[0] = temp[left];
            result[1] = temp[right];
            break;
        }
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == result[0])
        {
            result[0] = i;
            break;
        }
    }
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        if (nums[i] == result[1])
        {
            result[1] = i;
            break;
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    cout << "input target:" << endl;
    cin >> target;
    input(nums);
    vector<int> a = twoSum(nums, target);
    cout << a[0] << "," << a[1] << endl;

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
