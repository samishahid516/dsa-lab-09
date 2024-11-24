#include <iostream>
using namespace std;

struct TreeNode
{
    int info;
    TreeNode* left, * right;
};

typedef TreeNode* NODEPTR;

NODEPTR maketree(int x)
{
    NODEPTR p = new TreeNode;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void setleft(NODEPTR p, int x) 
{
    if (p == NULL) 
    {
        cout << "Void Insertion\n";
    }
    else if (p->left != NULL)
    {
        cout << "Invalid Insertion\n";
    }
    else 
    {
        p->left = maketree(x);
    }
}

void setright(NODEPTR p, int x) 
{
    if (p == NULL) 
    {
        cout << "Void Insertion\n";
    }
    else if (p->right != NULL) {
        cout << "Invalid Insertion\n";
    }
    else
    {
        p->right = maketree(x);
    }
}

void pretrav(NODEPTR tree)
{
    if (tree != NULL) 
    {
        cout << tree->info << " ";
        pretrav(tree->left);
        pretrav(tree->right);
    }
}

void intrav(NODEPTR tree) 
{
    if (tree != NULL) 
    {
        intrav(tree->left);
        cout << tree->info << " ";
        intrav(tree->right);
    }
}

void posttrav(NODEPTR tree)
{
    if (tree != NULL)
    {
        posttrav(tree->left);
        posttrav(tree->right);
        cout << tree->info << " ";
    }
}

int main() 
{
    NODEPTR root = maketree(1);
    setleft(root, 2);
    setright(root, 3);
    setleft(root->left, 4);
    setright(root->left, 5);
    setleft(root->right, 6);
    setright(root->right, 7);

    cout << "Pre-order Traversal: ";
    pretrav(root);
    cout << "\n";

    cout << "In-order Traversal: ";
    intrav(root);
    cout << "\n";

    cout << "Post-order Traversal: ";
    posttrav(root);
    cout << "\n";

    return 0;
}
