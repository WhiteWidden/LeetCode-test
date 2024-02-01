// wintertest15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。*/
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;//最大连续1的个数
int getrand(int min, int max)
{
    return (rand() % (max + 1 - min) + min);
}
void randnums(vector<int>& nums)
{
    srand(time(0));
    int n;
    cout << "input n:";
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = getrand(0, 1);
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int findMaxConsecutiveOnes(vector<int>& nums)
{
    int right = 0, maxlen = 0, temp = 0;
    while (right < nums.size())
    {
        if (nums[right] == 1)
        {
            ++temp;
            ++right;
            if (temp > maxlen)
            {
                maxlen = temp;
            }
            continue;
        }
        temp = 0;
        ++right;
    }
    return maxlen;
}
int main()
{
    vector<int> nums;
    randnums(nums);
    int result = findMaxConsecutiveOnes(nums);
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
