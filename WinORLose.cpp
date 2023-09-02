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
        int os = 0, zs = 0;
        for (int i = 0; i < N; i++)
        {
            if ((os >= 11) && (os - zs > 1))
            {
                cout << "WIN";
                break;
            }
            else if ((zs >= 11) && (zs - os > 1))
            {
                cout << "LOSE";
                break;
            }
            else if (S[i] == '1')
                os++;
            else if (S[i] == '0')
                zs++;

        }
    }

    return 0;
}