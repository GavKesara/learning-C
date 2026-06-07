//Sieve of Eratosthenes code to find primes under 10mil

#include<stdio.h>
#include<stdlib.h>

//function to create the ground to deploy the algorithm
int *create_sieves(int size){
    int *is_prime=malloc(size*sizeof(int));
    if(is_prime==NULL){
        printf("Error. Program terminated.");
        exit(1);//exit with error
    }
    int i;
    //sets starting value to TRUE
    for(i=0;i<size;i++){
        is_prime[i]=1;
    }

    //0,1 and not prime numbers so the values are set to FALSE
    if(size>0){is_prime[0]=0;}
    if(size>1){is_prime[1]=0;}

    return is_prime; //returns generated array {1,1,1,1,1,...}

}

//prints primes if the value is TRUE(1)
void print_primes(int array[],int size){
    int i;
    for(i=0;i<size;i++){
        if(array[i]==1){
            printf("%d\n",i,array[i]);
        }
    }
}

//function to filter primes
void filter_primes(int is_prime[],int size){
    int i,j,k;
    for(i=2;i*i<size;i++){//starting number is chosen
        if(is_prime[i]==1){
            for(j=i*i;j<size;j+=i){//assigns 0 to all multiples of the number i.
                is_prime[j]=0;
            }
        }
    }
}

int main(void){
    int ar_length=1000000;
    int array[ar_length];
    int* is_prime=create_sieves(ar_length);

    filter_primes(is_prime,ar_length);
    print_primes(is_prime,ar_length);

    free(is_prime);//frees allocated memory
    return 0;
    
}