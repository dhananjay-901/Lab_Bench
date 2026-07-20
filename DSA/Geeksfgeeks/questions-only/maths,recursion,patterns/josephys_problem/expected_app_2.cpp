//iterative mathematical approach 
#include <iostream>
using namespace std;

int josephus(int n, int k){
    int i = 1, ans = 0;
    while(i<=n){
        ans = (ans+k)%i;
        i++;
    }
    return ans+1;
}
int main(){
    int n=7,k=3;
    cout << josephus(n, k) << endl;
    return 0;
}