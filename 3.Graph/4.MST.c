/*
Program for Minimum spanning tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int vertex,edge,weight;
}data;

typedef struct list{
    int vertex;
    int edge;
    int weight;
    struct list *next;
}list;

typedef struct{
    int *parent;
    int *rank;
}DisjointSet;

list *create_list(int vertex,int weight){
    list *head=malloc(sizeof(list));
    
    head->vertex=vertex;
    head->weight=weight;
    head->next=NULL;
    return head;
}

list *Enter_to_list(int vertex,int weight,list *next){
    list *head=create_list(vertex,weight);
    head->next=next;
    return head;
}

void addEdge(int vertex,int edge,int weight,list *Array[]){
    Array[vertex]=Enter_to_list(edge,weight,Array[vertex]);
    Array[edge]=Enter_to_list(vertex,weight,Array[edge]);
}

void data_to_graph(list *Array[],data graphdata[],int numEdges){
    for(int i=0;i<numEdges;i++){
        addEdge(graphdata[i].vertex,graphdata[i].edge,graphdata[i].weight,Array);
    }
}

void print_list(list *head){
    while(head!=NULL){
        printf("%d (%d) | ",head->vertex,head->weight);
        head=head->next;
    }
    printf("\n");
}

void print_graph(list *Array[],int numVertices){
    printf("----Graph Data----\n");
    printf("Vertex\t->\tEdge\n");
    for(int i=0;i<numVertices;i++){
        printf("%d\t->\t",i);
        print_list(Array[i]);
    }

}

void free_list(list *head){
    list *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

void free_graph(list *Array[],int numVertices){
    for(int i=0;i<numVertices;i++){
        free_list(Array[i]);
    }
}

void swap(data *a,data *b){
    data temp=*a;
    *a=*b;
    *b=temp;
}

void sort_graph_data(data graph[],int numEdges){
    int min;
    for(int i=0;i<numEdges;i++){
        for(int j=0;j<numEdges-i-1;j++){
            if(graph[j].weight>graph[j+1].weight){
                swap(&graph[j],&graph[j+1]);
            }
        }
    }
}

void print_graph_data(data graph[],int numEdges){
    printf("----Graph data----\n");
    for(int i=0;i<numEdges;i++)
        printf("%d <-> %d (%d)\n",graph[i].vertex,graph[i].edge,graph[i].weight);
    printf("\n");
}

DisjointSet *create_set(int V){
    DisjointSet *set=malloc(sizeof(DisjointSet));
    set->parent=malloc(sizeof(int)*V);
    set->rank=calloc(V,sizeof(int));
    for(int i=0;i<V;i++){
        set->parent[i]=i;
        set->rank[i]=1;
    }
    return set;
}

int find_set(DisjointSet *set,int i){
    if(set->parent[i]==i){
        return i;
    }
    return set->parent[i]=find_set(set,set->parent[i]);
}

void union_sets(DisjointSet *set,int i,int j){
    int root_i=find_set(set,i);
    int root_j=find_set(set,j);
    if(root_i!=root_j){
        if(set->rank[root_i]<set->rank[root_j]){
            set->parent[root_i]=root_j;
        }else if(set->rank[root_i]>set->rank[root_j]){
            set->parent[root_j]=root_i;
        }else{
            set->parent[root_j]=root_i;
            set->rank[root_i]++;
        }
    }
}

void free_set(DisjointSet *set){
    free(set->parent);
    free(set->rank);
    free(set);
}

void kruskals_mst(data graphdata[],int numVertices,int numEdges,list *Array[]){
    sort_graph_data(graphdata,numEdges);
    DisjointSet *set=create_set(numVertices);

    printf("\n----Edges in the Constructed MST---\n");
    int mst_weight=0;
    int edges_counted=0;

    for(int i=0;i<numEdges;i++){
        if(edges_counted==numVertices-1){
            break;
        }
        int u=graphdata[i].vertex;
        int v=graphdata[i].edge;
        int weight=graphdata[i].weight;

        int root_u=find_set(set,u);
        int root_v=find_set(set,v);

        if(root_u!=root_v){
            printf("%d <-> %d (Weight: %d)",u,v,weight);
            addEdge(u,v,weight,Array);
            mst_weight+=weight;
            edges_counted++;

            union_sets(set,root_u,root_v);
        }
    }
    printf("\nTotal Weight of MST : %d\n",mst_weight);
    free_set(set);
}

int main(void){
    FILE *file=fopen("graph_mst.txt","r");
    if(file==NULL){
        printf("Error, File not found!.");
        return 1;
    }
    int numVertices,numEdges;
    fscanf(file,"%d %d\n",&numVertices,&numEdges);

    data *graphdata=malloc(sizeof(data)*numEdges);
    for(int i=0;i<numEdges;i++){
        fscanf(file,"%d %d %d\n",&graphdata[i].vertex,&graphdata[i].edge,&graphdata[i].weight);
    }
    fclose(file); //closes data steam.

    list **Graph=calloc(numVertices,sizeof(list*));
    if(Graph==NULL){
        printf("Error allocating memory.");
        return 1;
    }
    kruskals_mst(graphdata,numVertices,numEdges,Graph);
    //print_graph_data(graphdata,numEdges);
    //sort_graph_data(graphdata,numEdges);

    //print_graph_data(graphdata,numEdges);


    //data_to_graph(Graph,graphdata,numEdges);

    print_graph(Graph,numVertices);


    free(graphdata);
    free_graph(Graph,numVertices);
    free(Graph);
    return 0;

}