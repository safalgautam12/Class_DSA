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
 
    Stack()
    {
        head=NULL;
      
    }
 
    void push(int data)
    {
        Node *temp=new Node(data);
        if (head==NULL)
        {
            head=temp;
            return;
        }
        Node *n=head;
        while (n->next!=NULL)
        {n=n->next;
            
        }
        n->next=temp;
        
        
        
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
        if (head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        
    Node*toDelete = head;
    while (toDelete->next->next!=NULL)
    {
        toDelete=toDelete->next;

    }
    delete toDelete->next;
    toDelete->next=NULL;
    

    }
    void top()
    {
        Node *temp=head;
        if (!isEmpty())
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            cout<<"top = "<< temp->data;
            cout<<endl;
            
        }
        
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
    s.top();
    cout<<"popping the element\n";
    s.pop();
    cout<<"pushing 2 , 3 and 4 to the stack\n";
    s.push(2);
    s.push(3);
    s.push(4);
    s.top();
    s.traverse();
    cout<<"popping once\n";
    s.pop();
    s.traverse();
    return 0;
}