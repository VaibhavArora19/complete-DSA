#include<iostream>
using namespace std;
template<typename T>
class queue
{
    T *arr;
    int size;
    int capacity;
    int firstindex;
    int nextindex;
    public:
    queue()
    {
        capacity = 5;
        arr = new T[capacity];
        size = 0;
        firstindex = -1;
        nextindex =0;
        
    }
    
    int getsize()
    {
return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void push(T ele)
    {
    if(size == capacity)
    {
        T *newarr = new T[2*capacity];
        int j =0;
        for(int i =firstindex; i<capacity; i++)
        {
            newarr[j] = arr[i];
            j++;
        }
        for(int i =0; i<firstindex; i++)
        {
            newarr[j] = arr[i];
            j++;
        }
            delete []arr;
            arr = newarr;
            nextindex = size;
            capacity = 2*capacity;
            firstindex =0;
    }

    arr[nextindex] = ele;
    nextindex = (nextindex + 1)%capacity;
    if(firstindex == -1)
    {
        firstindex = 0;
    }
    size++;
    }
    T front()
    {
        if(isempty())
        {
            cout<<"queue is empty";
            return 0;
        }
        return arr[firstindex];
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"queue is empty";
            return;
        }
        firstindex = (firstindex+1)%capacity;
        size--;
        if(size==0)
        {
            firstindex = -1;
            nextindex =0;
        }
    }

};
int main()
{
queue<int> q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);
q.push(70);
cout<<q.getsize()<<endl;
cout<<q.front()<<endl;
q.pop();
q.pop();
q.pop();
cout<<q.front()<<endl;
cout<<q.getsize()<<endl;
cout<<q.isempty()<<endl;
q.push(60);
q.push(70);
q.pop();
q.pop();
cout<<q.front()<<endl;
cout<<q.getsize()<<endl;

}