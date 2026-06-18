/*
    Dijkstras shortest path algorithm implementation using C

    */


#include<stdio.h>
#include<stdlib.h>
#include<limits.h> //Needed for INT_MAX (substiture number for inf)

//Edge struct to read in data from txt file
typedef struct{
    int u,v,dis;
}Edge;

//stucture to contain data of an individual vertex
typedef struct list{
    int Edge;
    int dis;
    struct list *next;
}list;

//create a list struct
list *create_list(int edge,int d){
    list *head=malloc(sizeof(list));
    head->Edge=edge;
    head->dis=d;
    head->next=NULL;
    return head;
}

//add a new list struct and link it to the old one
list *Add_to_list(int edge,int d,list *next){
    list *head=create_list(edge,d);
    head->next=next;
    return head;
}

//add an edge to the graph.
void add_Edge(int vertex,int distance,list *Array[],int edge){
    Array[edge]=Add_to_list(vertex,distance,Array[edge]);
    Array[vertex]=Add_to_list(edge,distance,Array[vertex]);
}

//auxillary function for printing list data
void print_list(list *head){
    while(head!=NULL){
        printf(" %d ( %d ) ,",head->Edge,head->dis);
        head=head->next;
    }
}

//auxillary function for printing a graph
void print_Graph(list* Array[],int size){
    printf("---Graph data---\n");
    for(int i=0;i<size;i++){
        printf("%d ->",i);
        if(Array[i]==NULL){
            printf("\n");
            continue;
        }
        print_list(Array[i]);
        printf("\n");
    }
}

void free_list(list* head){
    list* temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

void free_graph(list *Array[],int size){
    for(int i=0;i<size;i++){
        free_list(Array[i]);
    }
}

int get_min_d(int dist[],int visited[],int numVertices){
    int min=INT_MAX,min_index=-1;

    for(int v=0;v<numVertices;v++){
        if(visited[v]==0 && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }

    return min_index;
}

void dijkstra(list *Array[],int numVertices,int source){
    int *dist=malloc(sizeof(int)*numVertices); //create array to include min distance from one vertex to others
    int *visited=calloc(numVertices,sizeof(int)); //an array that tracks is a certain vertex is visited or not

    for(int i=0;i<numVertices;i++){
        dist[i]=INT_MAX; //initial distance is set to a very high value in this case INT_MAX (infinity)
    }

    dist[source]=0; //distance to source is set to 0

    for(int count=0;count<numVertices;count++){
        int u=get_min_d(dist,visited,numVertices); 

        if(u==-1){
            break;
        }

        visited[u]=1; //sets flag to positive

        list *temp=Array[u];
        while(temp!=NULL){ //checks the distance in the edges in a single vertex
            int v=temp->Edge;
            int distance=temp->dis;

            if(!visited[v] && dist[u]!=INT_MAX && dist[u]+distance<dist[v]){
                dist[v]=dist[u]+distance;
            }
            temp=temp->next;
        }
    }

    printf("Djikstra's Shortest Path from %d\n",source);
    for(int i=0;i<numVertices;i++){
        if(dist[i]==INT_MAX){
            printf("%d is not Reachable.\n",i);
        }else{
            printf("from %d to %d -> %d \n",source,i,dist[i]);
        }
    }
    free(dist);
    free(visited);
}

int main(void){
    FILE *file=fopen("graph_dij.txt","r");
    if(file==NULL){
        printf("Unable to find file.");
        return 1;
    }
    int numVertices,numEdges;
    fscanf(file,"%d %d\n",&numVertices,&numEdges);
    Edge* graph_data=calloc(numEdges,sizeof(Edge));
    for(int i=0;i<numEdges;i++){
        fscanf(file,"%d %d %d\n",&graph_data[i].u,&graph_data[i].v,&graph_data[i].dis);
    }
    fclose(file);

    list **Graph=calloc(numVertices,sizeof(list));
    for(int i=0;i<numEdges;i++){
        add_Edge(graph_data[i].u,graph_data[i].dis,Graph,graph_data[i].v);
    }

    print_Graph(Graph,numVertices);

    printf("Enter starting node from (1 - %d) : -",numVertices);
    int source;
    scanf("%d",&source);
    printf("\n");

    dijkstra(Graph,numVertices,source);

    free(graph_data);
    free_graph(Graph,numVertices);
    free(Graph);
    return 0;
}