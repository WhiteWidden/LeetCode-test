// wintertest6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>//编写一个函数来查找字符串数组中的最长公共前缀,如果不存在公共前缀，返回空字符串 ""。
using namespace std;
vector<string> createstr(vector<string>& a)
{
    int strnum,temp=0;
    cout << "input strnum:";
    cin >> strnum;
    string tempstr;
    while (strnum)
    {
        cin >> tempstr;
        a.push_back(tempstr);
        strnum--;
    }
    
    return a;
}
int main()
{
    vector<string> strs;
    createstr(strs);//输入数据
    cout << "---------------------" << endl;
    string flag = "";
    string result = "";
    int mins = 200;
    int lable = 0;
    for (int i = 0; i < strs.size(); ++i)
    {
        if (strs[i].size() < mins)
        {
            mins = strs[i].size();
        }
    }
    int i;
    for (i = 0; i < mins; ++i)
    {
        flag = strs[0][i];
        cout << "flag:" << flag << endl;
        for (int j = 0; j < strs.size(); ++j)
        {
            if (abs(flag.compare(0, 1, strs[j], i, 1)))
            {
                lable = 1;
                break;
            }
        }
        if (lable == 0)
        {
            result.append(flag);
        }
        else
        {
            break;
        }    
    }
    cout << endl << "---------------------" << endl;
    cout << "最大公共首串:" << result << endl;
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
