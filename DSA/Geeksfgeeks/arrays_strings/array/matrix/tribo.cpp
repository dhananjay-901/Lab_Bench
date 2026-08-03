// C++ Program to find the nth tribonacci number

#include <bits/stdc++.h>
using namespace std;
void multiply(vector<vector<long long> >& A,
              vector<vector<long long> >& B)
{
    vector<vector<long long> > C(3, vector<long long>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j]
                    = (C[i][j] + ((A[i][k]) * (B[k][j])));
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = C[i][j];
        }
    }
}

vector<vector<long long> >
power(vector<vector<long long> > M, int expo)
{
    vector<vector<long long> > ans
        = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }
    return ans;
}
long long tribonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    vector<vector<long long> > M
        = { { 1, 1, 1 }, { 1, 0, 0 }, { 0, 1, 0 } };
    vector<vector<long long> > F
        = { { 1, 0, 0 }, { 1, 0, 0 }, { 0, 0, 0 } };
    vector<vector<long long> > res = power(M, n - 2);
    multiply(res, F);
    return res[0][0];
}

int main()
{
    int n = 4;
    cout << tribonacci(n);
    return 0;
}
