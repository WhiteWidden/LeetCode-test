// wintertest5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;//给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
int getRand(int min, int max) {
    return(rand() % (max - min) + min);
}
vector<vector<int>> vec(int R, int C,vector<vector<int>> &a){
    srand(time(0));
    a.resize(R);
    for (int i = 0; i < R; ++i)
    {
        a[i].resize(C);
    }
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            a[i][j] = getRand(0, 9);
            //cout << temp[i][j] << " ";
        }
        //cout << endl;
    }
    return a;
}
int main()
{
    vector<vector<int>> mat;
    vector<int> ans;
    int row, column;
    int num,temp;
    cout << "intput row:";
    cin >> row;
    cout << "input column:";
    cin >> column;
    num = row * column;
    temp = row + column - 1;
    //ans.resize(num);
    //int flag = temp;
    vec(row, column, mat);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < temp; ++i)
    {
        if (i % 2 == 1)
        {
            for (int j = 0; j <= i; ++j)
            {
                if ((j < row) && (i - j) < column)
                {
                    int c = i - j;
                    //cout << mat[j][c] << " ";
                    ans.push_back(mat[j][c]);
                }
            }
        }
        if (i % 2 == 0)
        {
            for (int k = i ; k >= 0; --k)
            {
                if ((k < row) && (i - k) < column)
                {
                    int c = i - k;
                    //cout << mat[k][c] << " ";
                    ans.push_back(mat[k][c]);
                }
            }
        }
        
    }
    for (int i = 0; i < num; ++i)
    {
        cout << ans[i] << " ";
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
