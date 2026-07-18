//given two arrays represent inorder and preorder traversals of a binary tree, the task is to find the postorder traversal
//the idea is a based on the propoerties of preorder and inorder traversals. in preorder traversal, the first element is always the root of the cuurrent subtree. by searching this root in the inorder traversal the left and right subtrees can be identified
/*take the first element of the current preorder range as the root. find the root's index in the inorder traversal using linear search. recursively process the left and right subtrees. append the root to the postorder traversal*/

#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& in, int x){
    for(int i=0;i<in.size();i++){
        if(in[i]==x) return i;
    }
    return -1;
}

void buildpostorder(vector<int>& in, vector<int>& pre, int instart, int inend, int prestart, vector<int>& post){
    if(instart >inend) return;
    int root = pre[prestart];
    int rootindex = search(in, root);
    buildpostorder(in , pre, instart, rootindex-1,  prestart + 1, post);
    buildpostorder(in, pre, rootindex+1, inend, prestart+(rootindex-instart) + 1, post);
    post.push_back(root);
}

vector<int> printpostorder(vector<int>& in, vector<int>& pre){
    vector<int> post;
    buildpostorder(in , pre, 0, in.size()-1, 0, post);
    return post;
}

int main(){
    vector<int> in = {4,2,5,1,3,6};
    vector<int> pre = {1,2,4,5,3,6};
    vector<int> post = printpostorder(in, pre);
    for(int x : post) cout << x << " ";
    return 0;
}