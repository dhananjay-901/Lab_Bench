#include <iostream>
using namespace std;

class Solution{
    public:
    int floor_sqrt(int x){
        int res=1;
        while(res*res <=x){
            res++;
        }
        return res-1;
    }
};

int main(){
    Solution s;
    int a = 0;
    cin >> a;
    cout << "\n" <<s.floor_sqrt(a) << "\n";
}