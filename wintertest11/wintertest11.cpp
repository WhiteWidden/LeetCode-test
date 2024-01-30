// wintertest11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
#include <iostream>//反转字符串-双指针应用
#include <string>
#include <vector>
using namespace std;
void input(vector<char>& s)
{
    int num;
    cout << "input num:";
    cin >> num;
    s.resize(num);
    cout << "input string:";
    for (vector<char>::iterator i=s.begin();i!=s.end();++i)
    {
        cin >> *i;
    }
}
void reverseString(vector<char>& s)
{
    vector<char>::iterator Start, End;
    Start = s.begin();
    End = s.end()-1;
    while (Start < End)
    {
        swap(*Start, *End);
        ++Start;
        --End;
    }
}
int main()
{
    vector<char> s;
    input(s);
    reverseString(s);
    cout << "----------------------" << endl;
    for (vector<char>::iterator i = s.begin(); i != s.end(); ++i)
    {
        cout << *i;
    }
    return 0;
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
