#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
    
};
class Queue
{
    public:
    Node *front; 
    Node * rear;
    Queue()
    {
        front =rear=NULL;
    }
    void push(int data)
    {
        Node * temp = new Node(data);
        if(front== NULL && rear ==NULL)
        {
            front = rear = temp;
            return;

        }
        Node *n =front;
        while (n->next!=NULL)
        {
            n=n->next;
        }
        n->next=temp;
        rear =temp;
        
        
        
        
    }
    void top()
    {
        if (isEmpty())
        {
            cerr<<"Queue is empty\n";
        }
        
        cout<<"top element\n";
        cout<<front->data;
        cout<<endl;
    }
    void traverse()
    {
        Node *temp=front;
        if (isEmpty())
        {
            cout<<"Queue is empty\n";
            return;
        }
        
        while (temp!=NULL)
        {
            cout<<temp->data << " -> ";
            temp=temp->next;
        }
            cout<<"NULL" <<endl;
        
    }
    void pop()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty\n";
            return;
        }
        
        Node *todelete =front;
        front =front ->next;
        delete todelete;

    }
    bool isEmpty()
    {
        if (front==NULL)
        {
            return true;
        }
        else 
        return false;
        
    }


};
int main()
{
    Queue q;
    cout<<"pushing elements 1, 2, 3 and 4\n";
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.top();
    q.traverse();
    q.pop();  
    cout<<"popping element\n";
    q.top(); 
    cout<<"popping element\n"; 
    q.pop();
    q.top(); 
    q.traverse();   

  
    return 0;
}