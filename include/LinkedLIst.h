#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
    int info;
    Node *next;
    Node() {}
    Node(int d) : info(d), next(nullptr) {}
    Node(int d, Node *next) : info(d), next(next) {}
};
class LinkedList
{
private:
    Node *head;
    Node *tail;
public:
LinkedList(){}
~LinkedList(){}
void add( int data);
void addToHead(int data);
void addToTail(int data);

bool remove(int data);
bool removeFromHead(int data);
bool removeFromTail(int data);
};
void LinkedList::add(int data)
{

Node *node =new Node();
node->info=data;
node->next=this->head;
this->head=node;
    

}
void LinkedList::addToHead(int data)
{
    Node* temp=new Node();// it has a value and a pointer 
    if (head!=nullptr)
    {
        temp->info=data;
        temp->next=head;
    }
    if (head==nullptr)
    {
        temp->info=data;
    }
    
    
}
