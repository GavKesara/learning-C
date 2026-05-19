/*Complex Number Algebra*/

#include<stdio.h>
#include<math.h>

typedef struct Co{
    double R;
    double C;
}Complex;

Complex Addition(Complex x,Complex y){ //Complex number addition function
    Complex z;
    z.R=x.R+y.R;
    z.C=x.C+y.C;
    return z;
}

Complex Negation(Complex x){
    Complex z;
    z.R=-x.R;
    z.C=-x.C;
    return z;
}

Complex Substract(Complex x,Complex y){ //Complex number substraction function
    Complex z;
    z=Addition(x,Negation(y));
    return z;
}

Complex Invertion(Complex x){
    Complex z;
    double deno=(round(pow(x.R,2)))+(round(pow(x.C,2)));
    z.R=x.R/(double)deno;
    z.C=-x.C/(double)deno;
    return z;
}

Complex Multiply(Complex x,Complex y){
    Complex z;
    z.R=(x.R*y.R)-(x.C*y.C);
    z.C=(x.C*y.R)+(x.R*y.C);
    return z;
}

Complex Division(Complex x,Complex y){
    Complex z;
    Complex y1=Invertion(y);
    z=Multiply(x,y1);
    return z;
}


int main(void){
    Complex x,y;
    printf("Choose Operation method.....(1-6)");
    printf("\nAddition\t(1)\nSubstraction\t(2)\nMultiplication\t(3)\nDivition\t(4)\nInversion\t(5)\nNegation\t(6)\n");
    int op;
    scanf("%d",&op);
    printf("Enter Complex number(x):--");
    printf("\nX->Real\t\t: ");
    scanf("%lf",&x.R);
    printf("X->Complex\t: ");
    scanf("%lf",&x.C);
    if(op!=5 && op!=6){
        printf("\nEnter Complex number(y):--");
        printf("\nY->Real\t\t: ");
        scanf("%lf",&y.R);
        printf("Y->Complex\t: ");
        scanf("%lf",&y.C);
    }
    printf("\n");
    switch(op){
        case 1:printf("%lf + %lfi",Addition(x,y).R,Addition(x,y).C);break;
        case 2:printf("%lf + %lfi",Substract(x,y).R,Substract(x,y).C);break;
        case 3:printf("%lf + %lfi",Multiply(x,y).R,Multiply(x,y).C);break;
        case 4:printf("%lf + %lfi",Division(x,y).R,Division(x,y).C);break;
        case 5:printf("%lf + %lfi",Invertion(x).R,Invertion(x).C);break;
        case 6:printf("%lf + %lfi",Negation(x).R,Negation(x).C);break;
        default:printf("Enter a Correct operation!");break;
    }
    return 0;
}