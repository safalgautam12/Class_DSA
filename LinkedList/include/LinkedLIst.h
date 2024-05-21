#pragma once
#include <iostream>
using namespace std;

// Node class for creating individual nodes of the linked list
class node
{
public:
    node *next; // Points to the next node
    int data;   // Stores the data of the node

    // Constructor to initialize node with given value
    node(int val)
    {
        next = NULL;
        data = val;
    }
};

// List class for managing the linked list operations
class List
{
private:
    node *head; // Points to the first node of the list
    node *tail; // Points to the last node of the list

public:
    // Constructor to initialize an empty list
    List() : head(NULL), tail(NULL) {}

    // Check if the list is empty
    bool isEmpty()
    {
        return head == NULL;
    }

    // Insert a new node at the beginning of the list
    // Comment: Inserts a new node at the beginning of the list.
    void insertAtHead(int data)
    {
        node *n = new node(data); // Create a new node
        if (isEmpty())            // Check if list is empty
        {
            head = tail = n; // If empty, set head and tail to the new node
        }
        n->next = head; // Set the next pointer of the new node
        head = n;       // Update head to point to the new node
    }

    // Insert a new node at the end of the list
    // Comment: Inserts a new node at the end of the list.
    void insertAtTail(int data)
    {
        node *n = new node(data); // Create a new node
        if (isEmpty())            // Check if list is empty
        {
            head = tail = n; // If empty, set head and tail to the new node
            return;
        }
        tail->next = n; // Set the next pointer of the last node to the new node
        tail = n;       // Update tail to point to the new node
    }

    // Traverse the list and print its elements
    // Comment: Traverses the list and prints its elements.
    void traverse()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->"; // Print data of current node
            temp = temp->next;          // Move to the next node
        }
        cout << "NULL";
    }

    // Delete the first node of the list
    // Comment: Deletes the first node of the list.
    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "Nothing to delete";
            return;
        }
        node *todelete = head;
        head = head->next; // Move head to the next node
        delete todelete;   // Delete the previous head node
    }

    // Delete the node with the given key
    // Comment: Deletes the node with the given key.
    void deletion(int key)
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            deleteAtHead();
            return;
        }
        node *temp = head;
        while (temp->next->data != key)
        {
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }

    // Delete the last node of the list
    // Comment: Deletes the last node of the list.
    void deleteAtTail()
    {
        if (isEmpty())
        {
            cout << "list is empty";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Search for a node with the given key
    // Comment: Searches for a node with the given key.
    bool search(int key)
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return false;
        }
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Retrieve the node with the given key
    // Comment: Retrieves the node with the given key.
    node *retrieved(int key)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Display the value and address of a single node
    // Comment: Displays the value and address of a single node.
    void display_single_node(node *&add)
    {
        cout << "value = " << add->data << " address = " << add << endl;
    }

    // Add a new node with the given key after the specified predecessor node
    // Comment: Adds a new node with the given key after the specified predecessor node.
    void add(int key, node *predecessor)
    {
        if (predecessor == NULL)
        {
            cout << "Predecessor node cannot be null." << endl;
            return;
        }
        node *n = new node(key);
        n->next = predecessor->next;
        predecessor->next = n;
    }
    // to fetch the head.
    node *getHead() const
    {
        return head;
    }
    // Destructor to release memory allocated for nodes
    // Comment: Destructor to release memory allocated for nodes.
    ~List()
    {
        node *current = head;      // Start with the head node
        while (current != NULL) // Loop until current node is not null
        {
            node *next = current->next; // Store the next node before deleting the current one
            delete current;             // Delete the current node
            current = next;             // Move to the next node
        }
        head = tail = NULL; // Set head and tail pointers to null to indicate an empty list
    }
};
