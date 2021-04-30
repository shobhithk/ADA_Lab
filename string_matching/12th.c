#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define incre 10

void string(int q,FILE *fp1,FILE *fp2,int count){

	int n,k=0,i,found=0;
    char pattern[1];
	char *text;

	for(n=x;n<=y;n+=incre)
	{

		text=(char*)malloc(n*sizeof(char));
		if(q==1 || q==3){
			for(i=0;i<n;i++) {
            	text[i]='0';
        	}
			
		}
		if(q==2) {
			for (i = 0; i < n/2; i++)
			{
				text[i]='0';
			}
			for(i=n/2;i<n;i++) {
				text[i]='1';
			}
			
		}
        
        if(q==1){
            pattern[0]='0';
            
           
        }
        if(q==3 || q==2){
            pattern[0]='1';
            
           
        }
	
        while(k<=n-1) {
		    int j=0; 
			
		    while(j<1 && text[k+j]==pattern[j])
		    {
			    j=j+1;
				
	        }
            
		if (j == 1)
		{   
			fprintf(fp1,"Pattern found at index %d \n", k);
			break;
			}
		else
	  	{
	  		fprintf(fp1,"No pattern is present in given text\n");
	 	 }
		count++;
		k++;
	}

		fprintf(fp2,"%d\t",n);
		fprintf(fp2,"%d\t\n",count);
		
	}
}

void main()
{
	int choice;
	FILE *fp1,*fp2;
	int count=0,run=1;
	system("del pattern_A.txt");
	system("del pattern_A_count.txt");
	system("del pattern_B.txt");
	system("del pattern__B_count.txt");
	system("del pattern__W_count.txt");
	system("del pattern__W.txt");
	srand(time(NULL));
	while(run){
		printf("\n1.best case\n2.average case\n3.worst case\n4.exit\nEnter the choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: fp1=fopen("pattern_B.txt","a");
					fp2=fopen("pattern_B_count.txt","a");
					string(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 2: fp1=fopen("pattern_A.txt","a");
					fp2=fopen("pattern_A_count.txt","a");
					string(choice,fp1,fp2,count);
					fclose(fp1);
					fclose(fp2);
					break;
			case 3: fp1=fopen("pattern_W.txt","a");
					fp2=fopen("pattern_W_count.txt","a");
					string(choice,fp1,fp2,count);
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

