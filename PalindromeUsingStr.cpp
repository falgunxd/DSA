#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.size();
        int bool1 = 1;
        if (N % 2 == 0)
        {

            for (int i = 0; i < N / 2; i++)
            {
                if (S[i] != S[N - 1 - i])
                {
                    cout << "loses\n";
                    bool1 = 0;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < (N - 1) / 2; i++)
            {
                if (S[i] != S[N - 1 - i])
                {
                    cout << "loses\n";
                    bool1 = 0;
                    break;
                }
            }
        }
        if (bool1 == 1)
            cout << "wins\n";
    }
    return 0;
}
