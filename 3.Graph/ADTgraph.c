/*
C code to implement a graph data structure in C 
a data stucture which contains a list structure in an array.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct basic_list{
    int data;
    struct basic_list *next;
}list;

//creates a list struct
list *create_list(int data){
    list *head=malloc(sizeof(list)); //creates a list pointer
    if(head==NULL){
        printf("Error allocating memory.");
        exit(EXIT_FAILURE);
    } 
    head->data=data;
    head->next=NULL; //assigns null pointer to next
    return head;
}

//function to push new value to old list
list *Enter_to_list(int data,list *next){
    list *head=create_list(data);
    head->next=next; //assigns next value to next
    return head;
}

void print_list(list *head){
    while(head!=NULL){
        printf("%d, ",head->data);
        head=head->next;
    }
}

void free_mem(list *h){
    list *temp;
    while(h!=0){
        temp=h;
        h=h->next;
        free(temp);
    }
}

void addEdge(int n,list *Array[],int data){
    Array[n]=Enter_to_list(data,Array[n]); //Enters data to Vertice contained in Array list.
}

void free_memory(list *Array[],int size){
    for(int i=0;i<size;i++){
        free_mem(Array[i]); //frees memory stored in a array index
    }
}


int main(void){
    int numVertices=5;
    list **Graph=calloc(numVertices,sizeof(list*)); //double pointer (list**) for dynamic array of pointers
    addEdge(0,Graph,7);                            //calloc instead of malloc because of array init
    addEdge(0,Graph,14);
    addEdge(1,Graph,18);
    addEdge(0,Graph,21);
    addEdge(1,Graph,10);
    addEdge(3,Graph,10);

    int i;
    printf("-----Printing Graph----\n");
    for(i=0;i<numVertices;i++){
        printf("%d -> ",i);
        if(Graph[i]==NULL){ //early exit incase of NULL pointer.
            printf("\n");
            continue;
        }
        print_list(Graph[i]);
        printf("\n");
    }
    free_memory(Graph,numVertices);
    free(Graph); //frees memory dedicated to Graph list array

    return 0;
}