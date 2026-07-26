//given a string str and integer position pos, the task is to delete the character at the specified position pos from the string str.

//traverse the string and push all the characters to another string or character array except the character which needs to be deleted. we will shift the characters to the left starting from the specified position to delete the character.

#include <iostream>
#include <cstring>
using namespace std;

string delete_char_cpp(string s, char ch){
    string new_str = "";
    for(char c : s){
        if(c!=ch){
            new_str+=c;
        }
    }
    return new_str;
}

int main(){
    string s = "hello";
    char ch = 'l';
    cout << delete_char_cpp(s, ch) << endl;
    return 0;
}