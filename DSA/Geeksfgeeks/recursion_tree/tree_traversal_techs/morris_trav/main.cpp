//morris traversal for inorder
//given the root of a binary tree. find its inorder traversal using morris raversal without using recursion or a stack.

/*for each node, check if it has a left child. if it does not have a left child, visit it and move to the right child. if it has a left child, find the inorder predecessor [right most node in the left subtree]. make the current node as the right child of its inorder predecessor[temporary link] move to the left child. when you encounter a temporary link again. it means the left subtree is fully visited - remove the temporary link. visit the current node. move to the right child.*/

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
        left = right = nullptr; 
    }
};

vector<int> inorder(Node* root){
    vector<int> res;
    Node* curr = root;

    while(curr!=nullptr){
        if(curr->left == nullptr){
            res.push_back(curr->data);
            curr = curr->right;
        }

        else{
            Node* prev = curr->left;
            while(prev->right!=nullptr && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inorder(root);
    for(auto data:res){
        cout << data << " ";
    }
    cout << endl;
    return 0;
}