#include<stdio.h>
#include<stdlib.h>

int count;

int fib(int n)
{
if (n <= 1)
	return n;
	count++;
return fib(n-1) + fib(n-2);
}

int main ()
{
int i,j;
   FILE *ptr1,*ptr2;
   ptr1=fopen("Fib.txt","a");
   ptr2=fopen("Fib_count.txt","a");

  
   for(i=1;i<=20;i++)
     {
        count=0;
        j=fib(i);
        fprintf(ptr1,"\nthe 'i'th fib no is %d\n",j);
        fprintf(ptr2,"%d\t%d\n",i,count);
     }
     fclose(ptr1);
     fclose(ptr2);
     system("gnuplot -p 'commands.txt'");
     
return 0;
}

