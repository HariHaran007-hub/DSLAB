#include<stdio.h>
#include<conio.h>
#define MAX 100

int graph_matrix[MAX][MAX],queue[MAX],front = 0 , rear = -1;

int n;//no of vertex




void main(){
    int max_edges,source,destination;
    int graphType,v;
    printf("Enter choice \n\t1-> Undirected Graph\n\t2->Directed Graph");
    scanf("%d",&graphType);

    printf("Enter number of vertices: ");
    scanf("%d",&n);
    if(graphType == 1)max_edges = n*(n-1)/2;
    else max_edges = n*(n-1);

    for(int i = 1; i <= max_edges; i++){
        printf("Enter edge [%d] (-1 -1 to quit): ",i);
        scanf("%d%d",&source,&destination);

        if(source == -1 && destination == -1){break;}

        else if(source >=n || destination >= n || source < 0 || destination < 0){
            printf("Invalide data to construct graph!!");}

        else{
            graph_matrix[source][destination] = 1;
            if (graphType == 1)
            {
                graph_matrix[destination][source] = 1;
            }

        }
    }


    for (int i = 0; i <=n-1; i++)
    {
        for (int j = 0; j<= n-1; j++)
        {
            printf("%d ",graph_matrix[i][j]);
        }
        printf("\n");

    }

}

