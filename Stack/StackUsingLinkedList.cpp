#include <iostream>
using namespace std; 
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
    this->data=data;
       this->next=NULL;
    }
};
class Stack
{
    public: 
    Node* head;
    int size;
    Stack()
    {
        head=NULL;
        size=0;
    }
 
    void push(int data)
    {
        Node *temp=new Node(data);
        if (head==NULL)
        {
            head=temp;
            size++;
            return;
        }
        temp->next=head;// since we are adding at the beginning
        head=temp;
        
        
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    
    void traverse()
    {
       Node *temp=head;
       while (temp!=NULL)
       {
        cout<<temp->data<<" ->  ";
        temp=temp->next;
       }
       cout<<"NULL"<<endl;
        

    }
    void pop()
    { 
        if (isEmpty())
        {
            cerr<<"Stack is empty\n";
            return;
        }
        if (head->next=NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        
          Node *toDelete=head;
    head=head->next;
    delete toDelete;

    }
       ~Stack()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            Node*next=temp->next;
            delete temp;
            temp=next;
        }
        
    }

};
int main()
{
    Stack s;
    cout<<"Adding 1 to the stack\n";
    s.push(1);
    s.traverse();
    cout<<"poppint the element\n";
    s.pop();
    cout<<"pushing 2 and 3 to the stack\n";
    s.push(2);
    s.push(3);
    s.traverse();
    cout<<"popping once\n";
    s.pop();
    s.traverse();
    return 0;
}