#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd(int,int);
void modular(int,int);
void consec(int,int);
void subtract(int,int);
int count=0;

void main() {
int num1,num2;
srand(time(NULL));
num1=rand()%100;
num2=rand()%100;
printf("\nThe two numbers are %d and %d\n\n", num1,num2);


    printf("\t\tnum1\tnum2\tgcd\tcount\n");
    modular(num1,num2);
    consec(num1,num2);
    subtract(num1,num2);


}

void modular(int a, int b) {
    count=0;
    int temp=0,res;
    if(a<b){
        
        temp=a;
        a=b;
        b=temp;
    }
    res= gcd(a,b);
    if(temp!=0) printf("modular\t\t%d\t%d\t%d\t%d\n",b,a,res,count);
    else printf("modular\t\t%d\t%d\t%d\t%d\n",a,b,res,count);
}

int gcd(int m,int n){
    int r;
    while(n!=0)
    {
        count++;
        r=m%n;
        m=n;
        n=r;

    }
    return m;
}

void consec(int a, int b) {
    int t;
    count=0;
    if(a>b) t=b;
    else t=a;
    while(t!=0)
    {   count++;
        if(a%t ==0){
            if(b%t == 0){
            printf("consIntCheck\t%d\t%d\t%d\t%d\n",a,b,t,count);
            break;
            }
        }
         t--;
    }
}

void subtract(int a, int b) {
    count=0;
    int t1=a, t2=b;
    while (a!=b)
    {
        count++;
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    printf("subtract\t%d\t%d\t%d\t%d\n\n",t1,t2,a,count);
    
}