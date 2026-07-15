#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Solution{
    public:
    int floor_sqrt(int x){
        float y = static_cast<float>(x);
        float z = sqrt(y);
        return ("%.0f\n",z);
    }
};

int main(){
    Solution s;
    int a = 0;
    cout << "Enter a number: ";
    cin >> a;
    cout << s.floor_sqrt(a) << "\n";
}