#include <iostream>
#include <queue>

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

void printLevelOrder(Tree* root)
{
    // To check if the tree is empty
    if (root == nullptr){return;}

    // Level-Order traveral (breath-first) using FIFO Queue
    std::queue<Tree* > q;
    q.push(root);

    while (!q.empty())
    {
        Tree* node = q.front();
        std::cout << node->data << " ";
        q.pop();

        if (node->left != nullptr){q.push(node->left);}
        if (node->right != nullptr){q.push(node->right);}
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

std::cout << "Level-Order traversal: \n";
printLevelOrder(root); // Expected O/P: 10 15 30 3 6 2 5 9 8 
std::cout << std::endl;

return 0;

}