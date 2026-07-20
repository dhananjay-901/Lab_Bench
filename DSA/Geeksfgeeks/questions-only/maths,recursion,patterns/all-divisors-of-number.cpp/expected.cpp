//expected approach = finding all factors in pairs 
/*If we look carefully, all the divisors of a number appear in pairs. For example, if n = 100, then the divisor pairs are: (1, 100), (2, 50), (4, 25), (5, 20), (10, 10). We need to be careful in cases like (10, 10), when both divisors in a pair are equal. In such cases, we should include that divisor only once. So Instead of iterating from 1 to n, we only need to iterate from 1 to √n. Why? Because for any factor a of n, the corresponding factor b = n / a forms a pair (a, b). At least one of the two values in any such pair must lie within the range [1, √n].*/

#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> getdivisors(int n){
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(){
    vector<int> divisors = getdivisors(10);
    for(auto &divs:divisors) cout << divs << " ";
    return 0;
}