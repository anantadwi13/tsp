#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;

typedef struct {
    int from,to,cost;
} edge;

int main(){
    map<int,edge*> graph;
    edge a;
    a.cost = 10;
    a.from = 1;
    a.to = 2;

    graph[0]=&a;
    printf("%d",graph[0]->cost);
}
