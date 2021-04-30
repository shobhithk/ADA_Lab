#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10


int count=0;


void smallest(int *a,int n, int small)
{
    if(n<0)
        return;
    else {
        count++;
        if(*a<small){
            small=*a;
        }
            
        return smallest(++a,--n,small);
    }
}



void main()
{
	int i,n=10;
    int *a;
    
    srand(time(NULL));

	FILE *ptr,*ptr1;
	system("del mArray.txt");
	system("del mArray_count.txt");
	ptr=fopen("mArray_count.txt","a");
	ptr1=fopen("mArray.txt","a");
	
    fprintf(ptr1,"The array elements are \n");
    for(n=x;n<=y;n+=incre)
    {
        a=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
	        {
		    count=0;
            a[i]= rand()%100;
		    fprintf(ptr1,"%d ",a[i]);
		    smallest(a,n-1,a[0]);
		    fprintf(ptr,"%d\t%d\n",n,count);
		
	        }
    }

	
	fclose(ptr);
	fclose(ptr1);
	system("gnuplot -p 'commands.txt'");
}