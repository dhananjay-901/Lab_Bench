/*This method is a special optimized version of Cycle Sort that works only when array elements are in the range 1 to N or 0 to N. In this case, we do not need to explicitly detect cycles; instead, we directly place elements at their correct indices using swapping.

If elements are in range 1 to N, then: Correct index of an element = value - 1
Example: 1 -> index 0, 2 -> index 1, …, N -> index N-1

If elements are in range 0 to N, then: Correct index of an element = value itself*/

#include <bits/stdc++.h>
using namespace std;
