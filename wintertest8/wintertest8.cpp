// wintertest8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <istream>
#include <algorithm>
#include <cmath>
using namespace std;//给你一个字符串 s ，请你反转字符串中单词的顺序。
//一种高效方法：思想：先将字符串整体反转，再将每个单词反转。
/*
* reverse(s.begin(), s.end());//反转字符串
        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
*/
int main()
{
    string s;
    getline(cin, s);
    //char space = ' ';
    for (int i = 0; i < s.size(); ++i)//去除重复空格
    {
        if (int(s[i]) == 32 && int(s[i + 1]) == 32)
        {
            s.erase(i, 1);
            i--;         
        }
    }
    if (int(s[s.size() - 1]) == 32)//检查末尾是否有空格，如果有，删除
    {
        s.erase(s.size() - 1, 1);
    }
    if (int(s[0]) == 32)
    {
        s.erase(0, 1);
    }
    int flag = 0;
    int i = s.size() - 1;
    while (i >= 0 && flag < s.size() - 1)
    {
        if (int(s[i]) == 32)
        {
            string temp = s.substr(i + 1, s.size() - i);
            temp=temp + "*";
            //cout << temp << endl;
            for (int j = s.size() - 1; j >= temp.size()+flag; --j)
            {
                s[j] = s[j - temp.size()];
            }
            //cout << s << endl;
            s = s.replace(flag, temp.size(), temp);
            //cout << s << endl;
            flag = flag + temp.size();
            i = s.size() - 1;
        }
        --i;
    }
    replace(s.begin(), s.end(),'*', ' ');
    cout << "-------------------------" << endl;
    cout << s << endl;
    cout << s.size() << endl;
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
