#include<iostream>
#include<vector>
using namespace std;
class Stack
{
vector<int> v;
int nextindex;
public:
Stack()
{
    nextindex =0;
}
int size()
{
    return v.size();
}
bool isEmpty()
{
    return nextindex ==0;
}
void push(int ele)
{
    v.push_back(ele);
    nextindex++;
}
void pop()
{
    if(nextindex ==0)
    {
        cout<<"Stack Empty";
    }
    v.pop_back();
    nextindex--;
}
int top()
{
    return v[nextindex -1];
}

};
int main()
{
Stack s;
s.push(10);
s.push(20);
s.push(30);
cout<<endl;
cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;
s.pop();
cout<<s.size()<<endl;
cout<<s.isEmpty();
}