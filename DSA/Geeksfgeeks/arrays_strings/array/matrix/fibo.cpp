// C++ Program to find the Nth fibonacci number using
// Matrix Exponentiation

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
void multiply(vector<vector<long long> >& A,
              vector<vector<long long> >& B)
{
    vector<vector<long long> > C(2, vector<long long>(2));

    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}
vector<vector<long long> >
power(vector<vector<long long> > M, int expo)
{
    vector<vector<long long> > ans = { { 1, 0 }, { 0, 1 } };
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }
    return ans;
}

int nthFibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    vector<vector<long long> > M = { { 1, 1 }, { 1, 0 } };
    vector<vector<long long> > F = { { 1, 0 }, { 0, 0 } };
    vector<vector<long long> > res = power(M, n - 1);
    multiply(res, F);
    return res[0][0] % MOD;
}

int main()
{
    int n = 3;
    cout << nthFibonacci(n) << endl;
}
