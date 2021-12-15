#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * right;
    struct node *left;
};

struct node *rootPtr;//to store root node;

struct node * getNode(int data){
    struct node * newnode  = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;

}

struct node * insert(struct node *root,int data){
    if(root == NULL){
        root = getNode(data);
    }else if(root->data > data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void main(){

    struct node *root;
    root = NULL;
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,7);
    root = insert(root,8);
    root = insert(root,9);
    inorder(root);
}