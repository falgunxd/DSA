#include <iostream>
using namespace std;
int summ(int N)
{
    if (N > 0)
    {
        return (N + summ(N - 1));
    }
    else
        return 0;
}
int main()
{
    int N;
    cin >> N;
    cout << summ(N);

    return 0;
}