#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data ;
    struct node *left,*right;
};
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
};
/*TRAVERSAL*/
void inorder(struct node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
/*INSERTION*/
struct node* insert_tree(struct node* node, int data)
{
    if (node==NULL)
    {
        return newNode(data);
    }
    if(data<node->data)
    {
        node->left = insert_tree(node->left,data);
    }
    else if(data>node->data)
    {
        node->right = insert_tree(node->right,data);
    }

    return node;
};
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
       {current = current->left; }
    return current;
};
/*DELETION*/
struct node* delete_node(struct node* root,int data)
{
    if (root == NULL)
        {   cout<<"Root not found"<<endl;
            return root;}
    if (data<root->data)
    {
        root->left = delete_node(root->left,data);
    }
    else if (data > root->data)
        {root->right = delete_node(root->right, data);}
    else
    {
        if(root->left==NULL)
        {
            struct node *temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

    struct node* temp = minValueNode(root->right);

    root->data = temp->data;

    root->right = delete_node(root->right,temp->data);
    }
    return root;
};

/*COUNT NO OF NODES*/


int Countnodes(node*root,int i)
{

    if(root==NULL)
    {
        return 0;
    }

    else{
    if(root->left!=NULL)
    {
        i = i+1;
        i = Countnodes(root->left,i);
    }
    if(root->right!=NULL)
    {
        i = i+1;
        i = Countnodes(root->right,i);
    }}
    return i;
}

int main()

{   int i=1;
    struct node *root = NULL;
    root = insert_tree(root,40);
    insert_tree(root,20);
    insert_tree(root,10);
    insert_tree(root,30);
    insert_tree(root,60);
    insert_tree(root,50);
    insert_tree(root,70);

    cout<<"Inorder traversal of the given tree "<<endl;
    inorder(root);
    cout<<"TOTAL NO OF NODES = "<<Countnodes(root,i)<<endl;

    cout<<"Delete 20"<<endl;
    root = delete_node(root,20 );
    cout<<"Inorder traversal of the modified tree"<<endl;
    inorder(root);
    cout<<"TOTAL NO OF NODES = "<<Countnodes(root,i)<<endl;



    cout<<"Delete 30"<<endl;
    root = delete_node(root, 30);
    cout<<"Inorder traversal of the modified tree"<<endl;
    inorder(root);
    cout<<"TOTAL NO OF NODES = "<<Countnodes(root,i)<<endl;

    cout<<"Delete 50"<<endl;
    root = delete_node(root, 50);
    cout<<"Inorder traversal of the modified tree"<<endl;
    inorder(root);
    cout<<"TOTAL NO OF NODES = "<<Countnodes(root,i)<<endl;

    cout<<"Delete 100"<<endl;
    root = delete_node(root,100);
    cout<<"Inorder traversal of the modified tree"<<endl;
    inorder(root);
    return 0;
}
