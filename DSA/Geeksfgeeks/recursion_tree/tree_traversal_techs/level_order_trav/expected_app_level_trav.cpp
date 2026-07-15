//expectec approach using queue [iterative] - O(n) time and O(n) space
//the idea is to use a queue to traverse the tree level by level. start by adding the root to the queue. then repeatedly remove a node from the queue, store its value in the result and add its left and right children to the queue. continue this process until the queue is empty


//breadth first search of binary tree
#include <exception>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public: 
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = nullptr;
        right= nullptr;
    }
};

vector<vector<int>> leveloforder(Node* root){
    if(root == nullptr) return {};

    queue<Node *> q;
    vector<vector<int>> res;

    q.push(root);
    int currlevel = 0;
    while(!q.empty()){
        int len = q.size();
        res.push_back({});
        for(int i = 0; i<len;i++){
            Node* node = q.front();
            q.pop();

            res[currlevel].push_back(node->data);

            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        currlevel++;
    }
    return res;
}

int main(void){
    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = leveloforder(root);

    for(auto level : res){
        for(auto val : level){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}