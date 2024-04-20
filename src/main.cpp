#include <iostream>
#include "../include/LinkedLIst.h"
// Main function to test the List class
int main()
{
    List list;
    // Insert nodes at the head
    list.insertAtHead(0);
    list.insertAtHead(4);
    list.insertAtHead(5);

    // Insert nodes at the tail
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);

    cout << "Linked list after insertion:\n";
    list.traverse();
    cout << endl;

    // Delete the last node
    list.deleteAtTail();
    cout << "Linked list after deleting the last node:\n";
    list.traverse();
    cout << endl;

    // Retrieve a node
    node *check = list.retrieved(1);
    cout << "Retrieved node:\n";
    list.display_single_node(check);

    // Add a new node after the retrieved node
    list.add(100, check);
    cout << "Linked list after adding a new node after the retrieved node:\n";
    list.traverse();
    cout << endl;

    // Delete the first node
    list.deleteAtHead();
    cout << "Linked list after deleting the first node:\n";
    list.traverse();
    cout << endl;

    // Delete a node with a specific key
    list.deletion(100);
    cout << "Linked list after deleting a node with key 3:\n";
    list.traverse();
    cout << endl;

    return 0;
}
