//the idea is to reduce the auxiliary space used by the memory stack in the previous approach. this approach is similar to the previous one, but instead of recursion, we use iteration to find the left and right bonudaries and use the morries traversal to find the leaf nodes
#include <iostream>
#include <vector>
using namespace std;

// Node Structure
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

// Function to collect the left boundary nodes
void collectLeft(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    while (!isLeaf(curr)) {
        res.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Function to collect the leaf nodes using Morris Traversal
void collectLeaves(Node* root, vector<int>& res) {
    Node* current = root;

    while (current) {
        if (current->left == nullptr) {
          
            // If it's a leaf node
            if (current->right == nullptr) 
                res.push_back(current->data);
            
            current = current->right;
        } 
      	else {
          
            // Find the inorder predecessor
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } 
          	else {
          	    
              	// If it's predecessor is a leaf node
                if (predecessor->left == nullptr) 
                    res.push_back(predecessor->data);
                
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

// Function to collect the right boundary nodes
void collectRight(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    vector<int> temp;
    while (!isLeaf(curr)) {
      
        temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
        res.push_back(temp[i]);
}

// Function to perform boundary traversal
vector<int> boundaryTraversal(Node *root) {
    vector<int> res;

    if (!root)
        return res;

    // Add root data if it's not a leaf
    if (!isLeaf(root))
        res.push_back(root->data);

    // Collect left boundary
    collectLeft(root->left, res);

    // Collect leaf nodes
    collectLeaves(root, res);

    // Collect right boundary
    collectRight(root->right, res);

    return res;
}

int main() {

    // Hardcoded Binary tree
    //            1
    //         /     \
    //       2         3
    //     /   \     /   \
    //    4     5   6     7
    //         / \
    //        8   9
    
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