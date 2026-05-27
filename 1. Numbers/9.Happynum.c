/*Happy Numbers - 
A happy number is defined by the following process.
 Starting with any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay), or it loops endlessly 
 in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers, 
 while those that do not end in 1 are unhappy numbers. Display an example of your output here. 
 Find first 8 happy numbers.
 */
#include<stdio.h>
#include<stdlib.h>


//simple power function not necessarily needed however,
int power(int i,int j){
    int count;
    int total=1;
    for(count=1;count<=j;count++){
        total*=i;
    }
    return total;
}

//ideal for 2 digit numbers needs improvement to handle other bigger numbers.
int cal_happy(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=power(digit,2);
        n=n/10;
    }
    return sum;
}

//function to find if a certain number is happy. method used is repetitive detection
//algorithm uses 2 pointers slow and fast
//if the pointers meet the meeting point is checked wheather if it is 1 if it is then its a happy number.
int is_happy(int n){
    int slow=n;
    int fast=n;
    do{
        slow=cal_happy(slow); //moves 1 step
        fast=cal_happy(cal_happy(fast)); //moves 2 steps

        if(fast==1){
            break;
        }
    }while(slow!=fast);
    return (slow==1 || fast==1); //boolean statement 0 or 1
}


int main(void){
    int i;
    int j=1;
    printf("Enter a number to begin generating happy numbers:...");
    scanf("%d",&i); //reading input value i

    printf("\nThe next 8 happy numbers are\n");
    while(j<=8){
        if(is_happy(i)){
            printf(" %d |",i);
            j++; //updates count if a happy number is detected.
        }
        i++;
    }
    printf("\n");
    return 0;
}