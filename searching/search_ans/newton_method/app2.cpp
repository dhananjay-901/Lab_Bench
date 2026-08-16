#include <iostream>
#include <cmath>

using namespace std;

double findsqrt(double n, double guess, double tolerance){
  double next_guess = (guess + n/guess)/2;
  if(abs(guess - next_guess) <= tolerance){
    return next_guess;
  }
  else{
    return findsqrt(n, next_guess, tolerance);
  }
}

int main(){
  double n = 327, l = 0.00001;
  double guess = n/2;
  double sqrt = findsqrt(n, guess,l);
  cout << sqrt << endl;
  return 0;
}
