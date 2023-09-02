#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        int repeats=0;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++)
        {
            while (a[i] == a[i + 1])
            {
                repeats++;
                i++;
            }
        }
        cout << N - repeats<<endl;
    }

    return 0;
}