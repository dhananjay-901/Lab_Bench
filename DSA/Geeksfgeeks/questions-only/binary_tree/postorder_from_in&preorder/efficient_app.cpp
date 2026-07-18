//the idea is to avoid repeatedly searching for the root in the inorder traversal. a hash map is used to store the index of every node in the inorder traversal
/*store each inorder value and its index in a hash map. maintain a preorder index pointing to the current root. for each recursive call: take the current preorder element as the root and find its inorder position using the hash map. recursively process the left and right subtrees. add the root to the postorder traversal. return the generated postorder traversal*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void buildpostorder(vector<int>& in, vector<int>& pre, int instart, int inend, unordered_map<int, int>& mp, int& preindex, vector<int>& post){
    if(instart>inend) return;
    int root = pre[preindex++];
    int inindex = mp[root];

    buildpostorder(in, pre, instart, inindex-1,mp, preindex, post);
    buildpostorder(in, pre, inindex+1, inend, mp, preindex, post);
    post.push_back(root);
}

vector<int> printpostorder(vector<int>& in, vector<int>& pre){
    int n = in.size();
    unordered_map<int, int> mp;

    for(int i=0;i<n;i++) mp[in[i]] = i;
    vector<int> post;
    int preindex = 0;
    buildpostorder(in, pre, 0, n-1, mp, preindex, post);
    return post;
}

int main(){
    vector<int> in = {4,2,5,1,3,6};
    vector<int> pre = {1,2,4,5,3,6};
    vector<int> post = printpostorder(in , pre);
    for(int x : post) cout << x << " ";
    return 0;
}