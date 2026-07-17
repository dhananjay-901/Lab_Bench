//given a binary tree, the task is to print the diagonal traversal of the binary tree. note: if the diagonal element are present in two different subtrees, then left subtree diagonal element should be taken first and then right subtree

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void diagonalrecur(Node *root, int level, unordered_map<int, vector<int>>& leveldata){
    if (root==nullptr) return;

    leveldata[level].push_back(root->data);
    diagonalrecur(root->left, level+1, leveldata);
    diagonalrecur(root->right, level, leveldata);
}

vector<int> diagonal(Node *root){
    vector<int> ans;

    unordered_map<int, vector<int>> leveldata;
    diagonalrecur(root, 0, leveldata);
    int level = 0;
    while(leveldata.find(level)!=leveldata.end()){
        vector<int> v = leveldata[level];
        for(int j=0;j<v.size();j++){
            ans.push_back(v[j]);
        }
        level++;
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
    Node *root = new Node(8);
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