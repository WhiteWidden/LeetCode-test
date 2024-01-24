// wintertest1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;//合并区间
bool cmp(int a[], int b[])
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
        return a[0] < b[0];
}
int getRand(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}
int main()
{
    
    stack<int> Temp;
    int row, column=2;
    int i, j, flag, temp = 0;
    cin >> row;
    int** a = new int* [row];
    for (int i = 0; i < row; i++)
    {
        a[i] = new int[column];
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            cin >> a[i][j];
        }
    }
    sort(a,a+row,cmp);
    for (int i = 0; i < row-1; i++)
    {
        flag = 1;
        if ((a[i+1][0])<=(a[i][1]))
        {
            a[i + 1][0] = a[i][0];
            if (a[i][1] <= a[i + 1][1])
            {
                a[i][1] = a[i + 1][1];
            }
            else
                a[i + 1][1] = a[i][1];
            flag = 0;
        }
        if (flag == 1)
        {
            Temp.push(i);
            temp++;
        }
    }
    if (a[row - 1][0] <= a[row - 2][1])
    {
        if (a[row - 1][1] >= a[row - 2][1])
        {
            a[row - 2][1] = a[row - 1][1];
        }
    }
    else
    {
        temp=temp+1;
        Temp.push(row - 1);
    }
    int** b = new int* [temp];
    for (int i = 0; i < temp; i++)
    {
        b[i] = new int[column]();
    }
    for (int i = 0; i < temp; i++)
    {
        int op = Temp.top();
        for (int j = 0; j < column; j++)
        {
            b[i][j] = a[op][j];
        }
        Temp.pop();
    }
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete a[i];
        //a[i] = NULL;
    }
    delete[row]a;
    for (int i = 0; i < temp; i++)
    {
        delete b[i];
        //a[i] = NULL;
    }
    delete[temp]b;
    //a = NULL;
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
