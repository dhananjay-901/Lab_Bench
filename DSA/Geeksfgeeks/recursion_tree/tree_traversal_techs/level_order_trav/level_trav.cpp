/*level order traversal technique is a method to traverse a tree such that all nodes present in the same level are traversed completely before traversing the next level*/

//approach using recursion - on time and on space

//the idea is to traverse the tree recursively, starting from the root at level 0, when a node is visited, its value is added to the result array at the index corressponding to its level, and then its left and right children are recursively processed in the same way. this effectively performs a level order traversal using recursion.

#include <iostream>
#include <vector>
using namespace std;
class node{
    public: 
    int data;
    node* left, * right;

    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void leveloforderec(node* root, int level, vector<vector<int>> & res){
    if(root == nullptr) return;

    if(res.size() <= level) res.push_back({});

    res[level].push_back(root->data);

    leveloforderec(root->left, level + 1, res);
    leveloforderec(root->right, level + 1, res);   
}

vector<vector<int>> leveloforder(node* root){
    vector<vector<int>> res;
    leveloforderec(root, 0, res);
    return res;
}

int main(void){
    node* root = new node(5);
    root->left = new node(12);
    root->right = new node(13);

    root->left->left = new node(7);
    root->left->right = new node(14);

    root->right->right = new node(2);

    root->left->left->left = new node(17);
    root->left->left->right = new node(23);

    root->left->right->left = new node(27);
    root->left->right->right = new node(3);

    root->right->right->left = new node(8);
    root->right->right->right = new node(11);

    vector<vector<int>> res = leveloforder(root);

    for(vector<int> level : res){
        for(int val : level){
            cout << val <<  " ";
        }
        cout << endl;
    }
    return 0;
}