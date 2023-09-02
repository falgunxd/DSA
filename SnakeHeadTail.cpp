#include <iostream>
#include <string>
using namespace std;
int main()
{
    int R;
    cin >> R;
    while (R--)
    {
        int L;
        cin >> L;
        string S, X;
        cin >> S;
        for (int i = 0; i < L; i++)
        {
            if (S[i] != '.')
            {
                X.push_back(S[i]);
            }
        }
        int bool1 = 1;
        cout << X;

        for (int i = 0; i < X.size() - 1; i++)
        {
            if (X.size() % 2 != 0)
            {
                bool1 = 0;
                break;
            }
            else if ((i % 2 == 0) && (X[i] != 'H'))
            {
                bool1 = 0;
                break;
            }
            else if ((i % 2 != 0) && (X[i] != 'T'))
            {
                bool1 = 0;
                break;
            }
        }
        if ((bool1) || (X.size() == 0))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}