// wintertest17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//杨辉三角I
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> temp;
    temp.resize(numRows);
    for (int i = 0; i < numRows; ++i)
    {
        temp[i].resize(i + 1);
    }
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0 || j == i)
            {
                temp[i][j] = 1;
            }
            else
            {
                temp[i][j] = temp[i - 1][j - 1] + temp[i - 1][j];
            }
        }
    }
    return temp;
}
int main()
{
    int numRows;
    cout << "input numRows:";
    cin >> numRows;
    vector<vector<int>> test = generate(numRows);
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            cout << test[i][j] << " ";
        }
        cout << endl;
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
