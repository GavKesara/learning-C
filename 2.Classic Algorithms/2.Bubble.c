//implementing C bubble sort algorithm

#include<stdio.h>

//sawps values of a,b
void swap(int *a,int *b){
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}

void bubble_sort(int ar[],int size){
    int i;
    int j;
    int flag; //flag to check if array is sorted to remove unnessasary sorting attempts
    for(i=0;i<size;i++){
        printf("*\n");
        flag=1;
        for(j=0;j<size;j++){
            if(ar[j]>ar[j+1]){
                swap(&ar[j],&ar[j+1]);
                flag=0;
            }
        }
        if(flag){break;}
    }   
}
//prints array
void print_array(int ar[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",ar[i]);
    }
}

int main(void){
    int array[5]={2,3,5,4,6}; //user enters array to be sorted
    int size=sizeof(array)/sizeof(array[0]);
    printf("Unsorted array\n");
    print_array(array,size);
    printf("\n");
    bubble_sort(array,size);
    printf("Sorted array\n");
    print_array(array,size);
    return 0;   
}