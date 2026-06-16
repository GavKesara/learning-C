/*
 C code to implement a Eurelian path in C
 code taken from ADTgraph.c
*/

/* test case 01 -
    add_Edge(0, Graph, 1);
    add_Edge(1, Graph, 2);
    add_Edge(2, Graph, 3);
    add_Edge(3, Graph, 0);

    output -> fully connected, contains Eulerian cycle
    
    test case 02 - 
    add_Edge(0, Graph, 2);
    add_Edge(1, Graph, 2);
    add_Edge(3, Graph, 0);
    
    output -> fully connected, contains Eulerian path
    
    test case 03 -
    add_Edge(0, Graph, 1);
    add_Edge(2, Graph, 3);
    
    output -> split to seperate components
    
    test case 04 -
    add_Edge(0, Graph, 1);
    add_Edge(1, Graph, 2);
    add_Edge(2, Graph, 0);
    
    output ->  fully connected, contains an Eulerian cycle
    
    test case 05 -
    add_Edge(0, Graph, 1);
    add_Edge(0, Graph, 2);
    add_Edge(0, Graph, 3);
    
    output -> fully connected, doesnt contain an Eulerian path
    */

#include<stdio.h>
#include<stdlib.h>



typedef struct list{
    int d;
    struct list *next;
}list;


//function to create a list structure
list *create_list(int data){
    list *head=malloc(sizeof(list));//create a list struct
    head->d=data;//assigns value in list to data;
    head->next=NULL;
    return head; //returns pointer to head struct
}

list *Enter_to_list(int data,list *next){
    list *head=create_list(data);//create a list struct with data in list->d
    head->next=next;
    return head; //returns pointer to head struct
}

void add_Edge(int vertice,list* Array[],int n){
    Array[vertice]=Enter_to_list(n,Array[vertice]); //adds the data to the needed 
    Array[n]=Enter_to_list(vertice,Array[n]); //reverse add so the verices are connected.
}

//function to print a list
void print_list(list *head){
    while(head!=NULL){
        printf(" %d,",head->d);
        head=head->next; //transition from one list structure to the next one
    }
}

//function to print individual lists in a data array
void print_Graph(list* Array[],int size){
    for(int i=0;i<size;i++){
        printf("%d -> ",i);
        if(Array[i]==NULL){
            printf("\n");
            continue;
        }
        print_list(Array[i]);
        printf("\n");
    }
}

//function to free allocated memory to list structure
void free_list(list *head){
    list *temp;
    while(head!=NULL){
        temp=head; //assigns head address to temp
        head=head->next;
        free(temp); //frees memory in head list struct
    }
}

//function to free allocated memory of the data addresses in the Graph Array
void free_graph(list *Array[],int size){
    for(int i=0;i<size;i++){
        free_list(Array[i]); //frees memory in a list in one array index
    }
}

//counts the number of elements in a list structure
int count_list(list *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

//counts the vertices with odd degrees
int count_odd(int Array[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(Array[i]%2!=0){
            count++;
        }
    }
    return count;
}

//auxillary function to print an array
void print_array(int Array[],int size){
    for(int i=0;i<size;i++){
        printf("%d, ",Array[i]);
    }
    printf("\n");
}

//Eulerian path rule 2 code
void Eulerian_R2(int num){
    printf("Result :- ");
    switch(num){
        case 0:printf("Contains an Eulerian cycle.");break;
        case 2:printf("Contains an Eulerian path.");break;
        default:printf("doesn't contain an Eulerian path");break;
    }
    printf("\n");
}

//function for Depth-First Search
void DFS(int vertex,int visited[],list *Array[]){
    visited[vertex]=1;
    list* temp=Array[vertex];
    while(temp!=0){
        int neighbor=temp->d;

        if(!visited[neighbor]){
            DFS(neighbor,visited,Array);
        }

        temp=temp->next;
    }
}

//function to check if the vertices are connected or if they contain individual cycles
int is_connected(list *Array[],int size){
    int *visited=calloc(size,sizeof(int)); //creates a int array and has its values to 0.
    if(visited==NULL){
        printf("Error allocating memory.");
        return 1;
    }

    int start_vertex=-1; //start vertex flag
    for(int i=0;i<size;i++){
        if(Array[i]!=NULL){
            start_vertex=i; 
            break;
        }
    }
    if(start_vertex==-1){
        free(visited);
        return 1;
    }
    DFS(start_vertex,visited,Array);

    for(int i=0;i<size;i++){
        if(Array[i]!=NULL && visited[i]==0){
            free(visited);
            return 0; //return false disconnected
        }
    }

    free(visited);
    return 1; //return true connected
}

//Eulerian function for singly linked network
void Eulerian(list* Array[],int size){
    int *degree=malloc(sizeof(int)*size); // array to include degree of the graph
    if(degree==NULL){
        printf("Error allocating memnory!");
        return;
    }
    for(int i=0;i<size;i++){
        degree[i]=count_list(Array[i]); //reads the degree of the path components to the array
        }
    int odd_count=count_odd(degree,size);
    Eulerian_R2(odd_count);
    free(degree);
}

int main(void){
    int numVertices=4;

    list **Graph=calloc(numVertices,sizeof(list*));
    if(Graph==NULL){
        printf("Failed to allocate graph wrapper!\n");
        return EXIT_FAILURE;
    }
    add_Edge(0, Graph, 1);
    add_Edge(0, Graph, 2);
    add_Edge(0, Graph, 3);    
    printf("-----Printing Graph-----\n");
    print_Graph(Graph,numVertices);

    if(is_connected(Graph,numVertices)){
        printf("The Graph is fully connected.\n");
        printf("---Eulerian Path Status------\n");
        Eulerian(Graph,numVertices);
    }else{
        printf("The graph is split into seperate components.\n");
        printf("Graph cannot contain an Eulerian Path.");
    }

    free_graph(Graph,numVertices);
    free(Graph);
    return 0;
}