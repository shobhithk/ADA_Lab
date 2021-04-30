#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count = 0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            
        }
        else {
            arr[k] = R[j];
            j++;
           
        }
        k++;
        
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
      
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {      
        int m = l + (r - l) / 2;     
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        
    }   
    }
int main(void)
{
    int *a,i,j,n,min,t;
    FILE *fp1,*fp2;
    system("rm MS_count.txt");
    system("rm MS_value.txt");
    srand(time(NULL));
    for(n=1;n<=10000;n=n*2)
    {
        count=0;
        a = (int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            a[i]=rand()%100;
            mergeSort(a,0,i - 1);
        fp1 = fopen("MS_value.txt","a");
        fprintf(fp1,"\nIteration : ");
        for(i=0;i<n;i++)
            fprintf(fp1,"%d ",a[i]);
        fclose(fp1);

        fp2 = fopen("MS_count.txt","a");
        fprintf(fp1,"%d\t%d\n",n,count);
        fclose(fp2);
    }
}