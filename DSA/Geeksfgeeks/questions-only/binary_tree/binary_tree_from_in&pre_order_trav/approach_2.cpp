//the idea is similar to first approach but instead of linearly searching the in order array for ech node we can yse hashing. map the values of in order array to its indices. this will reduce the searching complexity from on to 01.

#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

Node *buildtreerecur(unordered_map<int, int>& mp, vector<int>& preorder, int& preindex, int left, int right){
    if(left>right) return nullptr;
    int rootval = preorder[preindex];
    preindex++;
    Node *root = new Node(rootval);
    int index = mp[rootval];

    root->left= buildtreerecur(mp, preorder, preindex, left, index-1);
    root->right = buildtreerecur(mp, preorder, preindex, index+1, right);
    return root;
}

Node *buildtree(vector<int>& inorder, vector<int>& preorder){
    unordered_map<int, int> mp;
    for(size_t i=0;i<inorder.size();i++) mp[inorder[i]] = (int)i;
    int preindex = 0;
    Node *root = buildtreerecur(mp, preorder, preindex, 0, (int)inorder.size()-1);
    return root;
}

int getheight(Node* root, int h){
    if(root==nullptr) return h-1;
    return max(getheight(root->left, h+1), getheight(root->right, h+1));
}

void levelorder(Node* root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int lastlevel=0;
    int height = getheight(root, 0);
    while(!q.empty()){
        auto top = q.front(); q.pop();
        Node* node = top.first;
        int lvl = top.second;

        if(lvl>lastlevel){
            cout << "\n";
            lastlevel = lvl;
        }

        if(lvl>height) break;
        if(node->data!=-1) cout << node->data << " ";
        else cout << "N ";

        if(node->data == -1) continue;
        if(node->left == nullptr) q.push({new Node(-1), lvl +1});
        else q.push({node->left, lvl + 1});

        if(node->right==nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl+1});
    }
}

int main(){
    vector<int> inorder = {3,1,4,0,5,2};
    vector<int> preorder = {0,1,3,4,2,5};
    Node *root = buildtree(inorder, preorder);
    levelorder(root);
    return 0;
}