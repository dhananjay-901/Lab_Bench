//juggling algorithm for array rotation 
//given an array arr[] the task is to rotate the array by d positions to the left using juggling algorithm

//approach - the idea behind juggling algorithm is that we can rotote all elements of array using cycles. each cycle is independent and represents a group of elements that will shift among themselves during the rotation. if the starting index of cycle is i, then next elements of the cycle will be present at indides (i + d) % n, (i + 2d) % n, (i + 3d) % n ... and so on till we reach back to index i. 

//so for any index i, we know that after rotation we will have arr[(i + d) % n] at index i. Now, for every index in the cycle, we will place the element which should be present at that index after the array is rotated.

//How many independent cycles will be there if an array of size n is rotated by d positions? If an array of size n is rotated by d places, then the number of independent cycles will be gcd(n, d). When we rotate the array, the cycle increments in steps of d and terminates when we reach the starting point. This means that the distance travelled in each cycle will be a multiple of n, which is defined as lcm(n, d). So, number of elements in each cycle = lcm(n, d)/d. Therefore, to cover all n elements, the total number of cycles will be n*d/lcm(n, d) = gcd(n, d).

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	d%=n;

	int cycles = __gcd(n,d);
	for(int i=0;i<cycles;i++){
		int startele = arr[i];
		int curridx = i, nextidx;
		while(true){
			nextidx = (curridx + d)%n;
			if(nextidx == i) break;

			arr[curridx] = arr[nextidx];
			curridx = nextidx;
		}
		arr[curridx] = startele;
	}
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	int d = 2;
	rotatearr(arr,d);
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << " ";
	}
	return 0;
}
