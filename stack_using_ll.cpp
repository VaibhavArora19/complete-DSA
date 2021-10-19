#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node<T> *next;
    Node(T data)
    {
  this->data = data;
  next = NULL;      
    }
};
template<typename T>
class Stack
{
Node<T> *head;
int count;
public:
Stack()
{
    head = NULL;
    count = 0;
}
int size()
{
    return count;
}
bool isEmpty()
{
    return count == 0;
}

void push(T ele)
{
    Node<T> *n = new Node<T>(ele);
    n->next = head;
    head = n;
    count++;
}
void pop()
{
    if(head == NULL)
    {
cout<<"Stack empty";
return;
    }
    Node<T> *temp = head;
    head  = head->next;
    temp->next = NULL;
    delete temp;
    count--;
}
T top()
{
    if(isEmpty())
    {
        cout<<"stack is empty";
    }
    return head->data;
}
int getmin()
{
    Node<T> *temp = head;
    Node<T> *temp2 = head->next;
    int min = temp->data;
    if(head->next == NULL)
    {
return head->data;
    }
    while(temp->next!=NULL && temp2->next!=NULL)
    {
    if(temp2->data<temp->data)
    {
    
        min = temp2->data;
    }
    temp = temp->next;
    temp2 = temp2->next;
    }
    return min;
}
};
int main()
{
Stack<int> s;
s.push(-2);
s.push(0);
s.push(-3);
//cout<<s.top();
cout<<s.getmin();
cout<<endl;
s.pop();
cout<<s.top();
s.pop();
//cout<<s.top();
cout<<s.getmin();
// cout<<s.size()<<endl;
// cout<<s.isEmpty();
// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// cout<<endl;
// cout<<s.top()<<endl;
// s.pop();
// cout<<s.top()<<endl;
// s.pop();
// cout<<s.top()<<endl;
// s.pop();
// cout<<s.isEmpty();
}
