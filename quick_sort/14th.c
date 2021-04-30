#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 1
#define y 2048

int count;


void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

int partition (int a[], int low, int high, int q)
{
    int pivot,i,j;
    if(q==1){
        pivot= ((low+high)/2)+1;
    }
    else
        pivot = low;  
 
    i = low;  
    j = high;
                   
    while(i<j)
    {
        count++;
       
        while(a[i]<= a[pivot] && i<high){
            i++;
            count++;
        }
            
        while(a[j]>a[pivot]){
            j--;
            count++;
        }
            
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[j],&a[pivot]);
    return (j);
}


void quickSort(int a[], int low, int high, int q)
{
    if (low < high)
    { 
       int pi = partition(a, low, high, q);

        quickSort(a, low, pi - 1, q);  
        quickSort(a, pi + 1, high, q); 
    }
}


void QS(int q,FILE *fp1,FILE *fp2){

	int n,i,j;
	int *a;

	for(n=x;n<=y;n=n*2)
	{

		a=(int*)malloc(n*sizeof(int));

		if(q==2){
			for(i=0;i<n;i++)
			{
				a[i]=rand()%100;
			}
		}

		else{
			for(i=0;i<n;i++)
			{
				a[i]=i+2;
			}
		}

		count=0;
		quickSort(a,0,n-1,q);

		fprintf(fp1,"iteration	");
		for(i=0;i<n;i++)
		{
			fprintf(fp1,"%d ",a[i]);
		}
		fprintf(fp1,"\n\n");
		
		
		fprintf(fp2,"%d\t",n);
		fprintf(fp2,"%d\t\n",count);
		
	}
}

void main()
{
	int choice;
	FILE *fp1,*fp2;
	int run=1;
	system("del QS_B.txt");
	system("del QS_A.txt");
	system("del QS_W.txt");
	system("del QS_B_count.txt");
	system("del QS_A_count.txt");
	system("del QS_W_count.txt");
	srand(time(NULL));
	while(run){
		printf("\n1.best case\n2.average case\n3.worst case\n4.exit\nEnter the choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: fp1=fopen("QS_B.txt","a");
					fp2=fopen("QS_B_count.txt","a");
					QS(choice,fp1,fp2);
					fclose(fp1);
					fclose(fp2);
					break;
			case 2: fp1=fopen("QS_A.txt","a");
					fp2=fopen("QS_A_count.txt","a");
					QS(choice,fp1,fp2);
					fclose(fp1);
					fclose(fp2);
					break;
			case 3: fp1=fopen("QS_W.txt","a");
					fp2=fopen("QS_W_count.txt","a");
					QS(choice,fp1,fp2);
					fclose(fp1);
					fclose(fp2);
					break;
			case 4: run=0;break;
			
		   default: printf("Invalid input choose again\n");
					break;
		}
	}
system("gnuplot -p 'commands.txt'");
}

