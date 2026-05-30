//C program that flips a coin and generated probability

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int flip_coin(){
    int a=rand();
    int b=a%2; //wraps random number to 2 possible outcomes
    return b;
}

int main(void){
    int count;
    printf("Enter how many times to flip coins:......");
    scanf("%d",&count);
    //seeding random num generator
    srand(time(NULL));
    int heads=0;
    int tails=0;
    int p_count=count;
    printf("P_heads | P_tails\n");
    while(p_count!=0){
        int coin;
        coin=flip_coin();
        if(coin){
            heads++;
        }else{tails++;}
        p_count--;
    }
    printf("%.2f%%\t| %.2f%%\n",(double)heads/count*100,(double)tails/count*100);
    return 0;

}