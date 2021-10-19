#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BTNode<int> *takeinput()
{
    int data;
    cout << "enter data";
    cin >> data;
    BTNode<int> *rootnode = new BTNode<int>(data);
    if (data == -1)
    {
        return NULL;
    }
    rootnode->left = takeinput();
    rootnode->right = takeinput();

    return rootnode;
}
BTNode<int> *takeinputlevelwise()
{
    int data;
    cout << "Enter root data" << endl;
    cin >> data;
    BTNode<int> *root = new BTNode<int>(data);
    queue<BTNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        int n1;
        cout << "Enter the left child data of " << f->data << endl;
        cin >> n1;
        if (n1 != -1)
        {
            BTNode<int> *leftchild = new BTNode<int>(n1);
            q.push(leftchild);
            f->left = leftchild;
        }
        int n2;
        cout << "Enter the right child data of " << f->data << endl;
        cin >> n2;
        if (n2 != -1)
        {
            BTNode<int> *rightchild = new BTNode<int>(n2);
            q.push(rightchild);
            f->right = rightchild;
        }
    }
    return root;
}
void print(BTNode<int> *root)
{
    if (root == NULL) //base case
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left)
    {
        cout << "L " << root->left->data << ", ";
    }
    if (root->right)
    {
        cout << "R " << root->right->data << ",";
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
void printlevelwise(BTNode<int> *root)
{

    queue<BTNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        cout << f->data << ": ";
        if (f->left)
        {
            cout << "L " << f->left->data << ",";
            q.push(f->left);
        }
        if (f->right)
        {
            cout << "R " << f->right->data;
            q.push(f->right);
        }
        cout << endl;
    }
}
void inorder(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}
void preorder(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
int minimum(BTNode<int> *root, int &m)
{
    if (root == NULL)
        return 0;
    if (root->data < m)
    {
        m = root->data;
    }
    minimum(root->left, m);
    minimum(root->right, m);
    return m;
}
int min(BTNode<int> *root)
{
    int m = root->data;
    minimum(root, m);
    return m;
}
int countleaf(BTNode<int> *root, int &count)
{
    if (root == NULL)
        return 0;
    if (root->right == NULL && root->left == NULL)
    {
        count++;

        return count;
    }
    countleaf(root->left, count);
    countleaf(root->right, count);
    return count;
}

int countnodes(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countnodes(root->left) + countnodes(root->right) + 1;
}
int height(BTNode<int> *root)
{
    int a = 0;
    int b = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    a += height(root->left) + 1;
    b += height(root->right) + 1;
    return max(a, b);
}
bool path(vector<int> &v, int val, BTNode<int> *root)
{
    // bool check = true;
    if (root == NULL)
        return false;
    if (root->data == val)
    {
        v.push_back(root->data);
        return true;
    }
    if (root->left == NULL && root->right == NULL)
        return false;
    if (root->left == NULL && root->right != NULL)
        return true;
    if (root->left != NULL && root->right == NULL)
        return true;

    if (true)
    {
        v.push_back(root->data);
    }
    else
    {
        v.pop_back();
    }
    path(v, val, root->left);
    path(v, val, root->right);
}
void printlevel(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        cout << f->data;
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        cout << ", ";
    }
}

int main()
{
    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);
    // BTNode<int> *n4 = new BTNode<int>(4);
    // root->left = n1;
    // root->right = n2;
    // n1->left = n4;
    BTNode<int> *root = takeinputlevelwise();
    // printlevel(root);
    //inorder(root);
    //cout<<"the min value is "<<min(root);
    //    int count =0;
    //   cout<<"the leaf nodes are"<< countleaf(root, count);
    //cout<<height(root);
    vector<int> v;
    int val = 7;
    if (path(v, val, root))
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        cout << "path not found";
    }
}