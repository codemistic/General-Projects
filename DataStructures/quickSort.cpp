#include <iostream>
using namespace std;
// Time Complexity:O(NLogN)
// SPace Complexity:O(1):Only Recursive Space
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            // increment the initial index & swap to bring all the greater elements to one side
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
}
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        // sort the 2 halves independently
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
int main()
{
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // enter the starting and ending indexes to sort from
    int l, r;
    cin >> l >> r;
    quickSort(arr, l, r);
    cout << "Sorted Array:";
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}