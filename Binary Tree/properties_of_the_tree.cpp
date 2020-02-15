#include <iostream>
#include <queue>
#include <algorithm>

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

int size(Tree* root) // Return number of nodes in the tree
{
    if (root == nullptr){return 0;}
    int leftSize = size(root->left);
    int rightSize = size(root->right);
    return (leftSize + rightSize + 1);
}

int height(Tree* root)
{
    if (root == nullptr){return 0;}
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (1 + std::max(leftHeight, rightHeight));
}

bool rootToLeafSum(Tree* root, int sum, std::vector<int> &result)
{
    // Check if the tree is empty
    if (root == nullptr)
    {
        // std::cout<<"Empty tree!"<<std::endl;
        return false;
    }
    
    // Check if its a leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        // Check if the current node is equal to the sum provided
        if (root->data == sum)
        {
            result.push_back(root->data);
            return true;
        }
        else
        {
            // std::cout<<"Leaf node!"<<std::endl;
            return false;
        }
    }
    
    // Recursively check the left nodes everytime negating that nodes's data from the sum
    if (rootToLeafSum(root->left, (sum - root->data), result))
    {
        result.push_back(root->data);
        return true;
    }

    // Recursively check the right nodes everytime negating that nodes's data from the sum
    if (rootToLeafSum(root->right, (sum - root->data), result))
    {
        result.push_back(root->data);
        return true;
    }

    return false;
}

void printResults(std::vector<int> &result)
{
    std::reverse(result.begin(), result.end()); // reversed to show path from root to the child
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
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

std::cout << "Size (number of nodes) of the binary tree: " << size(root) << std::endl; // Expected O/P: 9

std::cout << "Max height of the binary tree: " << height(root) << std::endl; // Expected O/P: 4

std::vector<int> path;
std::cout<< "Does a path exsist for a given sum? --> " << rootToLeafSum(root, 31, path) << std::endl; // Expected O/P: True
std::cout << "Path from root to leaf such that the sum of the nodes is equal to the given sum: \n"; // Expected O/P: 10 15 6
printResults(path);
std::cout << std::endl;

return 0;

}