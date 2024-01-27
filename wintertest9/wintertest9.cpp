// wintertest9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;//KMP算法的实现
vector<int> Next(string pattern)
{
	vector<int> next;
	next.push_back(0);	//next容器的首位必定为0
	for (int i = 1, j = 0; i < pattern.length(); i++)
	{
		while (j > 0 && pattern[j] != pattern[i])
		{
			j = next[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			j++;
		}
		next.push_back(j);
	}
	return next;
}
void KMP(string& pattern, string& target)
{
	vector<int>next = Next(pattern);
	for (int i = 0, j = 0; i < target.length(); i++)
	{
		while (j > 0 && target[i] != pattern[j])
		{
			j = next[j - 1];
		}
		if (target[i] == pattern[j])
		{
			j++;
		}
		if (j == pattern.length())
		{
			cout << "Found pattern at " << i - j + 1 << " position" << endl;
			j = next[j - 1];
		}
	}
}
int main()
{
	string pattern,target;
	cout << "input pattern:";
	getline(cin, pattern);
	cout << "input target:";
	getline(cin, target);
	KMP(pattern, target);
	return 0;
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
