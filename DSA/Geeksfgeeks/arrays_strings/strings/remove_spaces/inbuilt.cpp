//using in built string function to remove or skip all space characters while forming the result. this process each character once and returns a new string without spaces in linear time
//
#include <iostream>
#include <algorithm>

using namespace std;

string removespaces(string& s){
    auto new_end = remove(s.begin(), s.end(), ' ');

    s.erase(new_end, s.end());
    return s;
}

int main(){
    string s = "g eek s f or ge eeks";
    cout << removespaces(s) << endl;
    return 0;
}
