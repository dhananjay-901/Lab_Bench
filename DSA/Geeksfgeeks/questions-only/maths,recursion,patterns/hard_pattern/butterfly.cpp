//given a integer N print a butterfly star pattern with 2n-1 rows. the numbers of stars increases 1 to n in the upper half and then decreases from n-1 to 1 in the lower half forming a symmetric butterfly shape. 

//using nested loops - the butterfly pattern can be printed using nested loops. the oter loops runs for all rows, while three inner loops are used to print the left stars, spaces and right stars. in the upper half the number of stars increases and spaces decreases. in the lower half, the stars decrease and spaces increase forming the butterfly shape

#include <iostream>
using namespace std;

int main(){
    int N = 5;

    for(int i = 1; i <= 2 * N - 1; i++){
        int stars;
        int spaces;

        if(i <= N){
            stars = i;
            spaces = 2 * (N - i);
        } else {
            stars = 2 * N - i;
            spaces = 2 * (i - N);
        }

        for(int j = 1; j <= stars; j++) cout << "*";
        for(int j = 1; j <= spaces; j++) cout << " ";
        for(int j = 1; j <= stars; j++) cout << "*";
        cout << endl;
    }

    return 0;
}