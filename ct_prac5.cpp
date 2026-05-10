#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int first = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int last = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return last;
}

int main()
{
    int arr[] = {2, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 5;

    int firstIdx = firstOccurrence(arr, n, k);
    int lastIdx = lastOccurrence(arr, n, k);

    cout << "first idx found at :" << firstIdx << endl;
    cout << "last idx found at :" << lastIdx << endl;

    return 0;
}