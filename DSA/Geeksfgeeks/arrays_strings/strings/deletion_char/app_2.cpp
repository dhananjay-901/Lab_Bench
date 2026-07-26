//deletion of character in string using built in function 
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string str = "geeksforgeeks";
    int pos = 5;
    str.erase(pos, 1);
    cout << "modified string: " << str << endl;
    return 0;
}