/*
Prime Factorization - Have the user enter a number and find all Prime Factors (if there are any) and display them.
*/

#include<stdio.h>
#include<stdlib.h>

//cleans array by initailising garbage values to 0;
void clean_array(int array[],int n){
    int i;
    for(i=0;i<n;i++){
        array[i]=0;
    }
}

//prints data array
void print_array(int array[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t%d\n",i,array[i]);
    }
}
//factor array- works as intended
void factor_array(int array[],int n){
    int i;
    for(i=1;i<n;i++){
        if((n-1)%i==0){
            array[i]=1;
        }
    }
}

//finds prime factors from factors array
void prime_array(int array[],int n){
    int i,j,count;
    for(i=1;i<n;i++){
        if(array[i]==1){
            count=0;
            for(j=1;j<i+1;j++){
                if(i%j==0){
                    count++;
                }

            }
            if(count!=2){
                array[i]=0;
            }
        }
    }
}

void print_primes(int array[],int n){
    int i;
    for(i=1;i<n;i++){
        if(array[i]==1){
            printf("%d, ",i);
        }
    }
}

int main(void){
    int n;
    printf("Enter number to find prime factors:...");
    scanf("%d",&n);
    int factor_flag[n+1];
    clean_array(factor_flag,n+1);

    factor_array(factor_flag,n+1);
    //print_array(factor_flag,n+1);

    prime_array(factor_flag,n+1);
    printf("The Prime factors for the number %d are: ",n);
    print_primes(factor_flag,n+1);
    return 0;
}
