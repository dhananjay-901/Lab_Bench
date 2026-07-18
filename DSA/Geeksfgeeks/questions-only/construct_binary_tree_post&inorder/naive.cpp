//given inorder and postorder traversals of a binary tree (having n nodes) in the arrays inorder[] and postorder[] respectively. the task is to construct a unique binary tree from these traversals and return the preorder traversal of the constructed tree.

//the main idea behind the algorithm is to construct a binary tree using the given inorder and postoder traversals. we start by recoginizing that the last element of the postorder traversal represents the root of the tree. using this value, we find its position in the inorder traversal, which allows us to divide the tree into the left and right subtree. we then recursively repeat this process, cnostructing the right subtree and then the left subtree. once the tree is fully constructed we can perform a preorder traversal to print the elements in the desired order.

//note: one important observation is, that we recursively call for the right subtree before the left subtree as we decrease the index of the postorder index whenever we create a new node.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

int search(vector<int>& arr, int start, int end, int value){
    int i;
    for(i = start;i<=end;i++){
        if(arr[i] == value){
            break;
        }
    }
    return i;
}

Node *buildutil(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int& pindex){
    if(instart > inend) return nullptr;

    Node *node = new Node(postorder[pindex]);
    pindex--;

    if(instart == inend) return node;

    int iindex = search(inorder, instart, inend, node->data);

    node->right = buildutil(inorder, postorder, iindex + 1, inend, pindex);
    node->left = buildutil(inorder, postorder, instart, iindex - 1, pindex);

    return node;
}
Node *buildtree(vector<int>& inorder, vector<int>& postorder){
    int n = inorder.size();
    int pindex = n-1;
    return buildutil(inorder, postorder, 0, n-1, pindex);
}

void print(Node *curr){
    if(curr==nullptr) return;
    cout << curr->data << " ";
    print(curr->left);
    print(curr->right);
}

int main(){
    vector<int> inorder = {4,8,2,5,1,6,3,7};
    vector<int> postorder = {8,4,5,2,6,7,3,1};

    Node *root = buildtree(inorder, postorder);
    print(root);
    return 0;
}