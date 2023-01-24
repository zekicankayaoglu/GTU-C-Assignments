#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000
#define MAX_VALUES 100


int main(){
	char arr[MAX], A[MAX][MAX],operator = '+',token[MAX],*token1;
	double lf1,lf2,sum,values[MAX_VALUES],evaluation[MAX_VALUES],val;
	int i,j=0,count=0,count1=0,count_values=0,b[MAX],l=0;
	
	FILE *file,*file1,*file2;
	file = fopen("polynomial.txt", "r");
	
	/*reading polynomial txt as char array*/
	fscanf(file, "%[^\n]", arr);
	for(i = 0; i < strlen(arr); i++){
		if(arr[i] == '-' || arr[i] == '+'){
			count1++;
		}
	}

	for(i = 0; i < strlen(arr); i++){
		
		/*reading according to + - and filling array*/
		if((arr[0] != '-' && arr[0] != '+') || i != 0){
			for(int k = 0; arr[count] != '-' && arr[count] != '+'; k++){
				if(k==0){
					A[i][k] = operator;
							
				}
				
				else{
					A[i][k] = arr[count];
					count++;
					
					
				}
			}

				if(i != strlen(arr)-1){
					count++;
					operator = arr[count-1];
						
				}
				
					
		}

		else{
			
			/*this part finds the operator of first element*/
			if(arr[0] == '-') A[0][0] = '-';
			else if(arr[0] == '+') A[0][0] = '+';
			count++;
			
			for(int k = 1; arr[count] != '-' && arr[count] != '+'; k++){
				if(k==0){
					A[i][k] = operator;
						
				}
				else{
					A[i][k] = arr[count];
					count++;
				}
			}

			if(i != strlen(arr)-1){
				count++;
				operator = arr[count-1];
			
			}
				
		}
	}
	
	/*reading values from values txt*/
	file1 = fopen("values.txt","r");
	fscanf(file1, "%lf ", &values[0]);
	
	count_values++;
	/*throw values into values array*/
	while (fscanf(file1, "%lf ", &val) != EOF){
		values[count_values]=val;
		count_values++;	
	}
	/*evulations are equals 0 first*/
	for(j=0;j<count_values;j++){
		evaluation[j]=0;
	
	}
	/*this loop helps to split polynomial*/
	for(j=0;j<count_values;j++){
		b[j]=0;
	
	}
	
	/*this part helps to split polynomial*/
	for(i = 0; i < count1+1; i++){
		for(int k = 0; k < strlen(A[i]); k++){
			/*according to '^'*/
			if(A[i][k]=='^'){
				strcpy(token,A[i]);
				b[i]=-1;
				l++;
				token1=strtok(token,"x");				
				sscanf(token1,"%lf",&lf1);
				
				/*if the coefficient is 1 or -1*/
				if(strcmp(token,"+")==0){
					lf1=1;
					sscanf(A[i],"+x^%lf",&lf2);
				}
				
				else if(strcmp(token,"-")==0){
					lf1=-1;
					sscanf(A[i],"-x^%lf",&lf2);
				}
				
				else{
					sscanf(A[i],"%lfx^%lf",&lf1,&lf2);
				}	
				
				if(lf1!=0){
					for(j=0;j<count_values;j++){
						/*calculation according to coefficient and power*/
						evaluation[j]=evaluation[j]+lf1*pow(values[j],lf2);
					
					}
				}							
			}			
		}
	}
	/*if the value has not power this part works*/
	for(int m=0;m<l;m++){
				if(b[m]==0){
					strcpy(token,A[m]);
					token1=strtok(token,"x");				
					sscanf(token1,"%lf",&lf1);
					
					/*if the coefficient is 1 or -1*/
					if(strcmp(token,"+")==0){
						lf1=1;
						
					}
					else if(strcmp(token,"-")==0){
						lf1=-1;	
					}
									
					if(lf1!=0){
						for(j=0;j<count_values;j++){	
						/*calculation according to coefficient*/					
							evaluation[j]=evaluation[j]+lf1*values[j];						
						
						}
					}
				}			
			}
	/*writing results to evaluation txt file*/
	file2 = fopen("evaluations.txt", "w+");		
	for(j=0;j<count_values;j++){
		fprintf(file2,"%.2lf\n",evaluation[j]);
	
	}
	fclose(file);
	fclose(file1);
	fclose(file2);
	
	return 0;
}

