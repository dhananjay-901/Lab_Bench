//given a array of size n and multiple values around which we need to left rotate the array.

//simple approach
#include <iostream>
using namespace std;
int* rotateArray(int A[], int start, int end)
{
    while (start < end) {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
    return A;
}

void leftRotate(int A[], int a, int k)
{
    int c = k % a;
    int D[a];
    for (int i = 0; i < a; i++)
        D[i] = A[i];

    rotateArray(D, 0, c - 1);
    rotateArray(D, c, a - 1);
    rotateArray(D, 0, a - 1);
    for (int i = 0; i < a; i++)
        cout << D[i] << " ";
    cout << "\n";
}

int main()
{
    int A[] = { 1, 3, 5, 7, 9 };
    int n = sizeof(A) / sizeof(A[0]);

    int k = 2;
    leftRotate(A, n, k);

    k = 3;
    leftRotate(A, n, k);

    k = 4;
    leftRotate(A, n, k);
    return 0;
}
