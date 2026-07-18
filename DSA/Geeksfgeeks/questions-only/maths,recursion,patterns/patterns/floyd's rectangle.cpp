//given an integer n, print floyd's triangle with n rows. floyd's triangle is a right angled triangular pattern formed using consecutive natural numbers starting from 1

//using nested loops on2 time and o1 space
//the pattern can be printed using two nested loops controls the number of rows, while the inner loops prints the numbers in each row, a variable val is used to keep track of the curent number, which is incrmented after each print so that the numbers appear in increasing order across the triangle

/*Step-wise Approach: 
Initialize a variable val = 1 to store the current number to print.
Run an outer loop from 1 to n to iterate through the rows.
For each row i, run an inner loop from 1 to i.
Print the current value of val.
Increment val after printing each number.
After completing each row, move to the next line.*/

#include <iostream>
using namespace std;
void printfloydtriangle(int n){
    int i,j,val = 1;
    for(int i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout << val++ << " ";
        }
        cout << endl;
    }
}

int main(){
    printfloydtriangle(6);
    return 0;
}