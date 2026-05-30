//C code for collatz conjecture -
// Start with a number n > 1. 
//Find the number of steps it takes to reach one using the following process: 
//If n is even, divide it by 2. If n is odd, multiply it by 3 and add 1.

#include<stdio.h>

int collatz(int a){
    if(a%2==0){
        return a/2;
    }else{
        return 3*a+1;
    }
}

int main(void){
    int n;//number
    printf("Enter value of n:-");
    scanf("%d",&n);
    int step=0; //num of steps
    while(n!=1){
        n=collatz(n);
        step++;
    }
    printf("number of steps :--%d",step);
}