#include <stdio.h>
#define MAX 100 /*defining max as 100*/

int main()
{
	
	int a[MAX] ,b[MAX]={0};/*a keeps the numbers, b keeps repeat counts of numbers*/
	int count=0,exist; /*count counter for number of different numbers*/
	int y,x,j,t,t1,i;
	FILE *file,*file1;
		
  	if ((file = fopen("input.txt", "r"))!=NULL)/*opens input txt*/
  	{	
  		
  		fscanf(file, "%d", &a[0]);/*In order to compare the read elements with each other first we assign the first number to the first element of array.*/
  		b[0]++;/*and we increase the number of the first element by one*/
    		while (fscanf(file, "%d", &x) != EOF)
    		{	
    			/*we assign all the numbers in the file to variable x one by one*/
    			exist=0;/*checks if numbers have not been thrown into the array before*/
    			
    			for(i=0; i<=count; i++){
    				if(x==a[i]){ 
    					/*if the number is in the array, its number increases by 1*/				
    					b[i]++;
    					exist=1;
    					  					
    				}  				
			}
			
			if(exist==0){
				
				a[count+1]=x;/*if the number is not in the array, the next element of the array becomes that number*/
				count++;/*the array grows*/
				b[count]++;/*its number increases by 1*/
				
			}
		}	    			
    		}
    		
    		
    		fclose(file);/*read operation completed*/
    		
    		/*Sorting of numbers happens in this part*/
    		for(i=0;i<=count;i++){
    			for(j=0;j<=count;j++){
    				
    				/*writing the least repeated numbers first*/
    				if(b[j]>b[i]){
    					t1=b[i];
    					b[i]=b[j];
    					b[j]=t1;
    					
    					t=a[i];
    					a[i]=a[j];
    					a[j]=t;
    					   				
    				}
    				/*if the repeat counts are the same, sorting according to numbers*/
    				else if(b[j]==b[i]){
    					if(a[j]>a[i]){
    						t1=b[i];
	    					b[i]=b[j];
	    					b[j]=t1;
	    					
	    					t=a[i];
	    					a[i]=a[j];
	    					a[j]=t;	
    					} 				
    				}  				
    			}   		
    		}
		
		/*opens file for output*/
		file1=fopen("output.txt","w+");
		
		if (file1 = fopen("output.txt", "w+"))
  		{		
  			/*writes arrays to file according to sort*/
    			for(i=0;i<=count;i++){
	    			fprintf(file1,"%d:",a[i]);
	    			fprintf(file1,"%d\n",b[i]);
    		
    		
    		}
    		}
    		
    		fclose(file1);/*closes write file*/
    		
  	return 0;
}





