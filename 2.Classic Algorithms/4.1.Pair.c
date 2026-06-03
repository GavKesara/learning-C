//Closest Pair problem - using a much more refined approach to reduce time to calculate min distance
//use -lm to compile


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//data structure to write points easily.
typedef struct point{
    double x;
    double y;
}point;

//function to get the distance between 2 points
double distance(point n1,point n2){
    double dx=n1.x-n2.x;
    double dy=n1.y-n2.y;
    double d=sqrt(pow(dx,2)+pow(dy,2));
    return d;
}

void print_array_p(point array[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d --> (%.2f , %.2f)\n",i,array[i].x,array[i].y);
    }
}

void print_array(double array[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%.2f\t",array[i]);
    }
    printf("\n");
}

void merge_x(point array[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    //create 2 arrays of int to divide
    point*L=(point*)malloc(sizeof(point)*n1);
    point*R=(point*)malloc(sizeof(point)*n2);

    for(i=0;i<n1;i++){
        L[i]=array[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=array[mid+1+j];
    }

    i=0,j=0;
    k=left;

    //inputs into the array in ascending order (x)
    while(i<n1&&j<n2){
        if(L[i].x<=R[j].x){
            array[k]=L[i];
            i++;
        }else{
            array[k]=R[j];
            j++;
        }
        k++;
    }

    //fills the remaining indexes to the arrays
    while(i<n1){
        array[k]=L[i];
        k++,i++;
    }
    while(j<n2){
        array[k]=R[j];
        k++,j++;
    }

    free(L);
    free(R);
}
void merge_sort_x(point array[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        merge_sort_x(array,left,mid);
        merge_sort_x(array,mid+1,right);

        merge_x(array,left,mid,right);
    }
}

void merge_y(point array[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    point*L=(point*)malloc(sizeof(point)*n1);
    point*R=(point*)malloc(sizeof(point)*n2);

    for(i=0;i<n1;i++){
        L[i]=array[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=array[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2){
        if(L[i].y<R[j].y){
            array[k++]=L[i++];
        }else{
            array[k++]=R[j++];
        }
    }

    while(i<n1){
        array[k++]=L[i++];
    }
    while(j<n2){
        array[k++]=R[j++];
    }
    free(L);
    free(R);
}

void merge_sort_y(point array[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        merge_sort_y(array,left,mid);
        merge_sort_y(array,mid+1,right);

        merge_y(array,left,mid,right);
    }
}

double distance_cal(double array_x,point array,int left,int mid,int right){

}

//smalled brute force to find min distance
double brute_force(point array[],int left,int right){
    int i,j;
    double min_d=1e9;//assign min_d a large value comparable to inf
    for(i=left;i<right;i++){
        for(j=i+1;j<=right;j++){
            double d=distance(array[i],array[j]);
            if(d<min_d){
                min_d=d;
            }
        }
    }
    return min_d;
}

double DividePair(point array[],int left,int right){  
    //base case points<3 can be caluclated via brute force method
    if((right-left)<=3){
        return(brute_force(array,left,right));
    }
    int mid=left+(right-left)/2;
    point mid_point=array[mid];

    //conquer: find min distance in left and right halves
    double dL=DividePair(array,left,mid);
    double dR=DividePair(array,mid+1,right);

    double d=(dL < dR) ? dL : dR; //if(dL<dR){d=dL}else{d=dR}

    //when points are too close to the center dividing line
    point*strip=(point*)malloc(sizeof(point)*(right-left+1));
    int strip_size=0;
    int i;
    for(i=left;i<=right;i++){
        if(fabs(array[i].x-mid_point.x)<d){
            strip[strip_size++]=array[i];
        }
    }

    //sort strip by Y coords
    merge_sort_y(strip,0,strip_size-1);
    for(int i=0;i<strip_size;i++){
        for(int j=i+1;j<strip_size;j++){
            double dist=distance(strip[i],strip[j]);
            if(dist<d){
                d=dist;
            }
        }
    }
    free(strip);
    return d;
}

void ClosestPair(point array[],int size){
    point* order_x=(point*)malloc(sizeof(point)*size);

    int i;
    for(i=0;i<size;i++){
        order_x[i]=array[i];
    }

    merge_sort_x(order_x,0,size-1);

    printf("The min distance between the points are :-   %lf",DividePair(order_x,0,size-1));
    free(order_x);
}

//function to coin_flip if a generated point is positive or negative
double is_positive(double n){
    if(rand()%2){
        return -n;
    }
    return n;
}

//function to generate a point between (-10.00 - 10.00)
point generate_point(){
    point n;
    n.x=rand()%1000;
    n.y=rand()%1000;
    n.x=n.x/100;
    n.y=n.y/100;
    n.x=is_positive(n.x);
    n.y=is_positive(n.y);
    return n;
}

void insert_points(point array[],int size){
    int i;
    for(i=0;i<size;i++){
        point n1;
        n1=generate_point();
        array[i]=n1;
    }
}

int main(void){
    int num_of_data=10;
    srand(time(NULL));
    point data_set[num_of_data];
    insert_points(data_set,num_of_data);

    printf("Generated points\n");
    print_array_p(data_set,num_of_data);
    //print_array(data_set,num_of_data);
    ClosestPair(data_set,num_of_data);


    return 0;
}
