/*
 Develop a converter to convert a decimal number to binary or a binary number to its decimal equivalent.    
*/
#include <stdio.h>
#include <math.h> //include math library flag when compiling use -lm

int bintodec(int bin){
    int i=0;
    int decimal=0;
    double t;
    int temp=bin;
    while(temp>0){
        int last_dig=temp%10;
        decimal+=last_dig*round(pow(2,i));
        i+=1;
        temp=temp/10;
    }
    return decimal;
}

int dectobin(int dec){
    int temp=dec;
    int bin=0;
    int i=0;
    while(temp!=0){
        int remainder=temp%2;
        bin+=remainder*(int)round(pow(10,i));
        temp=temp/2;
        i++;
    }
    return bin;

}

int main(void){
    int flag;
    int num;
    printf("Press 0 if Bin to Dec:.\n");
    printf("Press 1 if Dec to Bin:.\n");
    scanf("%d",&flag);

    printf("Enter Number to convert:...");
    scanf("%d",&num);

    if(flag){
        printf("%d decimal converted to binary is %d",num,dectobin(num));
    }else{
        printf("%d integer converted to decimal is %d",num,bintodec(num));
    }
    return 0;
}
