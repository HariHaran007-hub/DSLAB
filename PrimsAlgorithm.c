#include<stdio.h>
#include<conio.h>
int i ,j,u,v,cost[20][20],visited[10],ne=1,n,min,mincost=0;
void main(){
	printf("Enter the number nodes : \n");
	scanf("%d",&n);
	printf("Enter the matrix value : \n");
	for(i=1 ; i<=n ; i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0){
				cost[i][j] = 999;
			}
		}
	}
	for(i=0 ; i<n ; i++)
		visited[i] = 0;

	while(ne < n){

	visited[1] = 1;
	for(i=1,min=999;i<=n;i++){
		for(j=1;j<=n;j++){
			if(cost[i][j]<min){
					if(visited[i] == 0){
						continue;
					}
					else{
						min = cost[i][j];
						u =i ;
						v =j;
					}

			}
			if(visited[u] == 0 || visited[v] == 0){
				printf("%d edges(%d %d) : %d\n",ne++,u,v,min);
				mincost = mincost + min ;
				visited[v] = 1 ;
			}
			cost[u][v] = cost[v][u] = 999;


		}
	}
	printf("Min cost = %d",mincost);
	}
}
