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


struct node * getNewNode(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node * Insert(struct node * root,int data){
    if(root == NULL){
        root = getNewNode(data);
    }else if(root->data > data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    } 
}//Based on this do traversal



void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",&root->data);
    }
}

void search(int data,struct node *root){
    if(root == NULL){
        printf("Sorry the elemnt is not found");
    }else if(root->data == data){
        printf("Element is found!!");
    }else if(root->data > data){
        search(data,root->left);
    }else{
        search(data,root->right);
    }
}

struct node *Delete(struct  node *root,int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left =Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else{
        //case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
          
        }
        //case 2: one child(left or right)
        
        //left
        else if(root->left == NULL){
            struct node *temp  = root;
            root = root->right;
            free(temp);
                   }

        //right    
         else if(root->right = NULL){
             struct node *temp = root;
             root = root->left;
             free(temp);
            
         }



    }
    return root;
}

struct node * FindMin(struct node *root){
    if(root == NULL) printf("Tree is empty!!");
    while(root->left != NULL){
        root = root->left;    
    }
    return root;
    
  
}
int main(){
    
    struct node * root = NULL;

    root = Insert(root,15);
    root = Insert(root,19);root = Insert(root,7);root = Insert(root,1);root = Insert(root,20);root = Insert(root,10);
    inorder(root);
    struct node *temp = FindMin(root);
    printf("%d",temp->data);
    // int isExetuable = 0;
    // int ch;
    // while(!isExetuable){
        
    //     printf("\t1->Create a binary tree \n\t2->Traversal of tree\n\t3->Search an element in tree");
    //     ch = 1;
    //     switch(ch){
    //         case 1:{
    //             int n;
    //             printf("Enter number of node to be inserted: ");
    //             scanf("%d",&n);
    //             for (int i = 0; i < n; i++)
    //             {
    //                 int data;
    //                 printf("Enter data to be inserted: ");
    //                 scanf("%d",&data);
    //                 root = Insert(root,data);
    //             }
    //             break;
    //         }
    //         case 2:{ 
    //             printf("Inorder Traversal : "); 
    //             inorder(root);  
    //             printf("Preorder Traversal : "); 
    //             preorder(root);  
    //             printf("Post Traversal : "); 
    //             postorder(root);
    //             break;
    //         }  
    //         case 3:{ 
    //             int x;
    //             printf("Enter element to be searched: ");
    //             scanf("%d",&x);
    //             search(x,root);   
    //             break;
    //         }
    //         case 0:{ 
    //             printf("Exiting the application.....");
    //             isExetuable = 1;   
    //             break; 
    //         }
    //     }
    // }
     return 0;
}
