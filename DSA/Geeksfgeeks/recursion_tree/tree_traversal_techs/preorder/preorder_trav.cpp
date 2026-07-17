//preorder traversal of binary tree - is a method to traverse a tree such that for each node, you first visit the node iteself then traverse its left subtree and finally traverse its right subtree

//approach using recursion - the main idea is to traverse the tree recursively, starting from the root node, first visit the root node itself then completely traverse the left subtree, and finally completely traverse the right subtree

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
        left = right=NULL;
    }
};

void preorder(Node* node, vector<int>& res){
    if(node == nullptr) return;
    res.push_back(node->data);
    preorder(node->left, res);
    preorder(node->right, res);
}

int main(void){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> res;
    preorder(root, res);
    for(auto node :res){
        cout << node << " ";
    }
    return 0;
}