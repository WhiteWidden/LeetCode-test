// wintertest35.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;//最后一个单词的长度
void stringinput(string& s)
{
    cout << "input s:" << endl;
    getline(cin, s);
    //cout << s << endl;
}
int lengthOfLastWord(string s)
{
    int result = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] != ' ')
        {
            ++result;
        }
        else if (result != 0)
        {
            return result;
        }
    }
    return result;
}
int main()
{
    string s;
    stringinput(s);
    int i = lengthOfLastWord(s);
    cout << i << endl;
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
