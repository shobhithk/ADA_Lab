#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(void)
{
    int *a,i,j,n,min,t,count=0;
    FILE *fp1,*fp2;
    system("rm selection_sort.txt");
    system("rm selection_sort_count.txt");
    srand(time(NULL));
    for(n=10;n<=150;n+=10)
    {
        count=0;
        a = (int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            a[i]=rand()%100;
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                count+=1;
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }

        fp1 = fopen("selection_sort.txt","a");
        fprintf(fp1,"\nIteration : ");
        for(i=0;i<n;i++)
            fprintf(fp1,"%d ",a[i]);
        fclose(fp1);

        fp2 = fopen("selection_sort_count.txt","a");
        fprintf(fp1,"%d\t%d\n",n,count);
        fclose(fp2);
    }
    system("gnuplot -p 'commands.txt'");
}