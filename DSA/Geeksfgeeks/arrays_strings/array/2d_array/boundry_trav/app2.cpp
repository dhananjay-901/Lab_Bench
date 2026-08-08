//the idea is simple. traverse the matrix and check for every element if that element lies on the boundry or not, if yes then print the element else print space character

#include <iostream>
#include <vector>
using namespace std;

void printboundry(vector<vector<int>>& a, int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 ||j ==0 ||i==m-1 ||j == n-1)
				cout << a[i][j] << " ";
			else
				cout << " ";
		}
		cout << "\n";
	}
}
int main(){
	vector<vector<int>> a = {
		{1,2,3,4},{5,6,7,8},{1,2,3,4},{5,6,7,8}
	};
	printboundry(a,4,4);
	return 0;
}