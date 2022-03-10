#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *left,*right;
};
int size;
struct node *head;
struct node * newnode,*temp;
struct node* create(int data){
	newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
struct node * insert(struct node * root ,int data){
	if(root == NULL){
		root = create(data);
		return root;
	}

	else if(data < root->data){
		root->left = insert(root->left,data);
	}
	else if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}
void inorder(struct node * root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(struct node * root){
	if(root == NULL){
		return;
	}

	printf("%d ",root->data);
	inorder(root->left);
	inorder(root->right);
}


int min_value(struct node * root){
	if(root->left == NULL){
		return root->data;
	}

	return min_value(root->left);
}

int max_value(struct node * root){
	if(root->right == NULL){
		return root->data;
	}

	return min_value(root->right);
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


struct node * delete_element(struct node * root,int data){
	if(root == NULL){
		printf("Under flow error");
	}
	else if(data < root->data){
		root->left = delete_element(root->left,data);
	}
	else if(data > root->data){
		root->right = delete_element(root->right,data);
	}
	else if (root-> data == data){

		if(root->right == NULL && root->left == NULL){
			root = NULL;
			free(root);
			printf("Element deleted!!");
		}
		else if(root->right == NULL){
			struct node * temp = root;
			root = root->left;
			free(temp);
		}
		else if(root->left == NULL){
			struct node * temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->left != NULL && root->right != NULL){
			root->data = max_value(root->left);
			root->left = delete_element(root->left,root->data);;
		}
	}
	return root;

}



void main(){
	head = insert(head,15);
	head = insert(head,20);
	head = insert(head,25);
	head = insert(head,2);
	head = insert(head,6);
	inorder(head);
	search(100,head);
	delete_element(head,2);
	inorder(head);
	delete_element(head,15);
	inorder(head);

}
