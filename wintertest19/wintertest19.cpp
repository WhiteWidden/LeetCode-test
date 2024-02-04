// wintertest19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;//反转字符串中的单词III
void inputs(string& s)
{
    cout << "input s:";
    getline(cin, s);
}
string reverseWords(string s)
{
    int i = 0, j = 0;
    s.resize(s.size() + 1, ' ');
    while (j < s.size())
    {
        if (s[j] == ' ')
        {
            
            for (int k = i; k < (j - 1 + i) / 2 + 1; ++k)
            {
                swap(s[k], s[j + i - k - 1]);
            }
            i = j + 1;
        }
        ++j;
    }
    s.erase(s.end()-1);
    return s;
}
int main()
{
    string s;
    inputs(s);
    s = reverseWords(s);
    cout << s;
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
