//the idea is to consider all prime factors of factorial n. a trailing zero is always producded by primefactors 2 and 5. if we can count the number of 5s and 2s in n! our task is done

//summarized formula to count 5 are floor(n/5)+floor(n/25)...

//how does this work? - a trailing zero is formed by multiplication of 5 and 2. so if we consider all prime factors of all numbers from 1 to n, there would be more 2s and 5s. so the number of 0s is limited by number of 5s. if we count number of 5s in prime factors we get the result.'

//we can observe that the nuumber of 2s in primse factors is always more than or equal to the number of 5s. so if we count 5s in prime factors we are done. how to count the total nuumber of 5s in primse factors in n! - a simple way is to calculate floor(n/5)
#include <iostream>
using namespace std;

int trailingzeros(int n){
    if(n<0) return -1;
    int count = 0;
    for(int i=5; n/i>=1;i*=5) count+=n/i;
    return count;
}

int main(){
    int n =10;
    cout << trailingzeros(n);
    return 0;
}
