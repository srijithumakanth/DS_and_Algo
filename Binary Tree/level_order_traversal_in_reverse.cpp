#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Tree
{
	public:
	int data;
	Tree* left;
	Tree* right;
	
	// Function to add a new node to the tree
	Tree* newNode(int data);

	// Function that does level order traversal in reverse
	void levelOrderInReverse(Tree* root);
};

Tree* Tree::newNode(int data)
{
	Tree* newNode = new Tree();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	
	return (newNode);
}	

void Tree::levelOrderInReverse(Tree* root)
{
	queue<Tree*> q;
	stack<Tree*> s;
	
	// Push the root inside the queue
	
	if(root != nullptr) {q.push(root);}
	else {return;}
	
	while(!q.empty())
	{
		Tree* current = q.front();
		q.pop();
		if (current->right != nullptr) {q.push(current->right);}
		if (current->left != nullptr) {q.push(current->left);}
		s.push(current);
	} 
	
	// To print contents of the stack (basically print the final result)
	while(!s.empty())
	{
        cout << " " << s.top()->data;
		s.pop();
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

std::cout << "Level-Order traversal in Reverse: \n";
root->levelOrderInReverse(root); // Expected O/P: 5 9 8 3 6 2 15 30 10 
std::cout << std::endl;

return 0;

}