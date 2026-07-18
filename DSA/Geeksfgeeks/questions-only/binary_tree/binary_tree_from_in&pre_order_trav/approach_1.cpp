//given inorder and preorder traversals of a binary tree in anrray inorder[] and preorder[] respectively. construct the binary tree and return it's root.
//the idea is to construct the tree using preorder traversal. take the first element of the pre order array and create root node. find the index of this node in the inorder array. crete the left subtree using the elements present on left side of the roo node in n order array. similarly create the right subtree using the elements presents on the right side of the root node in inorder array

#include <iostream>
#include <queue>
#include <vector>
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

int search(vector<int>& inorder, int value, int left, int right){
    for(int i=left;i<=right;i++){
        if(inorder[i]==value){
            return i;
        }
    }
    return -1;
}

Node *buildtreerecur(vector<int>& inorder, vector<int>& preorder, int &preindex, int left, int right){
    if(left>right) return nullptr;

    int rootval = preorder[preindex];
    preindex++;

    Node *root = new Node(rootval);

    int index = search(inorder, rootval, left, right);
    root->left = buildtreerecur(inorder, preorder, preindex, left, index-1);
    root->right = buildtreerecur(inorder, preorder, preindex, index+1, right);

    return root;
}

Node *buildtree(vector<int> &inorder, vector<int>& preorder){
    int preindex = 0;
    if(inorder.empty() || preorder.empty()) return nullptr;
    Node *root = buildtreerecur(inorder, preorder, preindex, 0, (int)inorder.size() - 1);
    return root;
}


int getheight(Node *root, int h){
    if(root == nullptr) return h-1;
    return max(getheight(root->left, h+1), getheight(root->right, h+1));
}

void levelorder(Node* root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int lastlevel = 0;
    int height = getheight(root, 0);
    
    while(!q.empty()){
        auto top = q.front(); q.pop();
        Node* node = top.first;
        int lvl = top.second;
        if(lvl > lastlevel){
            cout << "\n";
            lastlevel = lvl;
        }

        if(lvl> height) break;

        if(node->data !=-1) cout << node->data << " ";

        else cout << "N ";
        if(node->data == -1) continue;
        if(node->left == nullptr) q.push({new Node(-1), lvl+1});
        else q.push({node->left, lvl+1});

        if(node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl+1});
    }
}

int main(){
    vector<int> inorder = {3,1,4,0,5,2};
    vector<int> preorder = {0,1,3,4,2,5};

    Node *root = buildtree(inorder, preorder);
    levelorder(root);
}