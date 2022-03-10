#include<stdio.h>
#include<conio.h>
#define MAX 10
int matrix[MAX][MAX];
int visited_vertex[MAX];
int vertex,orgin,destination,edges,source;
int graph_type;

void create_graph(){
	printf("Enter graph type: 1->Undirected 2->directed: ");
	scanf("%d",&graph_type);

	printf("\nEnter vertex: ");
	scanf("%d",&vertex);

	if(graph_type == 1){
		edges = vertex*(vertex - 1)/2;
	}


	if(graph_type == 2){
		edges = vertex*(vertex - 1);
	}

	for(int i = 1 ; i <= edges ; i ++){
		printf("Enter orgin and destination [-1 , -1 for exit the application]: ");
		scanf("%d %d",&orgin,&destination);

		if(orgin == -1 && destination == -1){
			break;
		}

		if(orgin >= vertex || destination >= vertex || orgin < 0 || destination < 0 ){
			printf("Invalid data!!");
			break;
		}

		matrix[orgin][destination] = 1;
		if(graph_type == 1){
			matrix[destination][orgin] = 1;
		}
	}

	for(int i = 0 ; i < vertex ; i ++){
		visited_vertex[i] = 0;
		//creating an empty array
	}
}

void display(){
	for(int i = 0 ; i < edges ;  i ++ ){
		for(int j = 0 ; j < edges ; j ++ ){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
}


void bfs(int source){
	int queue[MAX];
	int front,rear,root;

	front = rear = 0;
	visited_vertex[source] = 1;
	queue[rear++] = source;
	printf("%d",source);

	while(front != rear){
		root = queue[front];
		for(int i = 1 ; i <= vertex ; i ++){
			if(matrix[root][i] && !visited_vertex[i]){
				visited_vertex[i] = 1;
				queue[rear++] = i;
				printf("%d",i);
			}
		}
		front++;
	}
}
void get_edges(){
	printf("Enter graph type: 1->Undirected 2->directed: ");
	scanf("%d",&graph_type);

	printf("\nEnter vertex: ");
	scanf("%d",&vertex);

	printf("\nEnter the edges : \n");
	scanf("%d",&edges);

	while(edges > 0){
		printf("Enter orgin and destination [-1 , -1 for exit the application]: ");
		scanf("%d %d",&orgin,&destination);

		if(graph_type == 1){
			matrix[orgin][destination] = 1;
			matrix[destination][orgin] = 1;
		}
		if(graph_type == 2){
			matrix[orgin][destination] = 1;
		}
		edges--;
	}
	for(int i = 0 ; i < vertex ; i ++){
		visited_vertex[i] = 0;
		//creating an empty array
	}
}

void main(){
	get_edges();
	display();
	printf("Enter the source : \n");
	scanf("%d",&source);
	bfs(source);
}
