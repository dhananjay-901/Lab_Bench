//given inorder and preorder traversals of a binary tree in anrray inorder[] and preorder[] respectively. construct the binary tree and return it's root.
//the idea is to construct the tree using preorder traversal. take the first element of the pre order array and create root node. find the index of this node in the inorder array. crete the left subtree using the elements present on left side of the roo node in n order array. similarly create the right subtree using the elements presents on the right side of the root node in inorder array

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int search(vector<int>& inorder, int value, int left, int right){
    for(int i=left;i<=right;i++){
        if(inorder[i]==value) return i;
    }
    return -1;
}

Node *buildtreerecur(vector<int>& inorder, vector<int>& preorder, int& preindex, int left, int right){
    if(left > right) return nullptr;

    int rootval = preorder[preindex];
    preindex++;
    Node *root = new Node(rootval);
    int index = search(inorder, rootval, left, right);

    root->left = buildtreerecur(inorder, preorder, preindex, left, index-1);
    root->right = buildtreerecur(inorder, preorder, preindex, index + 1, right);

    return root;
}

Node *buildtree(vector<int>& inorder, vector<int> & preorder){
    int preindex = 0;
    Node *root = buildtreerecur(inorder, preorder, preindex, 0, preorder.size()-1);
    return root;
}

int get height(Node* root, int h){
    if(root == nullptr) return h-1;
}