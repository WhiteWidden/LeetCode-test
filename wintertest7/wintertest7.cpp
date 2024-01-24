// wintertest7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;//给你一个字符串 s，找到 s 中最长的回文子串。
string input(string &a)
{
    cout << "input:" << endl;
    cin >> a;
    return a;
}
int main()//中心扩展法
{
    string s;
    input(s);
    int mid;
    int len = 1;
    //string res;
    //if (s.size() == 1)
    //{
    //    cout << s;
    //}
    //else 
    //{
    //    //中心扩展算法
    //    //从每一个位置mid出发，向两边扩散
    //    int maxLeft = 0;//记录最长回文子串的起点
    //    int maxRight = 0;//记录最长回文子串的终点
    //    int maxlen = 0;//记录最长回文子串的长度
    //    for (int mid = 0; mid < s.size(); ++mid) {
    //        int left = mid - 1;
    //        int right = mid + 1;
    //        //向左侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
    //        while (left >= 0 && s[left] == s[mid]) {
    //            left--;//left字符与mid字符一致，继续左移
    //            len++;//与mid字符一致，回文长度+1
    //        }
    //        //向右侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
    //        while (right <= s.size() - 1 && s[right] == s[mid]) {
    //            right++;//right字符与mid字符一致，继续左移
    //            len++;//与mid字符一致，回文长度+1
    //        }
    //        //同时向左右两侧扩展
    //        while (left >= 0 && right <= s.size() - 1 && s[left] == s[right]) {//同时向两面扩散
    //            //注意此处，在最后一次循环中，即最长回文子串索引为：i~j，此时的left=i-1，right=j+1
    //            left--;
    //            right++;
    //            len += 2;
    //        }
    //        if (len > maxlen) {
    //            maxLeft = left;
    //            maxRight = right;
    //            maxlen = len;
    //        }
    //        len = 1;
    //    }
    //    //返回子串,从pos位开始，长度为len
    //    //return s.substr(maxLeft + 1, maxlen);
    //    s=s.substr(maxLeft + 1, maxlen);
    //    cout << s;
    //}
    int maxleft = 0, maxright = 0, maxlen = 0;
    for (mid = 0; mid < s.size(); mid++)
    {
        int left = mid - 1;
        int right = mid + 1;
        while (left >= 0&&s[left]==s[mid])
        {
            left--;
            len++;
        }
        while ((right <= s.size() - 1) && s[right] == s[mid])
        {
            right++;
            len++;
        }
        while ((left >= 0) && (right <= s.size() - 1) && s[left] == s[right])
        {
            left--;
            right++;
            len += 2;
        }
        if (len > maxlen)
        {
            maxleft = left;
            maxright = right;
            maxlen = len;
        }
        len = 1;
    }
    s = s.substr(maxleft + 1, maxlen);
    cout << s;
}


//一种效率低下的方法
//string st;
    //string sm;
    //int temp;
    //for (int i = 0; i < size(s); ++i)
    //{
    //    for (int j = i+1; j < size(s); ++j)
    //    {
    //        if (s[i] == s[j])
    //        {
    //            temp = i + j;
    //            for (int k = i; k <= j ; ++k)
    //            {
    //                if (s[k] != s[temp - k])
    //                {
    //                    st.erase(0);
    //                    break;
    //                }
    //                else
    //                {
    //                    st.push_back(s[k]);
    //                    //cout << "st:" << st << endl;
    //                }
    //            }
    //            if (st.size() > sm.size())
    //            {
    //                sm .erase(0);
    //                sm = st;
    //            }
    //            st.erase(0);
    //        }
    //    }
    //}
    //if (sm == "")
    //{
    //    sm.push_back(s[0]);
    //}
    //cout << "sm:" << sm << endl;
    //
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
