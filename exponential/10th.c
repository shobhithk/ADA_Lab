#include<stdio.h>
#include<stdlib.h>


int count;
int expo(int n)
{
    count++;
    if(n==0) return 1;
    return expo(n-1)+expo(n-1) ;        //This returns a complete binary tree of depth equal to d
}



void main(){

int n,i,pow;
FILE *ptr,*ptr1;
	system("rm exp.txt");
	system("rm exp_count.txt");
	ptr=fopen("exp_count.txt","a");
	ptr1=fopen("exp.txt","a");

fprintf(ptr1,"",i);
for(i=0;i<10;i++)
{
    count=0;
    pow=expo(i);
    fprintf(ptr1,"The value of %dth exp is :%d\n",i,pow);                            
    fprintf(ptr,"%d\t%d\n",i,count);
}
fclose(ptr);
fclose(ptr1);
system("gnuplot -p 'commands.txt'");

}