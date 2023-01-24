#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*counter for number of line*/
void count_line(FILE *file,int *count,int *count2){
	char temp;
	int count1=0,count3=0;
	temp=getc(file);
	while(temp!=EOF){
		
		if(temp=='\n'){
			count1++;
	}
		if(temp!='\n' && temp!=' '){
			count3++;/*counter all chars in file*/
		
		}
	temp=getc(file);
	}
	*count=count1;
	*count2=count3;
	fseek(file,0,SEEK_SET);
}
/*define struct*/
struct circuit{
	char operation[10][10];/*keeps operation of lines*/
	char name[50][50];/*keeps names of gates and inputs*/
	int input[50];/*keeps input file*/
	int in[50];/*keeps values of new gates*/
	int output;/*keeps values of outputs*/

};

/*learning operation of line, takes just first string of the line*/
void learn_op(char *line,char *line1){
	strcpy(line1,line);
	line=strtok(line," ");
}

int main(){
	int count,count1=0,input_num=0,count_input=0,counter,rows,cols,arr[4],b=0,a=0;
	char line[200],line1[200],*token;
	/*calling struct to function*/
	struct circuit *crc;
	FILE *file1,*file2;
	
	/*memory allocation for struct*/
	crc=(struct circuit*)calloc(100,sizeof(struct circuit*));
	
	file1=fopen("input.txt","r");
	count_line(file1,&count,&counter);
	rows=count;/*learning number of input row*/
	cols=(counter/count);/*learning number of input column*/
	
	/*reading input file*/
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			fscanf(file1,"%d",&(crc+i)->input[j]);
		}
		count_input++;/*counter for input number*/
	}
	fclose(file1);
	
	file2=fopen("circuit.txt","r");
	int y=0;
	count_line(file2,&count,&counter);/*learning number of line of circuit*/

	while(b<count_input){
		count_line(file2,&count,&counter);
		a=0;
		count1=0;
		/*reading file line by line*/
		while(fgets(line,sizeof(line),file2) ){
			/*learning operation of line*/
			learn_op(line,line1);
			strcpy((crc+a)->operation[0],line);
			/*according to operation it goes an if*/
			if(strcmp((crc+a)->operation[0],"INPUT")==0){
				token=strtok(line1," ");
				token=strtok(NULL," ");
				input_num=0;
				while(token!=NULL){	
						strcpy((crc+a)->name[input_num],token);/*name array keeps all names of gates and inputs*/
						token=strtok(NULL," \n");
						count1++;
						input_num++;						
				}	
			}

			if(strcmp((crc+a)->operation[0],"AND")==0){
				y=0;
				token=strtok(line1," ");
				token=strtok(NULL," ");
				input_num=0;
				strcpy((crc+a)->name[input_num],token);/*name array keeps new gate name*/
				input_num++;
				count1++;

				token=strtok(NULL," \n");
				for(int i=0;i<count1;i++){
					for(int j=0;j<=a;j++){
						if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
							if(j>0){
								arr[y]=(crc+j)->in[i+1];
								y++;
							}
							else{
								arr[y]=(crc+b)->input[i];
								y++;
							}
						}
					}
				}
				token=strtok(NULL," \n");
				
				for(int i=0;i<count1;i++){
					for(int j=0;j<=a;j++){
						if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
							if(j>0){
								arr[y]=(crc+j)->in[i+1];
								y++;
							}
							else{
								arr[y]=(crc+b)->input[i];
								y++;
							}
						}
					}
				}
				/*finding value of new gate according to truth table*/
				if(arr[y-1]==1 && arr[y-2]==1){
					(crc+a)->in[input_num]=1;				
					input_num++;
				}
				if(arr[y-1]==0 && arr[y-2]==1){
					(crc+a)->in[input_num]=0;
					input_num++;
				}
				if(arr[y-1]==1 && arr[y-2]==0){
					(crc+a)->in[input_num]=0;
					input_num++;
				}
				if(arr[y-1]==0 && arr[y-2]==0){
					(crc+a)->in[input_num]=0;				
					input_num++;
				}
			}
			
			if(strcmp((crc+a)->operation[0],"OR")==0){

				y=0;
				token=strtok(line1," ");
				token=strtok(NULL," ");
				input_num=0;
				strcpy((crc+a)->name[input_num],token);/*name array keeps new gate name*/
				input_num++;
				count1++;
				token=strtok(NULL," \n");

				for(int i=0;i<count1;i++){
					for(int j=0;j<=a;j++){
						if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
							if(j>0){
								arr[y]=(crc+j)->in[i+1];
								y++;
							}
							else{
								arr[y]=(crc+b)->input[i];
								y++;
							}
						}
					}
				}
				
				token=strtok(NULL," \n");

				for(int i=0;i<count1;i++){
					for(int j=0;j<=a;j++){
						if(strcmp((crc+j)->name[i],token)==0){
							if(j>0){
								arr[y]=(crc+j)->in[i+1];
								y++;
							}
							else{
								arr[y]=(crc+b)->input[i];
								y++;
							}
						}
					}
				}				
				/*finding value of new gate according to truth table*/
				if(arr[y-1]==1 && arr[y-2]==1){
					(crc+a)->in[input_num]=1;
					input_num++;

				}
				if(arr[y-1]==0 && arr[y-2]==1){
					(crc+a)->in[input_num]=1;
					input_num++;

				}
				if(arr[y-1]==1 && arr[y-2]==0){
					(crc+a)->in[input_num]=1;
					input_num++;
				}
				if(arr[y-1]==0 && arr[y-2]==0){
					(crc+a)->in[input_num]=0;
					input_num++;
				}
			}
			
			if(strcmp((crc+a)->operation[0],"NOT")==0){

				y=0;
				token=strtok(line1," ");
				token=strtok(NULL," ");
				input_num=0;
				strcpy((crc+a)->name[input_num],token);/*name array keeps new gate name*/
				input_num++;
				count1++;
				token=strtok(NULL," \n");
			
				for(int i=0;i<count1;i++){
					for(int j=0;j<=a;j++){
						if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
							if(j>0){
								arr[y]=(crc+j)->in[i+1];
								y++;
							}
							else{
								arr[y]=(crc+b)->input[i];
								y++;
							}
						}
					}
				}
				/*finding value of new gate according to truth table*/
				if(arr[y-1]==1 ){
					(crc+a)->in[input_num]=0;
					input_num++;
				}
				if(arr[y-1]==0){
					(crc+a)->in[input_num]=1;
					input_num++;
				}
			}
			
			if(strcmp((crc+a)->operation[0],"FLIPFLOP")==0){
				
				/*if this is not the first input line former_out=last output*/
				if(b>0){
					y=0;
					token=strtok(line1," ");
					token=strtok(NULL," ");
					input_num=0;
					strcpy((crc+a)->name[input_num],token);/*name array keeps new gate name*/
					input_num++;
					count1++;
					token=strtok(NULL," \n");

					for(int i=0;i<count1;i++){
						for(int j=0;j<=a;j++){

							if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
								if(j>0){
									arr[y]=(crc+j)->in[i+1];
									y++;
								}
								else{
									arr[y]=(crc+b)->input[i];
									y++;
								}
							}
						}
					}
					/*finding value of new gate according to truth table*/
					if(arr[y-1]==1 && (crc+b-1)->output==1){
						(crc+a)->in[input_num]=0;	
						input_num++;
					}
					if(arr[y-1]==0  && (crc+b-1)->output==1){
						(crc+a)->in[input_num]=1;
						input_num++;
					}
					if(arr[y-1]==1  && (crc+b-1)->output==0){
						(crc+a)->in[input_num]=1;
						input_num++;
					}
					if(arr[y-1]==0  && (crc+b-1)->output==0){
						(crc+a)->in[input_num]=0;
						input_num++;
					}
				}
				/*if this is the first input line former_out=0*/
				else{
					y=0;
					token=strtok(line1," ");
					token=strtok(NULL," ");
					input_num=0;
					strcpy((crc+a)->name[input_num],token);
					input_num++;
					count1++;
					token=strtok(NULL," \n");

					for(int i=0;i<count1;i++){
						for(int j=0;j<=a;j++){

							if(strcmp((crc+j)->name[i],token)==0){/*finds name of gate or input and accordin to j and i it finds its value too*/
								if(j>0){
									arr[y]=(crc+j)->in[i+1];
									y++;
								}
								else{
									arr[y]=(crc+b)->input[i];
									y++;
								}
							}
						}
					}
					/*finding value of new gate according to truth table*/
					if(arr[y-1]==1 ){
						(crc+a)->in[input_num]=1;
						input_num++;
					}
					if(arr[y-1]==0){
						(crc+a)->in[input_num]=0;
						input_num++;
					}	
				}
			}

			if(count-1==a){
				(crc+b)->output=(crc+a)->in[input_num-1];
				printf("%d\n",(crc+b)->output);
			
			}
			a++;/*counter for line number ++*/		
	}
	fseek(file2,0,SEEK_SET);/*goes to beginning of the file to try other input lines*/
	b++;/*counter for input line number++*/
	}
	fclose(file2);
}




