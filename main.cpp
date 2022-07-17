#include <iostream>
#include <queue>

using namespace std;

//1)linear search
int linearSeach(string arr[], int n, string key)
{
    for(int i = 0; i < n; i++)
    {
        if(key == arr[i])
        {
            cout << "item " << key << " is at index " << i;
            return i;
        }
    }
    cout << "item is not found";
    return -1;
}

//2)binary search loop
int binarySearch(int arr[], int n, int key)
{
    int counter = 0;
    int s, m, e;
    s = 0;
    e = n-1;

    while(s <= e)
    {
        m = (s+e)/2;
        if(key == arr[m])
        {
            cout << "item " << key << " is at index " << m;
            return m;
        }
        else if(key > arr[m])
        {
            s = m+1;
        }
        else
        {
            e = m-1;
        }
        counter++;
    }
    cout << "item is not found\n";
    return -1;
}

//2)binary search recursion
int binarySearchRec(int arr[], int n, int key, int s, int e)
{
    int m = (s+e)/2;

    if(key == arr[m])
    {
        cout << "item is found\n";
        return m;
    }

    if(key > arr[m] && s <= e)
    {
        s = m+1;
        return binarySearchRec(arr, n, key, s, e);
    }

    if(key < arr[m] && s <= e)
    {
        e = m-1;
        return binarySearchRec(arr, n, key, s, e);
    }
    return -1;
}



//binary search tree to apply bfs & dfs on
class Node
{
public:
    int value;
    Node* right;
    Node* left;

    Node(int v):value(v),right(NULL),left(NULL)
    {
    }
};

class BinaryST
{
public:
    Node* root;
public:
    BinaryST():root(NULL)
    {
    }

    //insertion
    Node* insertion(Node* r, int n)
    {
        if(r == NULL)
        {
            Node* newnode = new Node(n);
            r = newnode;
        }
        else if(n > r->value)
            r->right = insertion(r->right, n);
        else if(n < r->value)
            r->left = insertion(r->left, n);

        return r;
    }

    //insertion user
    void insertion(int x)
    {
        root = insertion(root, x);
    }

};

//3)breadth first search for tree
void breadthFirst(Node* r)
{
    queue<Node*>q;
    Node* temp = r;
    Node* fr;

    q.push(temp);

    while(!q.empty())
    {
        fr = q.front();
        cout << fr->value << " ";
        q.pop();
        if(fr->left)
            q.push(fr->left);
        if(fr->right)
            q.push(fr->right);
    }
}

//4)Depth first search for tree
//a)Preorder
void preOrder(Node* r)
{
    if(r == NULL)
        return;
    cout << r->value << " ";
    preOrder(r->left);
    preOrder(r->right);
}

//b)Inorder
void inOrder(Node* r)
{
    if(r == NULL)
        return;
    inOrder(r->left);
    cout << r->value << " ";
    inOrder(r->right);
}

//c)Postorder
void postOrder(Node* r)
{
    if(r == NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->value << " ";
}


int main()
{
    //int nums[] = {2, 4, 6, 8, 10, 12, 14, 16};

    //binarySearchRec(nums, 8, 20, 0, 7);

    BinaryST bt;

    bt.insertion(10);
    bt.insertion(8);
    bt.insertion(12);
    bt.insertion(6);
    bt.insertion(9);
    bt.insertion(11);
    bt.insertion(15);

    postOrder(bt.root);

    return 0;
}
