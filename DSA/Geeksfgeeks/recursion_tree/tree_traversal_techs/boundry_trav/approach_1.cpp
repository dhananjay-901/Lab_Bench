//boundry traversal of binary tree
/*given the root of a binary tree, find its boundry traversal in anti clockwise order, starting from the root

the boundry of a binary tree consits of the following parts:
1. left boundry the nodes on the left edge of the tree, excluding the leaf nodes.
2. lead nodes all the leaf nodes from the left to right
3. right boundry the node on the right edge of the tree, excluding the lead nodes, traversed in bottom up order

note - if the root does not have a left subtree or right subtree, then the root itself is considered part of the respective boundry. each node in the boundry should appear only once in the traversal*/

//approach 1 using recursion - O[n] time and O[h] space
//the boundry traversal of a binary tree is done in three steps, first we traverse the left boudnry starting from the root's left child and moving downward excluding any leaf nodes. next we traverse the right boundry, starting from the root's child and moving downward, again excluding leaf nodes, but the collected nodes are added in reverse order. by combining the left boundry, left nodes, and right boundry, we obtain the complete anti clockwise boundry traversal of the tree.
#include <iostream>
#include <vector>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
bool isLeaf(Node *node) {
    return node->left == nullptr && node->right == nullptr;
}
void collectLeft(Node* root, vector<int>& res) {
    if (root == nullptr || isLeaf(root))
        return;
  	res.push_back(root->data);
    if (root->left) 
        collectLeft(root->left, res);
    else if (root->right)
        collectLeft(root->right, res);
}

void collectLeaves(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;
	
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    collectLeaves(root->left, res);
    collectLeaves(root->right, res);
}

void collectRight(Node* root, vector<int>& res) {
  	
    if (root == nullptr || isLeaf(root)) 
        return;

    if (root->right)
        collectRight(root->right, res);

    else if (root->left) 
        collectRight(root->left, res);
	
	res.push_back(root->data);  
}

vector<int> boundaryTraversal(Node *root) {
	vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    collectLeft(root->left, res);
    collectLeaves(root, res);
    collectRight(root->right, res);
    return res;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}