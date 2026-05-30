//C code to get power in time o(log(n))

#include<stdio.h>

int power(int b,int a){
    int result=1;
    while(a>0){
        //if the current bit is 1,multiply result by the current base
        if(a%2==1){
            result*=b;
        }
        //square the base for the next bit position
        b*=b;
        //shift exponent to the right(divide by 2)
        a/=2;
    }
    return result;
}

int main(void){
    int base;
    int exponent;
    printf("Enter base value:...");
    scanf("%d",&base);
    printf("Enter exponent value:...");
    scanf("%d",&exponent);
    printf("%d",power(base,exponent));
    return 0;
}