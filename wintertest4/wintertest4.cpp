// wintertest4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
int getRand(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}
int main()//利用容器实现的一种数组去重方式。（会改变次序）
{
    srand(time(0));
    int row, column;
    vector<vector<int>> test;
    vector<int>::iterator temp;
    cout << "input row:";
    cin >> row;
    cout << "input column:";
    cin >> column;
    test.resize(row);
    for (int i = 0; i < row; i++)
    {
        test[i].resize(column);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            test[i][j] = getRand(0, 10);
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < row; i++)
    {

        sort(test[i].begin(), test[i].end());
        test[i].erase(unique(test[i].begin(), test[i].end()), test[i].end());
        for (int j = 0; j < test[i].size(); j++)
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
