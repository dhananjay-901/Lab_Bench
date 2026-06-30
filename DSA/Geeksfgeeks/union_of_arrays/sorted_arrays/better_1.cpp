/*Given two sorted arrays a[] and b[], the task is to return union of both the arrays in sorted order. Union of two arrays is an array having all distinct elements that are present in either array. The input arrays may contain duplicates.*/

/*The approach is to insert all elements from both arrays, a[] and b[], into a set. Since a set automatically removes duplicates, it gives us the union of the two arrays. Also, the set keeps the elements in sorted order, so after inserting them, we can store these sorted and unique elements in a result array.*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;
