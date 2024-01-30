// wintertest12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。

返回该 最大总和 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c24he/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//数组拆分I
void input(vector<int> &nums)
{
    int n;
    cout << "input n(n%2=0):";
    cin >> n;
    if (n % 2 == 1 || n < 0)
    {
        cout << "无效的n！！" << endl;
    }
    else
    {
        nums.resize(n);
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            cin >> *it;
        }
    }
}
int arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i % 2 == 0)
        {
            sum = sum + nums[i];
        }
    }
    return sum;
}
int main()
{
    vector<int> nums;
    input(nums);
    cout << "-------------------------" << endl;
    if (nums.size() != 0)
    {
        int result = arrayPairSum(nums);
        cout << result;
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
