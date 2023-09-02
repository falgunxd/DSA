#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S1, S2;
        int c = 0, q = 0;
        cin >> S1 >> S2;
        for (int i = 0; i < S1.size(); i++)
        {
            if ((S1[i] == '?') || (S2[i] == '?'))
                q++;
            else if ((S1[i] != '?') && (S2[i] != '?'))
            {
                if ((S1[i] != S2[i]))
                {
                    c++;
                }
            }
        }
        cout << c << "  " << c + q << endl;
    }

    return 0;
}