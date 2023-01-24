#include <stdio.h>
#include <string.h>
#define MAX 250


/*counter for '-'*/
void counter1(char arr[],int num,int* count){
	
	int y=0;
	/*difference of '(' and ')' gives us number of '-' */
	for(int i=0;i<num;i++){
		if(arr[i]=='('){
			y++;
			/*number of '('*/
		}
		
		else if(arr[i]==')'){
			y--;
			/*number of ')'*/
		}	
	}
	*count=y;
	/*count is equal to number of '-' for element of array*/
}

/*recursion function to print output*/
void print_recursion(FILE *file,char arr[],int count,int number){
			
	if(count>0){
		fprintf(file,"-");
		print_recursion(file,arr,count-1,number);
		}
	if(count==0){
		fprintf(file,"%c\n",arr[number]);
	
	}							
}

/*main recursion function to see tree*/
void recursion(FILE *file,char arr[],int num,int count){
	
	int a,counter;
	
	/*if the element of array is not '(' or ')' or ',' calls counter and print function*/
	if(num<count){
		if(arr[num]!='(' && arr[num]!=')' && arr[num]!=','){
			
			counter1(arr,num,&counter);/*learns how many - should be written*/
			print_recursion(file,arr,counter,num);/*prints the - and element*/
			recursion(file,arr,num+1,count);/*calls this function again*/
	}
	else 
		/*if the element is '(' or ')' or ',' calls this function again to switch next element*/
		recursion(file,arr,num+1,count);
}	
}

int main(){
	/*main function reads the input file and sends array to function */
	int count;
	char arr[MAX];
	
	FILE *file1,*file2;
	/*reading input file*/
	file1=fopen("input.txt","r");
	fscanf(file1, "%[^\n]", arr);
	count=strlen(arr);/*length of array*/
	/*output file for print output*/
	file2=fopen("output.txt","w+");
	recursion(file2,arr,0,count);/*sends array and output file to function*/
	fclose(file1);
	fclose(file2);
}

