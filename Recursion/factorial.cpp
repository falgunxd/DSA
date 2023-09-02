#include <iostream>
using namespace std;
int factorial(int K)
{
    if (K > 0)
        return K * factorial(K - 1);
    else
        return 1;
}
int main()
{
    int N;
    cin >> N;
    cout<<factorial(N);

    return 0;
}