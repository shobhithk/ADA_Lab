#include<stdio.h>
#include<stdlib.h>
int bit(int n)
  {
      if(n<=1)
        return 1;
      return 1+bit(n/2);
  }
void main()
{  int i,j,n;
   FILE *fp1,*fp2;
   fp1=fopen("Bit.txt","a");
   fp2=fopen("Bit_count.txt","a");
   for(i=1;i<=1024;i=i*2)
     {
        i;
        j=bit(i);
        
        fprintf(fp2,"%d\t%d\n",i,j);
        fprintf(fp1,"\nNumber of Bits required to reprsent %dare %d\n",i,j);
     }
     fclose(fp1);
     fclose(fp2);
  system("gnuplot -p 'commands.txt'");
}