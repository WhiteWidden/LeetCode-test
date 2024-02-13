// wintertest32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i]
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。*/

#include <iostream>
#include <vector>
using namespace std;//跳跃游戏II
void numsinput(vector<int>& nums)
{
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    cout << "input element:";
    for (vector<int>::iterator a = nums.begin(); a != nums.end(); ++a)
    {
        cin >> *a;
    }

}
int jump(vector<int>& nums)//贪心算法,在第一次能跳的点中，找出第二次能跳到最远的点，作为下一跳的起点。
{
    int flag = 1;
    //int start = 0;
    int i = 0;
    while (i < nums.size())
    {
        int temp = i+nums[i];
        if (i + nums[i] >= nums.size() - 1)
        {
            break;
        }
        for (int j = i + 1; j <= nums[i] + i; ++j)
        {
            temp = (nums[j] + j) > temp ? nums[j] + j : temp;
            cout << "---" << endl;
        }
        for (int j = nums[i] + i; j > i; --j)
        {
            if (nums[j]+j == temp)
            {
                i = j;
                break;
            }
        }
        ++flag;
    }
    return flag;
}
int main()
{
    vector<int> nums;
    numsinput(nums);
    int min = jump(nums);
    cout << min << endl;
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
