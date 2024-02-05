// wintertest21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//移动零
void numsinput(vector<int>& nums)
{
    int n;
    cout << "input n:";
    cin >> n;
    cout << "input elements:";
    nums.resize(n);
    auto i = nums.begin();
    for (; i != nums.end(); ++i)
    {
        cin >> *i;
    }
}
//void moveZeroes(vector<int>& nums)//暴力法，用时较长
//{
//    int temp = 0;
//    int j = 0;
//    int zero = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        if (nums[i] == 0)
//        {
//            ++zero;
//        }
//    }
//    while (temp < nums.size())
//    {
//        if (nums[temp] == 0)
//        {
//            for (int i = temp + 1; i < nums.size(); ++i)
//            {
//                if (nums[i] != 0)
//                {
//                    j = i - temp - 1;
//                    //zero = zero + j;
//                    break;
//                }
//            }
//            for (int i = temp; i < nums.size() - j - 1; ++i)
//            {
//                nums[i] = nums[i + j + 1];
//            }
//        }
//        ++temp;
//    }
//    cout << zero << endl;
//    for (int i = 0; i < zero; ++i)
//    {
//        nums[nums.size() - 1 - i] = 0;
//    }
//}
void moveZeroes(vector<int>& nums)//双指针(快慢指针)
{
    int slow = 0;
    for (int quick = 0; quick < nums.size(); ++quick)
    {
        if (nums[quick] != 0)
        {
            nums[slow] = nums[quick];
            ++slow;
        }
    }
    for (; slow < nums.size(); slow++) 
    {
        nums[slow] = 0;
    }
}
void numsoutput(vector<int>& nums)
{
    cout << "nums:";
    for (auto a = nums.begin(); a != nums.end(); ++a)
    {
        cout << *a << " ";
    }
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    moveZeroes(nums);
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
