#include <iostream>
using namespace std;
class solution
{
public:
    int BinarySearch(int A[], int find, int n)
    {
        int h = n;
        int l = 0;
        // int mid = (l + h) >>> 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (find == A[mid])
            {
                return mid + 1;
            }
            else if (find > A[mid])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return 0;
    }
};
int main()
{
    int n;
    cout << "Enter the length of the sorted array";
    cin >> n;
    int A[n];
    cout << "Enter teh elements of the array (the array should be sorted)";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    cout << endl;
    int tofind;
    cout << "Enter the element you wanna search in the array";
    cin >> tofind;
    solution wow;
    cout << wow.BinarySearch(A, tofind, n);
}