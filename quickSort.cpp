#include <bits/stdc++.h>
// #include <vector>
using namespace std;
void swap(int &n, int &m)
{
    int temp = n;
    n = m;
    m = temp;
}
int partitionSubRoutine(vector<int> A[], int i, int j)
{
    int pivot = A[i];
    while (j > i)
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j++;
        } while (A[j] > pivot);
        swap(A[i], A[j]);
    }
    return j;
}
void quickSort(vector<int> A[], int l, int h)
{
    if (l < h)
    {
        int j = partitionSubRoutine(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}
int main()
{
    int n;
    cout << "Enter size";
    vector<int> A;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        A.push_back(k);
    }
    quickSort(A, 0, n - 1);
    cout << "Sorted array is\n";
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    return 0;
}