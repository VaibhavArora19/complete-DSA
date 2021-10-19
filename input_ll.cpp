#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Node(int data)
    // {
    //     this->data = data;
    //     next = NULL;
    // }
};
void print(Node *&head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
}
int length(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        //Node n;
        Node *n = new Node();
        n->data = data;
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *insert(Node *head, int data, int i)
{
    Node *temp = head;
    Node *n = new Node();
    n->data = data;
    int count = 0;
    if (i < 0)
    {
        return head;
    }
    if (i == 0)
    {
        n->next = temp;
        temp = n;
        return temp;
    }
    while (temp != NULL)
    {
        if (count == i - 1)
        {
            n->next = temp->next;
            temp->next = n;
            break;
        }
        count++;
        temp = temp->next;
    }
    //cout<<"the count is "<<count<<endl;
    return head;
}
Node *deleteelement(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    if (i < 0)
    {
        return head;
    }
    if (i == 0 && head)
    {
        Node *newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }
    while (temp != NULL)
    {
        if (count == i - 1)
        {
            if (temp && temp->next)

            {
                Node *dlt = temp->next;
                temp->next = temp->next->next;
                dlt->next = NULL;
                delete dlt;
                return head;
            }
        }
        count++;
        temp = temp->next;
    }
    return head;
}
bool ispresent(Node *head, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int findnode(Node *head, int i)
{
    int ans = -1;
    int index = 0;
    Node *temp = head;
    while (head != NULL)
    {

        if (index == i)
        {
            ans = head->data;
        }
        index++;
        head = head->next;
    }
    return ans;
}
int main()
{
    Node *head = takeinput();
    print(head);
    cout << endl;
    // int i;
    // cin>>i;
    //int data = 60;
    //cout<<"the node at index "<<i<<" is "<<findnode(head, i);
    //Node *head2 = insert(head, data, i);
    //cout<<"Linked List after inserting element at index "<<i<<" is "<<endl;
    //Node *head2 = deleteelement( head,  i);
    //print(head2);
    if (ispresent(head, 15))
    {
        cout << "Element is present ";
    }
    else
    {
        cout << "Not found";
    }
}