#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode<T> *left;
    BTNode<T> *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};
class Pair
{
public:
    BTNode<int> *head;
    BTNode<int> *tail;
};
class BST
{
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == NULL)
        { /// base case
            return;
        }

        cout << root->data << ": ";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }
    bool hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }

        if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }

    BTNode<int> *insert(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }
    BTNode<int> *deleteData(BTNode<int> *root, int data)
    {
        if (root == NULL)
            return NULL;
        if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {

                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                BTNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                BTNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BTNode<int> *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                int mindata = temp->data;
                root->data = mindata;
                root->right = deleteData(root->right, mindata);
            }
        }
        else if (root->data > data)
        {
            root->left = deleteData(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = deleteData(root->right, data);
        }
        return root;
    }
    Pair converttoLL(BTNode<int> *root)
    {
        if (root == NULL)
        {
            Pair ans;
            ans.head = NULL;
            ans.tail = NULL;
            return ans;
        }
        if (root->right == NULL && root->left == NULL)
        {
            Pair ans;
            ans.head = root;
            ans.tail = root;
            return ans;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Pair leftLL = converttoLL(root->left);
            leftLL.tail->right = root;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = root;
            return ans;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            Pair rightLL = converttoLL(root->right);
            root->right = rightLL.head;
            Pair ans;
            ans.head = root;
            ans.tail = rightLL.tail;
            return ans;
        }
        else
        {
            Pair leftLL = converttoLL(root->left);
            Pair rightLL = converttoLL(root->right);
            leftLL.tail->right = root;
            root->right = rightLL.head;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = rightLL.tail;
            return ans;
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(root, data);
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void print()
    {
        printTree(root);
    }
    BTNode<int> *converttoLL()
    {
        Pair p = converttoLL(root);
        BTNode<int> *temp = p.head;
        while (temp)
        {
            temp->left = NULL;
            // cout<<temp->data<<"->";
            temp = temp->right;
        }
        return p.head;
    }
};
int main()
{
    BST b;
    b.insert(10);
    b.insert(7);
    b.insert(14);
    b.insert(6);
    b.insert(8);
    b.insert(12);
    b.insert(15);
    b.insert(13);
    b.print();
    BTNode<int> *root = b.converttoLL();
    while (root)
    {
        cout << root->data << "->";
        root = root->right;
    }

    return 0;
}
