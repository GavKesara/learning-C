/*
 find prime numbers until the user chooses to stop asking for the next one.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int gen_odd(int i){
    if(i==1){return 2;}else{
        return 2*i-1;
    }
}

int check_prime(int i){
    int j;
    int count=0;
    int n=gen_odd(i);
    for(j=1;j<n+1;j++){
        if(n%j==0){count++;}
    }
    return(count==2);
}

int main(void){
    int i=1,j;
    int odd_num;
    char boo;
    while(1){
        printf("Generate next prime(Y/N):...");
        scanf(" %c",&boo); //if "%c" is used, program will read enter cmd as No and exit prematurely
        if(tolower(boo)!='y'){
            printf("\nProgram exited successfully.");
            exit(1);
        }else{
            while(!check_prime(i)){
                i++;
            }
            printf("Prime -> %d\n",gen_odd(i));
            i++;
        }
    }
    return 0;
}
