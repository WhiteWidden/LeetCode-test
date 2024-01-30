// wintertest10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
                    //如果 needle 不是 haystack 的一部分，则返回  -1 。
                    //ps:本题可以看作是对c++ find函数的一次实现。
vector<int> Next(string needle)//利用kmp实现
{
	vector<int> next;
	next.push_back(0);	//next容器的首位必定为0
	for (int i = 1, j = 0; i < needle.length(); i++)
	{
		while (j > 0 && needle[j] != needle[i])
		{
			j = next[j - 1];
		}
		if (needle[i] == needle[j])
		{
			j++;
		}
		next.push_back(j);
	}
	return next;
}
int KMP(string& needle, string& haystack)
{
	int des;
	vector<int>next = Next(needle);
	for (int i = 0, j = 0; i < haystack.length(); i++)
	{
		while (j > 0 && haystack[i] != needle[j])
		{
			j = next[j - 1];
		}
		if (haystack[i] == needle[j])
		{
			j++;
		}
		if (j == needle.length())
		{
			des = i - j + 1;
			//cout << "Found pattern at " << des << " position" << endl;
			j = next[j - 1];
			return des;
		}
	}
	return -1;
}
int main()
{
	string needle, haystack;
	int flag;
	cout << "input haystack:";
	getline(cin, haystack);
	cout << "input needle:";
	getline(cin, needle);
	flag = KMP(needle, haystack);
	cout << flag;
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
