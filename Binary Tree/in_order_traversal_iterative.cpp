#include <iostream>
#include<bits/stdc++.h> 

class Tree
{
    public: 
        int data;
        Tree* left; // pointer to left child
        Tree* right; // pointer to right child

        // Function to add new node to the tree
        Tree* newNode(int newData)
        {
            // Allocate a new node on the heap memory
            Tree* newNode = new Tree();
            // Add the new Data onto the new node
            newNode->data = newData;
            // Initilize the left and right child as NULL
            newNode->left = nullptr;
            newNode->right = nullptr;

            return (newNode);
        }
};

void printInOrder(Tree* root)
{
    // Left -- Visit -- Right
    
    // (1) Create an empty stack
    std::stack<Tree*> s;
    // (2) Initialize current node as root 
    Tree* curr = root;
    // (3) Push the curr node into the stack & set curr = cuur->left until curr == NULL
    while (curr != nullptr || s.empty() == false)
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        /* If curr == null and stack is not empty:
        (i) Pop the stack
        (ii) Print the popped item
        (iii) Set curr = popped_item->right 
        (iv) Go back to step (3) */
        
        // Current must be NULL at this point
        curr = s.top();
        // Step (i)
        s.pop();
        // Step (ii)
        std::cout << curr->data << " ";
        // Step (iii)
        curr = curr->right;
        /* After here the while loop on Step 3 runs as it is the end of the 
        main while loop which ends the iteration of the inOrder traversal algorithm */ 
    }
}

int main()
{
    Tree* root = root->newNode(10);
    /* following is the tree after above statement  
  
       10    <-- root node
      /   \ 
     NULL  NULL   
  */
    root->left = root->newNode(15);
    root->right = root->newNode(30);
    /* 15 and 30 become left and right children of 10 
          10 
         /   \ 
        15    30 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
    root->left->left = root->newNode(3);
    root->left->right = root->newNode(6);
    root->right->right = root->newNode(2);
    /* following is the tree after above statement
          10 
         /   \ 
        15    30 
     /    \    /  \ 
    3      6 NULL  2
    */
    root->left->left->left = root->newNode(5);
    root->right->right->left = root->newNode(9);
    root->right->right->right = root->newNode(8);
    /* following is the tree after above statement
          10   <-- root node
         /   \ 
        15    30 
      /   \     \ 
     3     6     2
    /           /  \
   5           9    8 <-- leaf node
*/


/* ================================================================================================================= */

// std::cout << "Pre-Order traversal: \n";
// printPreOrder(root); // Expected O/P: 10 15 3 5 6 30 2 9 8
// std::cout << std::endl;

std::cout << "In-Order traversal (Iterative): \n";
printInOrder(root); // Expected O/P: 5 3 15 6 10 30 9 2 8
std::cout << std::endl;

// std::cout << "Post-Order traversal: \n";
// printPostOrder(root); // Expected O/P: 5 3 6 15 9 8 2 30 10
// std::cout << std::endl;

return 0;

}