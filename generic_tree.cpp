#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class treenode
{
public:
    T data;
    vector<treenode<T> *> children;
    treenode(T data)
    {
        this->data = data;
    }
    ~treenode()
    {
        for(int i =0; i<children.size(); i++)
        {
            delete children[i];
        }
    }
};
treenode<int> *takeinput()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    treenode<int> *root = new treenode<int>(data);
    int n;
    cout << "Enter the number of children of " << data << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}
treenode<int> *takeinputlevelwise()
{
    queue<treenode<int> *> q;
    int data;
    cout << "Enter root data" << endl;
    cin >> data;
    treenode<int> *root = new treenode<int>(data);
    q.push(root);

    while (!q.empty())
    {
        treenode<int> *f = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children of " << f->data << endl;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {

            int childdata;
            cout << "enter the data of " << i << " th child of " << f->data << endl;
            cin >> childdata;
            treenode<int> *childnode = new treenode<int>(childdata);
            q.push(childnode);
            f->children.push_back(childnode);
        }
    }
    return root;
}
int countnodes(treenode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ans =1;
    for(int i =0; i<root->children.size(); i++)
    {
        ans += countnodes(root->children[i]);
    }
    return ans;
}
void printlevelwise(treenode<int> *root)
{
    //cout<<root->data;
    queue<treenode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        treenode<int> *f = q.front();
        q.pop();
        cout << f->data << ": ";
        for (int i = 0; i < f->children.size(); i++)
        {
            cout << f->children[i]->data << ",";
            q.push(f->children[i]);
        }
        cout<<"NULL";
        cout << endl;
    }
}
int height(treenode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int mx =0;
    for(int i =0; i<root->children.size(); i++)
    {
        int childheight = height(root->children[i]);
        if(childheight>mx)
        {
            mx = childheight;
        }
    }
    return mx+1;
}
void printatlevelk(treenode<int> *root, int k)
{
if(k==0)
{
    cout<<"the root at  level k are "<<root->data<<endl;
    return;
}
for(int i =0; i<root->children.size(); i++)
{
printatlevelk(root->children[i], k-1);
}
}
void preordertraversal(treenode<int> *root)
{
    cout<<root->data<<endl;
    for(int i =0; i<root->children.size(); i++)
    {
        preordertraversal(root->children[i]);
    }
}
int countleaf(treenode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
return 1;
    }
    int ans =0;
    for(int i =0; i<root->children.size(); i++)
    {
        ans += countleaf(root->children[i]);
    }
    return ans;
}
void postordertraversal(treenode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i =0; i<root->children.size(); i++)
    {
        postordertraversal(root->children[i]);
    }
    cout<<root->data<<endl;
}
void deletenode(treenode<int> *root)
{
    for(int i =0; i<root->children.size(); i++)
    {
        deletenode(root->children[i]);
    }
    delete root;
}
void print(treenode<int> *root)
{
    if (root == NULL) //edge case not base case
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}
int main()
{
    // treenode<int> *root = new treenode<int>(1);
    // treenode<int> *n1 = new treenode<int>(2);
    // treenode<int> *n2 = new treenode<int>(3);
    // //treenode<int> *n3 = new treenode<int>(4);
    // root->children.push_back(n1);
    // root->children.push_back(n2);
    // //n1->children.push_back(n3);
    treenode<int> *root = takeinputlevelwise();
    //cout<<"the total number of nodes are "<<countnodes(root);
   // cout<<"the heigth of the tree is "<<height(root);
    //printlevelwise(root);
    //printatlevelk(root, 2);
    //cout<<countleaf(root);
    preordertraversal(root);
    //deletenode(root);
    delete root; //this is calling the destructor in treenode class
}