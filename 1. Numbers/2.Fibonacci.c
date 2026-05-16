/*
Generates the Fibonacci sequence to the Nth number.
*/

#include<stdio.h>
#include<stdlib.h>

//fibonacci Sequence generator
//uses recursion
int Fib(int n){
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }else{
        return(Fib(n-1)+Fib(n-2));
    }
}

void Fib_printer(int n){
    int i;
    for(i=1;i<n+1;++i){
        printf("%d\t-\t%d\n",i,Fib(i));
    }
}

int main(void){
    int n;
    printf("Enter number to calculate:...");
    scanf("%d",&n);
    printf("\n\nNumber\tFibonacci Number\n");
    Fib_printer(n);


    return 0;
}
