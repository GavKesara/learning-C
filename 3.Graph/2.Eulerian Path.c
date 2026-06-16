/*
 C code to implement a Eurelian path in C
 code taken from ADTgraph.c
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

int main(void){
    int numVertices=4;
    list **Graph=calloc(numVertices,sizeof(list*));
    add_Edge(0,Graph,2);
    add_Edge(0,Graph,3);
    add_Edge(1,Graph,2);
    printf("-----Printing Graph-----\n");
    print_Graph(Graph,numVertices);

    free_graph(Graph,numVertices);
    free(Graph);
    return 0;
}