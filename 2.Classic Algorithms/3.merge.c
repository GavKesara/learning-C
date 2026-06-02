//Implementation of merge sort- faster sorting algorithm compared to bubble sort

#include<stdio.h>
#include<stdlib.h>

void print_array(int array[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
    printf("\n");
}
//merges two sorted subarrays into a single sorted section
void merge(int array[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1; //size of left array
    int n2=right-mid; //size of right array

    //create temp arrays L and R
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));

    //copy data to temp arrays L and R
    for(i=0;i<n1;i++){
        L[i]=array[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=array[mid+1+j];
    }

    //merge the temp arrays back to main array
    i=0;// initial index of first sub array
    j=0;//initial index of second sub array
    k=left;// initial index of merged array

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }else{
            array[k]=R[j];
            j++;
        }
        k++;
    }

    //copies remaining elements in array L,if left
    while(i<n1){
        array[k]=L[i];
        i++;
        k++;
    }
    //copies remaining elements in array R,if left
    while(j<n2){
        array[k]=R[j];
        j++;
        k++;
    }
    //frees temp arrays created
    free(L);
    free(R);
}

void merge_sort(int array[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        merge_sort(array,left,mid);
        merge_sort(array,mid+1,right);

        merge(array,left,mid,right);
    }
}


int main(void){
    int array[20]={3,1,2,3,5,2,3,1,2,3,4,2,3,1,2,3,4,2,3,15};
    int size=sizeof(array)/sizeof(array[0]);

    if(size==1){
        printf("Sorted!\n");
        print_array(array,size);
        exit(0); //exit with success
    }
    merge_sort(array,0,size-1);
    printf("Sorted\n");
    print_array(array,size);
    return 0;
}