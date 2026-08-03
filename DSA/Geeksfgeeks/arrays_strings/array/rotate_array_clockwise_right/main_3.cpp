//The idea behind Juggling Algorithm is that instead of moving one by one, we can use the concept of cycles. Each cycle is independent and represents a group of elements that will shift among themselves during the rotation. If the starting index of a cycle is i, then the next elements will be present at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n ... and so on till we reach back to index i. So for any index i, we know that element at index i will move to index (i + d) % n. Now, we can simply rotate all elements in the same cycle without interfering with any other cycle. 


//juggling algorithm - finally
#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	d%=n;
	int cycles = __gcd(n,d);
	for(int i=0;i<cycles;i++){
		int curridx = i;
		int currele = arr[curridx];

		do{
			int nextidx = (curridx + d)%n;
			int nextele = arr[nextidx];

			arr[nextidx] = currele;
			currele = nextele;
			curridx = nextidx;
		}while(curridx!=i);
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