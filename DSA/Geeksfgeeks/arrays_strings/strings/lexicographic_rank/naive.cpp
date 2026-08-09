//given a string s consisting of distinct lowercase characters find its rank among all its permutations when sorted lexicographically
//The idea is to generate all the permutations in lexicographic order and store the rank of the current string. To generate all permutations, we first sort the string and then one by one generate lexicographically next permutation. After generating a permutation, check if the generated permutation is the same as the given string and return the rank of string.

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

long long findrank(string& s){
    string original = s;
    sort(s.begin(), s.end());

    long long rank = 1;

    while(s!=original){
        next_permutation(s.begin(), s.end());
        rank++;
    }
    return rank;
}

int main(){
    string s = "string";
    cout << findrank(s) << endl;
    return 0;
}
