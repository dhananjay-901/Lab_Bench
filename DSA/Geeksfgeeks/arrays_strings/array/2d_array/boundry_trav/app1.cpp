//given a matric mat[][] of size nxm the task is to traverse the boundry elements in clockwise order, starting from the top left element

//approach - the idea is to traverse the boundry elements of a matrix in clockwise order by breaking down the traversal into four distinct movements first along the top row from left to right then down the rightmost column from top to bottom followed by the bottom row from right to left and finally up the left most column from the bottom to top.

#include <iostream>
#include <vector>
using namespace std;

vector<int> boundrytraversal(vector<vector<int>>& mat){
	int n = mat.size(), m = mat[0].size();
	vector<int> res;
	
	for(int j=0;j<m;j++){
		res.push_back(mat[0][j]);
	}
	for(int i=1;i<n;i++){
		res.push_back(mat[i][m-1]);
	}

	for(int j=m-2;j>=0;j--){
		res.push_back(mat[n-1][j]);
	}
	for(int i=n-2;i>0;i--){
		res.push_back(mat[i][0]);
	}
	return res;
}

int main(){
	vector<vector<int>> mat = {
		{1,2,3,4},{5,6,7,8},{9,10,11,12}
	};

	vector<int> res = boundrytraversal(mat);
	for(auto val : res){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}