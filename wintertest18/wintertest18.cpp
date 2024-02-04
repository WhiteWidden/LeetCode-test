// wintertest18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//杨辉三角II
//vector<int> getRow(int rowIndex)//一种递归实现，超过九个就超时了,2333
//{
//    vector<int> temp;
//    temp.resize(rowIndex + 1);
//    temp[0] = 1;
//    temp[rowIndex] = 1;
//    for (int i = 1; i < rowIndex; ++i)
//    {
//        temp[i] = getRow(rowIndex - 1)[i] + getRow(rowIndex - 1)[i - 1];
//    }
//    return temp;
//}
vector<int> getRow(int rowIndex)//倒序迭代法，空间复杂度O（n）
{
    vector<int> temp;
    temp.resize(rowIndex + 1, 1);
    if (rowIndex < 2)
    {
        return temp;
    }
    else
    {
        for (int i = 1; i < rowIndex; ++i)//i是迭代次数，也是内循环每次调整的起始元素下标
        {
            for (int j = i; j > 0; --j)
            {
                temp[j] = temp[j] + temp[j - 1];
            }
        }
        return temp;
    }
}
int main()
{
    vector<int> test;
    int rowIndex;
    cout << "input the rowIndex:";
    cin >> rowIndex;
    test = getRow(rowIndex);
    for (int i = 0; i <= rowIndex; ++i)
    {
        cout << test[i] << " ";
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
