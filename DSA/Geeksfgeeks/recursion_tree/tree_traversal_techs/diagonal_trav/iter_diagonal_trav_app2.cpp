/*The idea is similar to level order traversal, use a queue, but here delimiter is not used. Little modification is to be done. 

if(curr.left != null), then  add it to the queue and move curr pointer to right of curr.
if curr = null, then remove a node from queue.*/

#include <bits/stdc++.h>
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

vector<int> diagonalprint(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        while(curr!=nullptr){
            ans.push_back(curr->data);
            if(curr->left!=nullptr) q.push(curr->left);
            curr = curr->right;
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
    
    vector<int> ans = diagonalprint(root);
    printlist(ans);

}