#include <stdio.h>
#include <string.h>

/*counter for '*'*/
void counter(char arr[100], int* count){

	/*if function finds '*' that means input is not a number*/
	int count1=0;
	char c='*';
	
	for(int i = 0; i < strlen(arr); i++){
	
		if(arr[i] == c){
		
			count1++;
		}
	}
	*count=count1;
}

/*splits input line*/
void parse_input(char* buffer,int* num,char nameo[][15],int count,int* num_part){

	char *token,*token1,*token2;
	char temp[25][15];
	int i;
	
	i=*num_part;
	/*if input has one part*/
	if(count==1){
		/*splits according to '*'*/
		token=strtok(buffer,"\n");
		token1=strtok(token,"*");
		sscanf(token1,"%d",&num[i]);
		token2=strtok(NULL," ");
		strcpy(nameo[i],token2);
		i++;
		*num_part=i;	
	}
	/*if input has more than one part*/
	else if(count>1){
		
		/*splits according to '+'*/
		token=strtok(buffer,"+");
		int x=i;
		
		while(token!=NULL){
			/*throws the part names to temp array*/
			strcpy(temp[i],token);
			i++;			
			token=strtok(NULL,"+");
			
		}
		/*then assigns temp elements to nameo array*/
		for(int y=x;y<i;y++){
			token1=strtok(temp[y],"*");
			sscanf(token1,"%d",&num[y]);
			token2=strtok(NULL," ");
			strcpy(nameo[y],token2);

		}
		*num_part=i;	
	}
}

/*if input is number this function converts it to double*/
double convert_number(char buffer[100]){
	
	double price;
	sscanf(buffer,"%lf",&price);
	return price;
}

/*recursion function*/
double price_object(char* buffer){
	/*nameo:keeps names of parts ,num:keeps number of parts,numpart = number of part */
	
	char buffer2[100],nameo[25][15],*object;
	int count,num[25],numpart=0;
	double total=0.0,price;
	/*asking 'what is ' question*/
	printf("> What is %s?:\n> ",buffer);
	fgets(buffer2,100,stdin);
	object=strtok(buffer2,"\n");
	counter(object,&count);
	/*count checks input number or not*/
	/*if input is not a number:*/
	if(count>=1){
		/*calls parse function to split input*/
		parse_input(object,num,nameo,count,&numpart);
	
		for(int i=0;i<numpart;i++){	
			/*calls price_object function again*/
			price=price_object(nameo[i]);
			total=total + num[i]*price;
			}
					
		return total;
	}
	
	else /*if input is number:*/
		return convert_number(object);			
}

/*main function calls recursion function and prints price*/
int main(){
	
	char buffer[100];
	double price;
	/*gets the object's name*/
	printf("> Define the object:\n> ");
	fgets(buffer,sizeof(buffer),stdin);
	char* object=strtok(buffer,"\n");

	/*sends object name to recursion function*/
	price = price_object(object);
	printf("\nTotal cost of %s is %.1lf\n",object,price);
	return 0;
}




