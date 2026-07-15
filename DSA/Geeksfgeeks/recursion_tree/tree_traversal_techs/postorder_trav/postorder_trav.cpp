//postorder traversal of binary tree
/*given a root of the binary tree, return the postorder traversal of the binary tree. postorder traversal is a method to traverse a tree such that for each node, you first traverse its left subtree, then its right subtree, and finally visit the node itself*/

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data = v;
        left = right = nullptr;
    }
};

void postorder(Node *node, vector<int>& res){
    if(node == nullptr) return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->data);
}

int main(void){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> result;
    postorder(root, result);
    for(auto val:result){
        cout << val << " ";
    }
    return 0;
}

/*Time Complexity: O(n)
Auxiliary Space: O(h), h is the height of the tree

In the worst case, h can be the same as n (when the tree is a skewed tree)
In the best case, h can be the same as log n (when the tree is a complete tree)
Key Properties:
It is used for tree deletion because subtrees are deleted before the current node.
It is also useful for generating the postfix expression from an expression tree.*/