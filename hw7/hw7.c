#include <stdio.h>
/*recursion function to check neighbors of matrix elements*/
void check(int arr[512][512],int i,int j,int l){/*matrix,row,column and L comes to function*/
	/*if is it a part of island its coordinates becomes -1 to check all islands easily*/
	arr[i][j]=-1;
	/*if conditions help to check edges and corners of matrix*/
	if(i==0 || j==0){/*if coordinate is at left or top edge*/
		if(i==0 && j==0){/*if coordinate is first element of matrix*/
			if(arr[i][j+1]>l) check(arr,i,j+1,l);/*calls function again to check right of coordinate*/
			if(arr[i+1][j]>l) check(arr,i+1,j,l);
		}
		
		if(i==0 && j!=0){/*if coordinate is at first row(top edge)*/
			if(j==511){/*right-top corner*/
				if(arr[i+1][j]>l) check(arr,i+1,j,l);
				if(arr[i][j-1]>l) check(arr,i,j-1,l);
			}
			if(arr[i+1][j]>l) check(arr,i+1,j,l);
			if(arr[i][j+1]>l) check(arr,i,j+1,l);
			if(arr[i][j-1]>l) check(arr,i,j-1,l);
			}
			
		if(j==0 && i!=0){/*if coordinate is at first column(left edge)*/
			if(i==511){/*left-bottom corner*/
				if(arr[i-1][j]>l) check(arr,i+1,j,l);
				if(arr[i][j+1]>l) check(arr,i,j-1,l);
			}			
			if(arr[i][j+1]>l) check(arr,i,j+1,l);
			if(arr[i+1][j]>l) check(arr,i+1,j,l);
			if(arr[i-1][j]>l) check(arr,i-1,j,l);
		}
	}
	
	if(i<511 && j<511 && i!=0 && j!=0){/*if coordinate is not at edges*/
		if(arr[i+1][j]>l) check(arr,i+1,j,l);
		if(arr[i][j+1]>l) check(arr,i,j+1,l);
		if(arr[i-1][j]>l) check(arr,i-1,j,l);
		if(arr[i][j-1]>l) check(arr,i,j-1,l);
	}
	
	if(i==511 || j==511){/*if coordinate is at right or bottom edge*/
		if(i==511 && j==511){/*if coordinate is last element of matrix*/
			if(arr[i][j-1]>l) check(arr,i,j-1,l);
			if(arr[i-1][j]>l) check(arr,i-1,j,l);
		}
		
		if(i==511 && j!=511){/*if coordinate is at last row(bottom edge)*/
			if(arr[i-1][j]>l) check(arr,i-1,j,l);
			
			if(j>0){
				if(arr[i][j-1]>l) check(arr,i,j-1,l);
			}
			if(arr[i][j+1]>l) check(arr,i,j+1,l);
			}
			
		if(j==511 && i!=511){/*if coordinate is at last column(right edge)*/
			if(arr[i+1][j]>l) check(arr,i+1,j,l);
			
			if(i>0){
				if(arr[i-1][j]>l) check(arr,i-1,j,l);
			}
			if(arr[i][j-1]>l) check(arr,i,j-1,l);
		}	
	}
}

int main(){
	int M[512][512];
	int x=0,flag=0,L;
	FILE *file1,*file2;
	file1=fopen("input.txt","r");
	/*reading input file to matrix*/
		for(int i=0;i<512;i++){
			for(int j=0;j<512;j++){
				if(j==0 && i==0){
					fscanf(file1,"%d",&L);/*first number is water length*/
				}
				fscanf(file1,"%d",&M[i][j]);
			}
		}
	file2=fopen("output.txt","w+");
	/*checking matrix elements according to their row and column numbers*/
	while(flag==0){	
		for(int i=0;i<512;i++){
			for(int j=0;j<512;j++){
				
				if(j==511 || i==511){/*if element is at right or bottom edges*/
					if(i==511 && j==511){/*if it is last element of matrix*/
						if(M[i][j]>L){
								M[i][j]=-1;/*if it is taller than water coordinate becomes -1 to check all of them easily*/
								if(x==0 && (M[i][j-1]!=-1 && M[i-1][j]!=-1) ){/*x keeps condition for print coordinates*/
									fprintf(file2,"%d %d\n",i,j);/*if it is first coordinate of an island it prints to file*/
								
								}
								check(M,i,j,L);/*sends coordinates to function*/
								/*checks neighbors for print or not print the coordinates*/
								if(M[i][j-1]<L && M[i-1][j]<L && M[i][j-1]!=-1 && M[i-1][j]!=-1){
									x=0;
								}
								flag=0;/*flag is a condition for the cycle to continue */			
							}
					}
					
					if(i==511 && j!=511){/*if it is at last row*/
						if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 && (M[i][j-1]!=-1 && M[i-1][j]!=-1 && M[i][j+1]!=-1)){
									fprintf(file2,"%d %d\n",i,j);	/*if it is first coordinate of an island it prints to file*/
								}
								check(M,i,j,L);/*sends coordinates to function*/
								if(M[i][j+1]<L && M[i][j+1]!=-1 && M[i][j-1]!=-1 && M[i-1][j]!=-1){/*checks neighbors for print or not print the coordinates*/
									x=0;
								}			
								flag=0;
							}
					}
					
					if(j==511 && i!=511){/*if it is at last column*/
						if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 && (M[i][j-1]!=-1 && M[i-1][j]!=-1 && M[i+1][j]!=-1) ){
									fprintf(file2,"%d %d\n",i,j);/*if it is first coordinate of an island it prints to file*/
								}
								check(M,i,j,L);/*sends coordinates to function*/
								/*checks neighbors for print or not print the coordinates*/
								if(M[i+1][j]<L && M[i+1][j]!=-1 && M[i][j-1]!=-1 && M[i-1][j]!=-1){
									x=0;
								}
								flag=0;
							}
					}
				}
				
				if(i>0 && j>0 && j!=511 && i!=511){/*if element is not at edges*/
						if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 && (M[i][j-1]!=-1 && M[i-1][j]!=-1 && M[i][j+1]!=-1 && M[i+1][j]!=-1) ){
									fprintf(file2,"%d %d\n",i,j);/*if it is first coordinate of an island it prints to file*/
									}
								check(M,i,j,L);/*sends coordinates to function*/
								/*checks neighbors for print or not print the coordinates*/
								if(M[i][j+1]<L && M[i+1][j]<L && M[i][j-1]<L && M[i-1][j]<L && M[i][j+1]!=-1 && M[i+1][j]!=-1 && M[i][j-1]!=-1 && M[i-1][j]!=-1){
									x=0;
								}
								flag=0;
						}
				}
				/*if element is at left or top edges*/
				if(i==0 || j==0){
					
					if(i==0 && j==0){/*if it is at left-top corner*/
						if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 && (M[i][j+1]!=-1 && M[i+1][j]!=-1)){
									fprintf(file2,"%d %d\n",i,j);/*if it is first coordinate of an island it prints to file*/
									}
								check(M,i,j,L);
								/*checks neighbors for print or not print the coordinates*/
								if(M[i][j+1]<L && M[i+1][j]<L && M[i][j+1]!=-1 && M[i+1][j]!=-1){
									x=0;
								}
								flag=0;
							}				
					}
					
					if(i==0 && j!=0){/*if it is at first row*/
							if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 &&( M[i][j-1]!=-1 && M[i][j+1]!=-1 && M[i+1][j]!=-1) ){
									fprintf(file2,"%d %d\n",i,j);
									}
								check(M,i,j,L);/*sends coordinates to function*/
								/*checks neighbors for print or not print the coordinates*/
								if(M[i][j+1]<L && M[i+1][j]<L && M[i][j+1]!=-1 && M[i+1][j]!=-1 && M[i][j-1]!=-1){
									x=0;
								}
								flag=0;
								}			
					}
					
					if(j==0 && i!=0){/*if it is at first column*/
							if(M[i][j]>L){
								M[i][j]=-1;
								if(x==0 &&(M[i-1][j]!=-1 && M[i][j+1]!=-1 && M[i+1][j]!=-1) ){
									fprintf(file2,"%d %d\n",i,j);	
								}
								check(M,i,j,L);/*sends coordinates to function*/
								/*checks neighbors for print or not print the coordinates*/
								if(M[i][j+1]<L && M[i+1][j]<L && M[i][j+1]!=-1 && M[i+1][j]!=-1 && M[i-1][j]!=-1){
									x=0;
								}
								flag=0;
								}
					}	
					}
					else {
						flag=1;		
						}
							}
					}
			}
	fclose(file1);
	fclose(file2);
}


