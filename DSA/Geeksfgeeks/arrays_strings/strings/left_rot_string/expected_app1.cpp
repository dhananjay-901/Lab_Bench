//the idea behind the juggling algorithm is that we can rotate all the elements in cycle. each cycle is independent and represents a group of elements that will shift among themselves during the rotation. if the starting index of a cycle is i, then next elements of the cycle will be present at indices (i + d) % n, (i + 2d) % n, (i + 3d) % n ... and so on till we reach back to index i. The total number of cycles will be GCD of n and d. And, we perform a single left rotation within each cycle.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void rotatestring(string &s, int d){
	int n = s.size();
	d%=n;
	int cycles = __gcd(n,d);
	for(int i=0;i<cycles;i++){
		char startchar = s[i];
		int curridx = i, nextidx;
		while(true){
			nextidx = (curridx + d) % n;
			if(nextidx == i) break;

			s[curridx] = s[nextidx];
			curridx = nextidx;
		}

		s[curridx] = startchar;
	}
}

int main(){
	string s = "geeksforgeeks";
	int d = 2;
	rotatestring(s,d);
	cout << s << endl;
	return 0;
}