#include <bits/stdc++.h>
#include <iostream>

// Create a class for a node of linked list
class Node
{
    public:
        int data;
        Node* next;
};

// Function to print data in the linked list
void printLinkedList(Node* n)
{
    while(n != nullptr)
    {
        std::cout << n->data << std::endl;
        n = n->next;
    }

} 

int main()
{
    // Create a three node single-linked list
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    // Allocate 3 nodes on the heap memory
    head = new Node();
    second = new Node();
    third = new Node();

    // Linking the three nodes and also reprenting them usin some random data
    head->data = 1;
    head->next = second;  // linking he head node to the second node

    // Similarly done to the other nodes
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr; // the linked list terminates after the third node

    // To test print function
    printLinkedList(head);

    return 0;
}