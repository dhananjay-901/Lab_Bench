/*given a binary tree, the task is to print the diagonal traversal of the binary tree. note if the diagonal element are present in two different subtrees, then left subtreee diagonal element should be taken first and then right subtree*/

//expected approach-1 using queue with delimiter - on time and on space

//the idea is to traverse the binary tree in level order manner using a queue.push the root node and null pointer in the queue. for each node(starting from root) append its value to the resultant list. push its left child node into queue if it exists and set it to its right child node. if the current node is null, it means the starting of the next diagonal. so set the current node to the front node of the queue and pop from queue

#include <bits/stdc++.h>
#include <cstddef>
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

vector<int> diagonal(Node* root){
    vector<int> ans;

    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == nullptr){
            if(q.empty()) break;
            q.push(nullptr);
        }
        else{
            while(curr!= nullptr){
                ans.push_back(curr->data);
                if(curr->left != nullptr) q.push(curr->left);
                curr = curr->right;
            }
        }
    }
    return ans;
}

void printlist(vector<int> v){
    int n = v.size();
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);
    
    vector<int> ans = diagonal(root);
    printlist(ans);
}