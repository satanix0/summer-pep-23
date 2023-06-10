#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
        cout << i << " ";
}
void arrReverse()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int start = 0, end = 6;
    printArr(arr, 6);
    while (start < end)
    {
        cout << "in loop " << endl;
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printArr(arr, 6);
}

int main()
{
    // int size = 0;
    // cin >> size;

    // int arr[size];

    // for (int i = 0; i < size; i++)
    // {

    //     cout << "Enter Element " << i + 1 << ": ";
    //     cin >> arr[i];
    // }

    arrReverse();
    return 0;
}