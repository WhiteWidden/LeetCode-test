#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
constexpr auto n = 1000000;
using namespace std;
int intlength(int x)
{
    int flag = x;
    int i = 0;
    while (flag)
    {
        flag = flag / 10;
        i++;
    }
    return i;
}
int* intoarr(int y,int x,int *a) {
    int xx = x;
    int yy = y;
    int i;
    int* c = new int[xx];
    for (i = 0; i <xx; i++)
    {
        //c[i] = to_string(yy%10);
        c[i] = yy % 10;
        yy = yy /10;
    }
    for (int i = 0; i < xx; i++)
    {
        a[i] = c[xx - 1 - i];
    }
    delete[]c;
    return a;
}
int main()
{
    int src;
    int Num1, Num2, max_num, min_num;
    string num1, num2;
    int flag = 0;
    int ilength;
    cout << "num1=";
    cin >> num1;
    cout << "num2=";
    cin >> num2;
    cout << "min_num=";
    cin >> min_num;
    cout << "max_num=";
    cin >> max_num;
    istringstream ss(num1);
    ss >> Num1;
    istringstream s(num2);
    s >> Num2;
    for (src = Num1; src <=Num2; src++)
    {
        int* b = new int[n];
        int sum = 0;
        ilength=intlength(src);
        intoarr(src, ilength, b);
        for (int j = 0; j < ilength; j++)
        {
            sum += b[j];
        }
        if (sum >= min_num && sum <= max_num)
        {
            flag++;
            cout << src << endl;
        }
        delete[]b;
    }
    flag = flag % (1000000000 + 7);
    cout << "flag=" << flag << endl;
}


// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
