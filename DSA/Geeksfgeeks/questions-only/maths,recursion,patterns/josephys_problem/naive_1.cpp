//there are n people standing in circle numbered from 1 to n. starting from person 1, counting proceeds in clockwise direction, in each step exactly k-1 people are skipped and the kth person is eliminated from the circle. the counting then resumes from the next person and the process continues until the only one person remains

//naive approach 1 - we can store people in an array from 1 to n. since counting is 0 based in the code, we use k-1 instead of k. starting at index 0. in each step we remove the person at position index(k-1)%current size

#include <iostream>
#include <vector>
using namespace std;

int josephusrec(vector<int> person, int k, int index){
    if (person.size()==1) return person[0];
    index = ((index + k)% person.size());
    person.erase(person.begin() + index);
    return josephusrec(person, k, index);
}

int josephus(int n, int k){
    int index = 0;
    vector<int> person;

    for(int i=1;i<=n;i++){
        person.push_back(i);
    }
    return josephusrec(person, k,index);
}
int main(){
    int n =7;
    int k =3;
    k--;
    cout << josephus(n, k)<< endl;
}