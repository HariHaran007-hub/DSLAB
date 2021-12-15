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
    }else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    } 
}

void inorder(struct node *root){
    if(root != NULL){
         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
    }
}





struct node * Delete(struct node * root,int data){
    if(root == NULL) printf("Tree is empty");
    else if(root->data > data) root->left = Delete(root->left,data);
    else if(root->data < data ) root->right = Delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);

        }else if(root->left == NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
        }else{
            int d= Findmin(root->right);
            root->data =d;
            root->right = Delete(root->right,root->data);

        }

    }
    return root;
}
int Findmin(struct node *root){
    if(root == NULL){
        printf("Tree is emoty");
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
void main(){

    struct node *root = NULL;
    root = insert(root,5);
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,9);
    root = insert(root,4);
    inorder(root);
    printf("\n%d",(Delete(root,2))->data);
     inorder(root);
}