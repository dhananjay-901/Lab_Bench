Tree traversal refers to the process of visiting or accessing each node of a tree exactly once in a specific order. Unlike linear data structures such as arrays, linked lists, or queues (which have only one logical way of traversal), trees offer multiple ways to traverse their nodes. 

tree traversals are broadly classified into two categories
1. depth first traversal 
2. breath first traversal [level order traversal or BFS]

the depth first traversal include inorder traversal, preorder traversal, post order traversal

depth first traversal DFT
- explores as far as possible along a branch before exploring the next branch
- types - inorder, preorder, post order

breath first traversal BFT
- explores nodes level by level from top to bottom
- type level order traversal 


inorder traversal - inorder traversal visits the node in order left->root->right
![alt text](image.png)
algorithm for inorder traversal 
inorder tree 
- traverse the left subtree call inorder (left -> subtree)
- visit the root
- traverse the right subtree call inorder (right -> subtree)
![alt text](image-1.png)
![alt text](image-2.png)
![alt text](image-3.png)
![alt text](image-4.png)
![alt text](image-5.png)
![alt text](image-6.png)
uses of inorder traversal 
- in the case of binary search tree [bst], inorder traversal gives nodes in non decreasing order.
- to get nodes of bst in non increasing order, a variation of inorder traversal where inorder traversal is reversed can be used.
- inorder traversal can be used to evaluate arithmetic expressions stored in expression trees. 


preorder traversal - preorder traversal visits the node in the order : root -> left -> right
algorithm for preorder traversal 
preorder[tree] 
- visit the root.
- traverse the left subtree call preorder [left->subtree]
- traverse the right subtree call preorder[right->subtree]
![alt text](image-7.png)
![alt text](image-8.png)
![alt text](image-9.png)
![alt text](image-10.png)
![alt text](image-11.png)
![alt text](image-12.png)

use of preorder traversal 
- preorder traversal is used to create a copy of the tree
- preorder traversal is also used to get prefix expressions on an expression tree.


postorder traversal - visits the node in the order left->right->root
algorithm for postorder traversal 
- traverse the left subtree call postorder[left->subtree]
- traverse ther right subtree call postorder[right->subtree]
