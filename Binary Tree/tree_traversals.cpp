#include <iostream>

class Node
{
    public: 
        int data;
        Node* left; // pointer to left child
        Node* right; // pointer to right child

        // Function to add new node to the tree
        Node* newNode(int newData)
        {
            // Allocate a new node on the heap memory
            Node* newNode = new Node();
            // Add the new Data onto the new node
            newNode->data = newData;
            // Initilize the left and right child as NULL
            newNode->left = nullptr;
            newNode->right = nullptr;

            return (newNode);
        }
};

void printPreOrder(Node* node)
{
    if (node != nullptr)
    {
        std::cout << node->data << " "; 
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

int main()
{
    Node* root = root->newNode(10);
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

printPreOrder(root);
std::cout << std::endl;

return 0;

}