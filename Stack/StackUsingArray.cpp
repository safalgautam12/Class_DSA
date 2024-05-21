#include <iostream> 
using namespace std;
#define n 100
class Stack
{
    public:
    int *arr; 
    int top; 
    Stack()
    {
        arr=new int[n];
        top=-1;

    }
    void push (int data)
    {
        if (isEmpty())
        {
            top++;
            arr[top]=data;
            return;
        }
        
        if (isFull())
        {
            cerr<<"Stack is full\n";
            return;
        }
        top++;
        arr[top]=data;
        
    }
    void pop()
    {
        if (isEmpty())
        {
            cerr<<"Stack is empty\n";
            return;
        }
        top--;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
    return top==n-1;
    }
    
    void Top()
    {
        if (isEmpty())
        {
            cerr<<"Stack is empty\n";
            return;
        }
        cout<<"The top element is : "<<arr[top]<<endl;
    }
    void Traverse()
    {
        if (!isFull()&&!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
    }
    ~Stack()
    {
        delete []arr;
    }

};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.Top();
    cout<<"Traversing the stack\n";
    s.Traverse();
    cout<<"Popping the stack\n";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.isEmpty();
    return 0;

}