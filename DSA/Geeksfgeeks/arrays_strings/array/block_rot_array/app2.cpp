#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    for (i = 0; i < d; i++) {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}

void leftRotate(int arr[], int d, int n)
{
    int i, j;
    if (d == 0 || d == n)
        return;
    if (d > n)
        d = d % n;
    i = d;
    j = n - d;
    while (i != j) {
        if (i < j) /*A is shorter*/
        {
            swap(arr, d - i, d + j - i, i);
            j -= i;
        }
        else /*B is shorter*/
        {
            swap(arr, d - i, d, j);
            i -= j;
        }
    }
    swap(arr, d - i, d, i);
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}