#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

int countNode(struct node *root)
{
    if (root != NULL)
        return (1 + countNode(root->left) + countNode(root->right));
    else
        return 0;
}

int countNullLink(struct node *root)
{
    if (root != NULL)
        return (0 + countNullLink(root->left) + countNullLink(root->right));
    else
        return 1;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    struct node *root, *temp;
    int value1, value2;
    //creating root node
    root=new node;
    cout<<"Enter data of root: ";
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;

    //creating left child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->left=temp;

    //creating right child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->right=temp;

    //creating left child of left child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->left->left=temp;

    //creating right child of left child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->left->right=temp;

    //creating left child of right child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->right->left=temp;

    //creating right child of right child of root
    temp=new node;
    cout<<"Enter data of temp: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    root->right->right=temp;

    cout<<"Preorder traversal:\n";
    preorder(root);
    cout<<"\nInorder traversal:\n";
    inorder(root);
    cout<<"\nPostorder traversal:\n";
    postorder(root);
    
    value1 = countNode(root);
    cout<<"\nTotal number of node is: "<<value1;

    value2 = countNullLink(root);
    cout<<"\nTotal number of null links are: "<<value2;
    
    return 0;
}
