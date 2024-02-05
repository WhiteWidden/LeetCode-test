// wintertest20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cq376/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//删除排序数组中的重复项
void numsinput(vector<int>& nums)
{
	int n;
	cout << "input n:";
	cin >> n;
	nums.resize(n);
	auto i = nums.begin();
	cout << "input elements:";
	for (; i != nums.end(); ++i)
	{
		cin >> *i;
	}
	sort(nums.begin(), nums.end());
}
//int removeDuplicates(vector<int>& nums)//利用unique函数解决,用时略长
//{
//	nums.erase(unique(nums.begin(), nums.end()), nums.end());
//	int lentem = nums.size();
//	return lentem;
//}
int removeDuplicates(vector<int>& nums)//快慢指针
{
	int left = 0;
	int right = 0;
	while (right < nums.size())
	{
		if (nums[right] != nums[left])
		{
			++left;
			nums[left] = nums[right];
		}
		++right;
	}
	return left + 1;
}
int main()
{
	int length;
	vector<int> nums;
	numsinput(nums);
	length = removeDuplicates(nums);
	cout << length;
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
