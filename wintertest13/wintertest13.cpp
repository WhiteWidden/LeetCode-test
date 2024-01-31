// wintertest13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cnkjg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//两数之和 II - 输入有序数组
void numbersinput(vector<int> &numbers)
{
    int nums;
    cout << "input nums:";
    cin >> nums;
    numbers.resize(nums);
    cout << "input elements:";
    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
    {
        cin >> *i;
    }
    sort(numbers.begin(), numbers.end());
}
//vector<int> twoSum(vector<int>& numbers, int target) //初步想法，时间不通过，改用双指针。
//{
//    vector<int> result(2,-1);
//    float flag1 = target / 2;
//    for (int i = 0; i < numbers.size(); ++i)
//    {
//        if (result[1] != -1)
//            break;
//        else
//        {
//            for (int j = i + 1; j < numbers.size(); )
//            {
//                if (numbers[i] + numbers[j] == target)
//                {
//                    result[0] = i;
//                    result[1] = j;
//                    break;
//                }
//                else
//                    ++j;
//            }
//        }
//    }
//    return result;
//}
vector<int> twoSum(vector<int>& numbers, int target)//对撞指针解法
{
    vector<int> result(2, -1);
    vector<int>::iterator left, right;
    left = numbers.begin();
    right = numbers.end() - 1;
    while (left<right)
    {
        if (*left + *right == target)
        {
            result[0] = distance(numbers.begin(), left);
            result[1] = distance(numbers.begin(), right);
            break;
        }
        else if (*left + *right < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return result;
}
int main()
{
    vector<int> numbers;
    int target;
    numbersinput(numbers);
    cout << "input target:";
    cin >> target;
    vector<int> result(twoSum(numbers, target));
    cout << "index1=" << result[0] << endl;
    cout << "index2=" << result[1] << endl;
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
