/*
Find Cost of Tile to Cover W x H Floor
Gavesh Diss
*/

#include<stdio.h>

int area_cal(int h,int w){
    return(h*w);
}

int main(void){
    int width,height;
    int price_per_tile;

    printf("Enter Width of the floor:...");
    scanf("%d",&width);
    printf("\nEnter height of the floor:...");
    scanf("%d",&height);
    printf("\nEnter cost of tile per 1sqr of unit:...");
    scanf("%d",&price_per_tile);
    printf("\nTotal cost of tile:...%d cost_units",price_per_tile*area_cal(height,width));

    return 0;

}