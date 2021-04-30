#include<stdio.h>
#include<stdlib.h>

int count=0;


void towerOfHanoi(int n,char src, char temp, char dest,FILE* ptr1 ) {
	if(n==0) return ;
	count++;
	towerOfHanoi(n-1, src, dest, temp, ptr1 );
	fprintf(ptr1,"move %d from %c to %c\n",n,src,dest);
	towerOfHanoi(n-1, temp, src, dest, ptr1 );
}



void main()
{
	int i;
	FILE *ptr,*ptr1;
	system("rm TOH.txt");
	system("rm TOH_count.txt");
	ptr=fopen("TOH_count.txt","a");
	ptr1=fopen("TOH.txt","a");
	
	for(i=0;i<=15;i++)
	{
		count=0;
		fprintf(ptr1,"for number of discs =%d\n",i);
		towerOfHanoi(i,'A','B','C',ptr1);
		fprintf(ptr,"%d\t%d\n",i,count);
		fprintf(ptr1,"\n\n");
	}
	
	fclose(ptr);
	fclose(ptr1);
	system("gnuplot -p 'commands.txt'");
}