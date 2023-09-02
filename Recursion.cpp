#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 0)
    {
        cout<<fun(n - 1) + n;
    }
    return 0;
}

int main()
{
    int a = 5;
    fun(a);
    return 0;
}