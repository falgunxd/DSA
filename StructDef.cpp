#include <iostream>
using namespace std;
void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    cout << "enter the number of elements you want in the array ";
    cin >> n;
    int arr[n];
    cout << "\n\nEnter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\n\n\nEntered array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    sort(arr, n);
    cout << "\n\n\nSorted array is\n";
    for (int i = 0; i < n; i++ )
    {
        cout << arr[i]<<" ";
    }
    return 0;
}