/*
 The user enters a cost and then the amount of money given.
 The program will figure out the change and the number of quarters, dimes, nickels, pennies needed for the change.*/

#include<stdio.h>

int main(void){
    int cost,mny_gvn;
    int change;

    printf("Enter the cost of the product:...");
    scanf("%d",&cost);
    printf("\nEnter the amount of money given to machine:...");
    scanf(" %d",&mny_gvn);
    change=mny_gvn-cost;
    int pen=change/(25);
    int nickel=(change-25*pen)/10;
    int dimes=(change-(25*pen+10*nickel))/5;
    int quarters=(change-(25*pen+10*nickel+5*dimes))/1;

    printf("your change is:....\n'%d' pennies\n'%d' nickels\n'%d' dimes\n'%d' quarters\n",pen,nickel,dimes,quarters);
    return 0;


}
