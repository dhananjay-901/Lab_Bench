//tower of hanoi is a classic mathematical puzzle involving three rods a,b and c and n disks of different sizes. intially all disks are stacked on rod A in decreasing order of diameter - largest disk at the bottom and smallest at the top.
/*Goal is to move the entire stack to another rod (rod C) while following these rules: Move only one disk at a time. At each step, you can take the top disk from any rod and place it on another rod. A disk can only be moved if it is the topmost disk of a rod. No larger disk may be placed on top of a smaller disk.*/

//approach tower of hanoi using recursion 

#include <iostream>
using namespace std;
void towerofhanoi(int n, char fromrod, char torod, char auxrod){
    if (n==0) return;
    towerofhanoi(n-1, fromrod, auxrod, torod);
    cout << "disk" << n << "moved from" << fromrod << "to" << torod << endl;
    towerofhanoi(n-1, auxrod, torod, fromrod);
}

int main(){
    int n =3;
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}