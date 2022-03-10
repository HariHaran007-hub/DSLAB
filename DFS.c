#include<stdio.h>
#include<conio.h>
#define MAX 10
int matrix[MAX][MAX];
int visited_vertex[MAX];
int vertex,orgin,destination,edges,source;
int graph_type;

void display(){
	for(int i = 0 ; i < edges ;  i ++ ){
		for(int j = 0 ; j < edges ; j ++ ){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
}


void dfs(int source){
	visited_vertex[source] = 1 ;
	printf("%d",source);
	for(int i = 1 ; i<= edges ; i++){
		if(matrix[source][i] && !visited_vertex[i]){
			dfs(i);
		}
	}

}
void get_edges(){
	int e;
	printf("Enter graph type: 1->Undirected 2->directed: ");
	scanf("%d",&graph_type);

	printf("\nEnter vertex: ");
	scanf("%d",&vertex);

	printf("\nEnter the edges : \n");
	scanf("%d",&edges);

	e =  edges;

	while(e > 0){
		printf("Enter orgin and destination [-1 , -1 for exit the application]: ");
		scanf("%d %d",&orgin,&destination);

		if(graph_type == 1){
			matrix[orgin][destination] = 1;
			matrix[destination][orgin] = 1;
		}
		if(graph_type == 2){
			matrix[orgin][destination] = 1;
		}
		e--;
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
	dfs(source);
}

