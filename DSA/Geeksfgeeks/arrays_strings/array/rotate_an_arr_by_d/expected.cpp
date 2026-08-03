//The idea is to use Juggling Algorithm which is based on rotating elements in cycles. Each cycle is independent and represents a group of elements that will shift among themselves during the rotation. If the starting index of a cycle is i, then next elements of the cycle can be found at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n ... and so on till we return to the original index i. So for any index i, we know that after rotation, the element that will occupy this position is arr[(i + d) % n]. Consequently, for every index in the cycle, we will place the element that should be in that position after the rotation is completed. 

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	d%=n;
	reverse(arr.begin(), arr.begin() + d);
	reverse(arr.begin() + d, arr.end());
	reverse(arr.begin(), arr.end());
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	int d = 2;
	rotatearr(arr, d);
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << " ";
	}
	return 0;
}