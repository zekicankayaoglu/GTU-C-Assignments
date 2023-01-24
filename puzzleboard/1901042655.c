#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void moveFunc();

/*This function is the function that checks that the table is completed.*/
int checkBoard(int grid[N][N])
{

	int i,j;
	int x=1;
	
	/*win condition of puzzle*/
	if(grid[0][0]==1 && grid[0][1]==2 && grid[0][2]==3 && grid[0][3]==4 && grid[1][0]==5 && grid[1][1]==6 && grid[1][2]==7 && grid[1][3]==8 && grid[2][0]==9 && grid[2][1]==10 && grid[2][2]==11 && grid[2][3]==12 && grid[3][0]==13 && grid[3][1]==14 && grid[3][2]==15 && grid[3][3]==0){
			
			printf("Congratulations you have successfully completed the puzzle!!!!!\n");
			return 1;
			}
				
	else return 0;

}

/*This function is for the current state of the table after moves.*/
void curBoard(int grid[N][N]){
	
	int i,j;
	
	printf("*****************************************************************\n");
	for (i=0; i<N; i++)
	{
		if(i==1 || i==2 || i==3 ) printf("*****************************************************************\n");
		for (j=0; j<N; j++)
		{
			/*if loops for sides of puzzle(*)*/	
			if(j==0){ 
				printf("*\t%u",grid[i][j]);
				printf("\t*");
				}
			else if(j==1 || j==2 || j==3){
			
				printf("\t%u\t*",grid[i][j]);
				}
			
			
			else printf("\t%u",grid[i][j]);	
		
		}
		printf("\n");
		}
	printf("*****************************************************************\n");	

	printf("\n");
}

/*This function is the first state of the table.(mixed randomly)*/
void puzzleBoard()
{
	int grid[N][N]={0};
	int i,j,x=1;
	srand(time(NULL));

	while(x<=15){
		
		i=rand()%4;
		j=rand()%4;
		if(grid[i][j]==0 ){
		grid[i][j]=x;
		x++;
/*Places numbers from 1 to 15 into random index*/
		}		
	}
	
	printf("*****************************************************************\n");/*top edge of the table*/
	
	for (i=0; i<N; i++)
	{
		if(i==1 || i==2 || i==3 ) printf("*****************************************************************\n");
		for (j=0; j<N; j++)
		{
			
			/*if loops for sides of puzzle(*)*/	
			if(j==0){ 
				printf("*\t%u",grid[i][j]);
				printf("\t*");
				}
			else if(j==1 || j==2 || j==3){
			
				printf("\t%u\t*",grid[i][j]);
				}
			
			
			else printf("\t%u",grid[i][j]);
			
		
		
		}
		printf("\n");
		}
		printf("*****************************************************************\n");/*bottom edge of the table*/
	
		
	printf("\n");
	/*Move function starts after the first state of the table.*/
	moveFunc(grid);
		
}

/*enum for directions*/
enum direction1{up=0,
		down=1,
		right=2,
		left=3};


/*This function works for moves.*/		
void moveFunc(int grid[N][N]){
	
	int row,column,temp,temp2;
	enum direction1 direction;
	
	do{
	/*Asking user for start locations*/
	printf("row:");
	scanf("%d",&row);
	printf("column:");
	scanf("%d",&column);
	printf("Direction(up-0 down-1 right-2 left-3):");
	scanf("%u",&direction);
	
	/*cases according to directions*/
	switch(direction){
		
		/*if direction is up*/
		case 0:
			/*checking row and column values*/
			if(row<0 || row>3 || column<0 || column>3) printf("Your row and column values can be range from 0 to 3!!\n");
			
			/*moving up 1 unit*/
			else if(grid[row-1][column]==0 && (row==1 || row==2 ||row==3) ){
				temp=grid[row][column];
				grid[row-1][column]=temp;
				grid[row][column]=0;	
				curBoard(grid);
				}
			
			/*moving up 2 unit*/
			else if(grid[row-2][column]==0 && (row==2 || row==3)){
				temp=grid[row][column];
				grid[row][column]=0;
				grid[row-2][column]=grid[row-1][column];
				grid[row-1][column]=temp;
				curBoard(grid);
				}
			
			/*moving up 3 unit*/
			else if(grid[row-3][column]==0 && row==3){
				temp=grid[row-2][column];
				temp2=grid[row][column];
				grid[row][column]=0;
				grid[row-3][column]=temp;
				grid[row-2][column]=grid[row-1][column];
				grid[row-1][column]=temp2;
				curBoard(grid);
				}
			
			/*the other moves can't be possible*/
			else 
				printf("Impossible move!\n");
				break;
		
		/*if direction is down*/	
		case 1:
			/*checking row and column values*/
			if(row<0 || row>3 || column<0 || column>3) printf("Your row and column values can be range from 0 to 3!!\n");
			
			/*moving down 1 unit*/
			else if(grid[row+1][column]==0 && (row==0 || row==1 ||row==2) ){
				temp=grid[row][column];
				grid[row+1][column]=temp;
				grid[row][column]=0;	
				curBoard(grid);
				}
			
			/*moving down 2 unit*/
			else if(grid[row+2][column]==0 && (row==0 || row==1)){
				temp=grid[row][column];
				grid[row][column]=0;
				grid[row+2][column]=grid[row+1][column];
				grid[row+1][column]=temp;
				curBoard(grid);
				}
			
			/*moving down 3 unit*/
			else if(grid[row+3][column]==0 && row==0){
				temp=grid[row+2][column];
				temp2=grid[row][column];
				grid[row][column]=0;
				grid[row+3][column]=temp;
				grid[row+2][column]=grid[row+1][column];
				grid[row+1][column]=temp2;
				curBoard(grid);
				}
			
			/*the other moves can't be possible*/
			else 
				printf("Impossible move!\n");
				break;

		/*if direction is right*/	
		case 2:
			/*checking row and column values*/
			if(row<0 || row>3 || column<0 || column>3) printf("Your row and column values can be range from 0 to 3!!\n");
			
			/*moving right 1 unit*/
			else if(grid[row][column+1]==0 && (column==0 || column==1 || column==2) ){
				temp=grid[row][column];
				grid[row][column+1]=temp;
				grid[row][column]=0;	
				curBoard(grid);
				}
			
			/*moving right 2 unit*/
			else if(grid[row][column+2]==0 && (column==0 || column==1)){
				temp=grid[row][column];
				grid[row][column]=0;
				grid[row][column+2]=grid[row][column+1];
				grid[row][column+1]=temp;
				curBoard(grid);
				}
			
			/*moving right 3 unit*/
			else if(grid[row][column+3]==0 && column==0){
				temp=grid[row][column+2];
				temp2=grid[row][column];
				grid[row][column]=0;
				grid[row][column+3]=temp;
				grid[row][column+2]=grid[row][column+1];
				grid[row][column+1]=temp2;
				curBoard(grid);
				}
				
			/*the other moves can't be possible*/	
			else 
				printf("Impossible move!\n");
				break;
	
		/*if direction is left*/
		case 3:
			/*checking row and column values*/
			if(row<0 || row>3 || column<0 || column>3) printf("Your row and column values can be range from 0 to 3!!\n");
			
			/*moving left 1 unit*/
			else if(grid[row][column-1]==0 && (column==1 || column==2 || column==3)){
				temp=grid[row][column];
				grid[row][column-1]=temp;
				grid[row][column]=0;	
				curBoard(grid);
				}
			
			/*moving left 2 unit*/
			else if(grid[row][column-2]==0 && (column==2 || column==3)){
				temp=grid[row][column];
				grid[row][column]=0;
				grid[row][column-2]=grid[row][column-1];
				grid[row][column-1]=temp;
				curBoard(grid);
				}
			
			/*moving left 3 unit*/
			else if(grid[row][column-3]==0 && column==3){
				temp=grid[row][column-2];
				temp2=grid[row][column];
				grid[row][column]=0;
				grid[row][column-3]=temp;
				grid[row][column-2]=grid[row][column-1];
				grid[row][column-1]=temp2;
				curBoard(grid);
				}
			
			/*the other moves can't be possible*/	
			else 
				printf("Impossible move!\n");
				break;
		
		/*if entered direction isn't appropriate*/
		default:
			printf("Wrong direction!(Direction can be 0-3)!\n");
		
	}	
	}while(checkBoard(grid)==0);
	/*Functions works until the user wins the game.*/
	
}

int main(){
	
	puzzleBoard();
	
}














