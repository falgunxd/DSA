#include <iostream>
using namespace std;
class solution
{
public:
    int recBinSearch(int A[], int key, int l, int h)
    {
        if (l == h)
            if (A[l] == key)
                return l + 1;
            else
                return 0;
        else
        {
            int mid = (l + h) / 2;
            if (A[mid] == key)
                return mid + 1;
            else if (A[mid] > key)
                return recBinSearch(A, key, l, mid - 1);
            else
                return recBinSearch(A, key, mid + 1, h);
        }
    }
};
int main()
{
    int n;
    cin >> n;
    int A[n];
    int find;
    cin >> find;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    solution wow;
    cout << wow.recBinSearch(A, find, 0, n);
}