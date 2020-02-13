// Iterative C++ program to find length  
// or count of nodes in a linked list  
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  
void printLinkedList(Node* n)
{
    while(n != nullptr)
    {
        std::cout << n->data << std::endl;
        n = n->next;
    }
}

/* Given a reference (pointer to pointer) to the head  
of a list and an int, push a new node on the front  
of the list. */
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
  
/* Counts no. of nodes in linked list (Iterative) */
int getCountIterative(Node* head)  
{  
    int count = 0; // Initialize count  
    Node* current = head; // Initialize current  
    while (current != nullptr)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
  
/* Counts no. of nodes in linked list (Recursive) */
int getCountRecursive(Node* head)
{
    // Base case: no nodes in linked list
    if (head == nullptr){return 0;}
    // Remaining cases: Recursivly traverse through the list adding 1 each time
    return (1 + getCountRecursive(head->next));
}

/* Driver program to test count function*/
int main()  
{  
    /* Start with the empty list */
    Node* head = nullptr;  
  
    /* Use push() to construct below list  
    1->2->1->3->1 */
    push(&head, 1);  
    push(&head, 3);  
    push(&head, 1);  
    push(&head, 2);  
    push(&head, 1);  
  
    /* Check the count function */
    cout<<"count of nodes (Iterative) is: "<< getCountIterative(head) << endl; 
    cout<<"count of nodes (Recursive) is: "<< getCountRecursive(head) << endl;  
    return 0;  
}  