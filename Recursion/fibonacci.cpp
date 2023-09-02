#include <iostream>
using namespace std;
int fibonacci(int n)
{
    static int S = 0;

    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
        return (fibonacci(n-1)+fibonacci(n-1));
}

int main()
{
    int N;
    cin >> N;
    fibonacci(N);
    return 0;
}