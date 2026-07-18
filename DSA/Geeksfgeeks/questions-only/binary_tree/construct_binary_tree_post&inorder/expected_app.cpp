//the idea is to optimize the above solution using hashing. we store indexes of inorder traversal in a hash table. so that search can be done o1 time if given that element in the tree is not repeated
/*follow the below steps to solve the problem:
- we first find the last node in postorder[]. the last noed is lets say x we know this value is the root as the root always appears at the end of postorder traversal. we get the index of postorder[i] in inorder using the map to find the left and right subtrees of the root. everything on the left of x in inorder[] is in the left subtree and everything on right is in right subtree. we recur the above process for following two. - recur for right side in inorder[] and decrease index of postorder index. make the created tree as right child of root. recur for left side in inorder[] and decrease index of postorder index. make the created tree as left child of root*/

#include <bits/stdc++.h>
#include <type_traits>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node *buildutil(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int& pindex, unordered_map<int, int>& mp){
    if(instart > inend) return NULL;
    int curr = postorder[pindex];
    Node* node = new Node(curr);
    pindex--;

    if(instart == inend) return node;

    int iindex = mp[curr];

    node->right = buildutil(inorder, postorder, iindex + 1, inend, pindex, mp);
    node->left = buildutil(inorder, postorder, instart, iindex-1, pindex, mp);

    return node;
}

Node* buildtree(vector<int>& inorder, vector<int>& postorder){
    int len = inorder.size();

    unordered_map<int , int> mp;
    for(int i=0;i<len;i++){
        mp[inorder[i]] = i;
    }

    int postindex = len-1;
    return buildutil(inorder, postorder, 0, len-1, postindex, mp);
}

void print(Node* curr){
    if(curr==nullptr) return;
    cout << curr->data << " ";
    print(curr->left);
    print(curr->right);
}

int main(){
    vector<int> inorder = {4,8,2,5,1,6,3,7};
    vector<int> postorder = {8,4,5,2,6,7,3,1};
    Node* root = buildtree(inorder,postorder);
    print(root);
    return 0;
}