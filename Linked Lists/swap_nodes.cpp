/* This program swaps the nodes of linked list rather  
than swapping the field from the nodes.*/
#include <bits/stdc++.h> 
using namespace std; 
  
/* A linked list node */
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
  
/* Function to swap nodes x and y in linked list by  
changing links */
void swapNodes(Node **head_ref, int x, int y)  
{  
    /* Checks: 1. x and y nodes are not the same
    2. x and y nodes are not present in the linked list
    3. Either x or y nodes are the heads  */

    // Check 1: x and y nodes are not the same
    if (x == y)
    {
        cout << "\nThe nodes to be swapped cannot be the same!\n"; 
        return;
    }

    // Keep track of the previous and current x and traverse through the list until you find x node
    Node* prevX = nullptr, *currX = *head_ref;
    while (currX != nullptr && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    // Keep track of the previous and current y and traverse through the list until you find y node
    Node* prevY = nullptr, *currY = *head_ref;
    while (currY != nullptr && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // Check 2: x and y nodes are not present in the linked list
    if (currX == nullptr || currY == nullptr)
    {
        cout << "\nThe nodes to be swapped are not present in the given linked list!\n";
        return;
    }

    // Check 3: Either x or y nodes are the heads
    if (prevX != nullptr) // Not a head
    {
        prevX->next = currY;
    }
    else // Make the current Y node as the new head
    *head_ref = currY;

    if (prevY != nullptr) // Not a head
    {
        prevY->next = currX;
    }
    else // Make the current X node as the new head
    *head_ref = currX;

    // Swap the next pointers of the x and y nodes
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp; 
}  
  
/* Function to add a node at the beginning of List */
void push(Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node =new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
/* Function to print nodes in a given linked list */
void printList(Node *node)  
{  
    while(node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  
  
/* Driver program to test above function */
int main()  
{  
    Node *start = NULL;  
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes(): " << endl;  
    printList(start);  
  
    swapNodes(&start, 1, 3);  
  
    cout << "\nLinked list after calling swapNodes(): " << endl;  
    printList(start);
    cout << " " << endl;   
  
    return 0;  
}  