/*inorder traversal is a method to traverse a tree such that for each node, you first traverse its left subtree, then visit the node itself and finally traverse its right subtree*/

//approach using recursion
//the main idead is to traverse the tree recursively, starting from the root node, first completely traverse the left subtree, then visit the root node itself and finally completely traverse the right subtree.
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void inorder(Node* node, vector<int>& res){
    if(node == nullptr) return;
    inorder(node->left, res);
    res.push_back(node->data);
    inorder(node->right, res);
}

int main(void){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    inorder(root, res);
    for(auto node : res){
        cout << node << " ";
    }
    return 0;
}

/*time complexity O(n) and auxiliary space O(h), h is the height of the tree
-the worst case, h can be same as n [where th tree is skewed tree]
-the best case, h can be the same as log n [where the tree is complete tree]

key properties 
- if applied to a binary search tree [bst], it returns elements in sorted order.
- ensures that nodes are processed in a hierarchical sequence, making it useful for expression trees and bsts*/