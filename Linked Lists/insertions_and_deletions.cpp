#include <bits/stdc++.h>
#include <iostream>

class Node
{
    public:
        int data;
        Node* next;
};

// Function to print data members from a linked list.
void printLinkedList(Node* n)
{
    while(n != nullptr)
    {
        std::cout << n->data << std::endl;
        n = n->next;
    }
}

/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
    // 1. Allocate new_node on the heap memory
    Node* new_node = new Node();
    // 2. Add the ne data to the new_node
    new_node->data = new_data;
    // 3. Make the new_node as the new head
    new_node->next = (*head_ref);
    // 4. Move the current head to the new_node
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given  
prev_node */
void insertAfter(Node* prev_node, int new_data)
{
    // 1. Check if the prev_node is not a null node
    if (prev_node == nullptr)
    {
        std::cout << " The Previous node cannot be NULL\n";
        return;
    }
    // 2. Allocate new_node on the heap memory
    Node* new_node = new Node();
    // 3. Add new_data to the new_node
    new_node->data = new_data;
    // 4. Make the next of the new_node equal to the next of the prev_node
    new_node->next = prev_node->next;
    // 5. Make the prev_node point to the new_node
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
    // 1. Allocate the new_node on the heap memory
    Node* new_node = new Node();
    // 2. Add new_data to the new_node
    new_node->data = new_data;
    // 3. Make the next pointer variable of new_node point to NULL
    new_node->next = nullptr;
    // 4. If the Linked List is empty, then make the new node as head  
    if(*head_ref == nullptr)
    {
        *head_ref = new_node;
        return;
    }
    // 5. Else traverse till the last node in the linked-list
    Node* last = *head_ref;
    while(last->next != nullptr)
    {
        last = last->next;
    }
    // 6. Point the last node in the linked-list to the new_node
    last->next = new_node;

    return;
}

/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(Node** head_ref, int key)
{
    // Store the head node as temp
    Node* temp = *head_ref, *prev;
    // If head node itself holds the key to be deleted
    if(temp != nullptr && temp->data == key)
    {
        *head_ref = temp->next; // Change head 
        delete(temp); // Free the old memory
        return;
    }
    // If head does not hold the key, then traverse through the list to find it
    while(temp != nullptr && temp->data != key)
    {
        prev = temp; // keeping track of the previous node from he node to be deleted
        temp = temp->next; 
    }
    // If no key is found in the linked-list
    if(temp == nullptr) {return;}

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Delete the old node's memory
    delete(temp);

    return;
}

/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNodeAtPos(Node** head_ref, int position)
{
    /* Checks:  1. If the list is empty, 2 Position exceeds the no. of nodes in the list */

    // Check 1: If the list is empty
    if(*head_ref == nullptr){return;}

    // (1). If the position is equal to the root node
    // Store the head reference into a temp pointer variable
    Node* temp = *head_ref;
    if(position == 0)
    {
        // Change head
        *head_ref = temp->next;
        // Delete the temp node from the memory
        delete(temp);
        return;
    }
    
    // (2). If the position is not zero, then traverse through the list to find the previous node of the node to be deleted
    for (int i = 0; temp != nullptr && i < (position-1); i++)
    {
        temp = temp->next;
    }
    // Check 2: Position exceeds the no. of nodes in the list
    if (temp == nullptr || temp->next == nullptr)
    {
        std::cout << "Position exceeds the number of nodes in the list.\n";
        return;
    }

    // (3). Node (temp) is the previous node and Node (temp->next) is the node to be deleted
    // Store the next of Node (temp->next) for the previous node to be updated with after (temp->next) is deleted
    Node* next = temp->next->next;
    
    // Delete the node to be deleted (temp->next)
    delete(temp->next);

    // Unlink the deleted node from the linked list and update the next of the previous node to point to the next of the node jude deleted
    temp->next = next; 
}

int main()
{
    // allocate memory on the heap for 3 nodes
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    // Start linking the nodes together with random data to form a single-linked-list
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    push(&head, 4); // to the front of the list
    insertAfter(second, 5); // Insert after a particular node
    append(&head, 6); // To the end of the list
    deleteNode(&head, 4); // Delete a particular node with the corresponsing key
    deleteNodeAtPos(&head, 2);  // Delete a node at a particular position
    printLinkedList(head); // Print akk the data in the linked-list

    return 0;
}