#include<stdio.h>
#include<string.h>
#define INF 99999999

int main(){
    int vertex, cost;
    printf("Jumlah Vertex : ");
    scanf("%d",&vertex);

    int graph[vertex][vertex];
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            if(i==j)
                graph[i][j]=INF;
            else if(i<j){
                printf("Cost Edge %d -> %d : ",i,j);
                scanf("%d",&cost);
                graph[i][j]=cost;
                graph[j][i]=cost;
            }
        }
        printf("\n");
    }

    //START OF PRIMS
    int MST[vertex][vertex];
    int vertexNow = 0;
    int isTraversed[vertex];
    int primFrom[vertex];
    int primCost[vertex];
    int minCost, minVertex;
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++)
            MST[i][j]=INF;
        isTraversed[i]=0;
        primCost[i]=INF;
        primFrom[i]=INF;
    }

    for(int i=0;i<vertex;i++){
        isTraversed[vertexNow] = 1;
        minCost = INF;
        minVertex = INF;
        for(int j=0;j<vertex;j++){
            if(graph[vertexNow][j]!=INF && !isTraversed[j]){
                if(graph[vertexNow][j]<minCost){
                    minCost = graph[vertexNow][j];
                    minVertex = j;
                }
                if(graph[vertexNow][j]<primCost[j]){
                    primCost[j] = graph[vertexNow][j];
                    primFrom[j] = vertexNow;
                }
            }
        }
        vertexNow = minVertex;
    }

    for(int i=1;i<vertex;i++){
        MST[primFrom[i]][i] = primCost[i];
        MST[i][primFrom[i]] = primCost[i];
    }
    //END OF PRIMS

    //START CHECKING MST
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%8d ",MST[i][j]);
        }
        printf("\n");
    }
    //END CHECKING MST
}
