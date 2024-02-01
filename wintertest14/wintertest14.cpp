// wintertest14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cwuyj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//移除元素
int numsinput(vector<int>& nums)
{
    int n, val;
    cout << "input n:";
    cin >> n;
    if (n >= 0)
    {
        nums.resize(n);
        cout << "input number:";
        for (vector<int>::iterator a = nums.begin(); a != nums.end(); ++a)
        {
            cin >> *a;
        }
        cout << "input val:";
        cin >> val;
        return val;
    }
    else
    {
        cout << "invalid input!" << endl;
        return -1;
    }
}
int removeElement(vector<int>& nums, int val)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    auto fast=nums.begin(), slow=nums.begin();
    while (fast!=nums.end()&&slow!=nums.end())
    {
        if (*fast!=val)
        {
            *slow = *fast;
            ++slow;
        }
        ++fast;
    }
    //nums.erase(slow+1, nums.end()-1);
    return distance(nums.begin(),slow);
}
int main()
{
    vector<int> nums;
    int val = numsinput(nums);
    int len = removeElement(nums, val);
    cout << "length:" << len << endl;
    for (vector<int>::iterator a = nums.begin(); a != nums.end(); ++a)
    {
        cout << *a << " ";
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
