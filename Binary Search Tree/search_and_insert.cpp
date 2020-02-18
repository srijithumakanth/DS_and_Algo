// C++ program to demonstrate insertion 
// in a BST recursively. 

#include <iostream>

class BST
{
    private:
        int data;
        BST* left, *right;

    public:
        // Default constructor
        BST();

        // Parametrized constructor
        BST(int);

        // Insert function
        BST* insert(BST*, int);

        // In-Order traversal
        void printInOrder(BST*);
};

// Default constructor definition
BST::BST() : data(0), left(nullptr), right(nullptr) {}

// Parametrized constructor definition
BST::BST(int value)
{
    data = value;
    left = right = nullptr;
}

// Insert function definition
BST* BST::insert(BST* root, int value)
{
    if (!root)
    {
        // Insert first node if root is NULL
        return new BST(value);
    }

    // Insert data
    if (value > (root->data))
    {
        /* Insert right node data, if the 'value' 
        to be inserted is greater than 'root' node data */ 
          
        // Process right nodes
        root->right = insert(root->right, value);
    }
    else
    {
        /* Insert left node data, if the 'value' 
        to be inserted is less than 'root' node data */ 
          
        // Process left nodes
        root->left = insert(root->left, value);
    }

    // Return root after node insertion
    return root;
}

// In-Order traversal function definition
// This gives data in sorted order
void BST::printInOrder(BST* root)
{
    // Return if the BST is empty
    if (!root){return;}
    
    printInOrder(root->left);
    std::cout << root->data << " ";
    printInOrder(root->right);
}

// Driver code 
int main() 
{ 
    BST b, *root = NULL; 
    root = b.insert(root, 50); 
    b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
  
    b.printInOrder(root); 
    std::cout << std::endl;
    
    return 0; 
} 
