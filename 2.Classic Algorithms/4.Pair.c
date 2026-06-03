//Closet Pair problem(2D) - Brute force - not suitable for larger arrays such as with 1000 points
//you have to find the 2 points which are closed to each other.
// use -lm flag when compiling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to find the distance between 2 points
double distance(double n1[],double n2[]){
    double dx=n1[0]-n2[0];
    double dy=n1[1]-n2[1];
    double d2=pow(dx,2)+pow(dy,2);
    double d=sqrt((double)d2);
    return d;
}

int main(void){
    // 2 points next to each other.
    double pA[2] = {3.5, -7.2};
    double pB[2] = {-8.1, 4.3};
    double pC[2] = {0.2, 9.1};
    double pD[2] = {-5.0, -2.8};
    double pE[2] = {7.6, 1.5};
    double pF[2] = {-2.3, -6.4};
    double pG[2] = {6.0, 8.7};
    double pH[2] = {-9.4, -9.1};
    double pI[2] = {1.1, -0.5};
    double pJ[2] = {-4.7, 5.9};

    //pointer array containing the points
    double* data_set[10]={pA,pB,pC,pD,pE,pF,pG,pH,pI,pJ};
    int size=10;

    
    int i,j;
    double min_d=distance(data_set[0],data_set[1]);//initial distance value

    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            double cur_d=distance(data_set[i],data_set[j]);
            if(cur_d<min_d){
                min_d=cur_d;
                printf("%d %d\n",i,j);
            }
        }
    }
    printf("Min distance :- %lf",min_d);
    return 0;

}