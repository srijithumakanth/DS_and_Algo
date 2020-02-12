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

    push(&head, 4);
    insertAfter(second, 5);
    append(&head, 6);
    printLinkedList(head);

    return 0;
}