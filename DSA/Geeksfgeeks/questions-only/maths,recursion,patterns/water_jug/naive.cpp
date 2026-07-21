//given a m litre jug and a n litre jug where 0 < m < n, both initially empty and without any markings to measure intermediate quantities. you need to measured d litres of water where d < n. the oeprations you can perform are : empty a jug, fill a jug, pour water from one jug to the other until one of the jug is either empty or full. find the minimum number of operations required to obtain exactly d litres of water in either of the two jugs. if it is not possible return -1.

//to solve this problem we can think like it as a state exploration problem where each state represents the amount of water in both jugs at a particular point in time. from any given state, a set of possible operations can be performed to move to a new state and this continues until we either reach the desired amount d in one of the jugs or determining that it's not possible..

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int minsteps(int m, int n, int d){
    if(d> max(m,n)) return -1;

    queue<vector<int>> q;

    vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));

    q.push({0,0,0});
    visited[0][0] = true;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        int jug1 = curr[0];
        int jug2 = curr[1];
        int steps = curr[2];

        if(jug1 == d || jug2 == d) return steps;

        if(!visited[m][jug2]){
            visited[m][jug2] = true;
            q.push({m, jug2, steps + 1});
        }

        if(!visited[jug1][n]){
            visited[jug1][n] = true;
            q.push({jug1, n, steps + 1});
        }

        if(!visited[0][jug2]){
            visited[0][jug2] = true;
            q.push({0, jug2, steps + 1});
        }

        if(!visited[jug1][0]){
            visited[jug1][0] = true;
            q.push({jug1, 0, steps + 1});
        }

        int pour1to2 = min(jug1, n - jug2);
        if(!visited[jug1 - pour1to2][jug2 + pour1to2]){
            visited[jug1 - pour1to2][jug2 + pour1to2] = true;
            q.push({jug1 - pour1to2, jug2 + pour1to2, steps + 1});
        }

        int pour2to1 = min(jug2, m - jug1);
        if(!visited[jug1 + pour2to1][jug2 - pour2to1]){
            visited[jug1 + pour2to1][jug2 - pour2to1] = true;
            q.push({jug1 + pour2to1, jug2 - pour2to1, steps + 1});
        }
    }
    return -1;
}

int main(){
    int m = 3, n = 5, d = 4;
    cout << minsteps(m, n, d);
    return 0;
}