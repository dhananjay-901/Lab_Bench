//the arrangement attacks where knight to move 2 steps in the horizontal direction and 1 step in vertical. to 4 * (n - 2) * (m - 1) and similarly for 2 steps in the vertical direction and 1 step in the horizontal. Thus the answer will be Total possible arrangement - 4 * (n - 2) * (m - 1) - 4 * (n - 1) * (m - 2) which is (n*m)*(n*m - 1) - 4 * (n - 2) * (m - 1) - 4 * (n - 1) * (m - 2)

/*How does this work? Consider knight to move 2 steps in the horizontal direction and 1 step in the vertical. So if we are at (i, j) after such moves we can reach at (i+2, j+1), (i+2, j-1), (i-2, j+1), (i-2, j-1). To have (i+2) inside the board we can have our positions 0 to n-3 i.e we have to leave the last two rows otherwise (i+2) will be out of the board. similarly for (i-2) range is possible if 2 to n-1. Similarly for (j+1) range will be 0 to m-2, and for (j-1) range will be 1 to m-1 i.e one column less in each case. So, arrangements in this case where attack possible equal to 4 * (n - 2) * (m - 1) Similarly, if we consider two steps in vertical and one step in horizontal we will have one less row and two less col so that two knights can attack each other. We subtract this arrangement from total arrangements which is m * n * (n * n - 1). Hence the answer will be m * n * (m * n - 1) - 4 * (n - 2) * (m - 1) - 4 * (n - 1) * (m - 2)*/

#include <iostream>
using namespace std;
int numofways(int n, int m){
    int ans = (n*m-1) *n*m;
    if(n>=1 && m>=2){
        ans-= (4*(n-1)*(m-2));
    }
    if(n>=2 && m>=1){
        ans -= (4*(n-2) * (m-1));
    }
    return ans;
}

int main(){
    int n = 2, m = 3;
    cout << numofways(n, m) << " ";
    return 0;
}