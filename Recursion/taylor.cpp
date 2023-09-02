#include <iostream>
using namespace std;
double fact(int n)
{
    if (n > 0)
        return n * fact(n - 1);
    else
        return 1;
}
double power(int x, int n)
{
    if (n > 0)
        return x * power(x, n - 1);
    else
        return 1;
}
// float e(int x, int n)
// {
//     static int k = x ^ n, l = n !, m;

//     if (n == 0)
//         return 1;
//     else
//     {

//         k = k * x;
//         m = (k / l) + e(x, n-1);
//         l = l * n;
//         return m;
//         // return (power(x,n)/fact(n))+e(x, n - 1);
//     }
// }

double e(int x, int n)
{
    static double k=1,l=1;
    double r;
    if (n == 1)
        return 1;
    else
        // k=k*n/x;
        // return e(x,n-1)+k;
        r=e(x,n-1);
        k=k*x;
        l=l*n;
        return r+k/l;
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << e(x, n);

    return 0;
}