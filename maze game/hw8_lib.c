#include <stdio.h>
#include "hw8_lib.h"
#include <stdlib.h>


int a=0,b=0;
/*print function to print the board on terminal*/
void print(cell_type maze[8][8]){
	
	
	if(a==8){
		a=0;
		b=0;
		printf("\n");
		return;
	}
	else if(b==8){
		a++;
		b=0;
		printf("\n");
		print(maze);
	}
	else{
		if(maze[a][b]==cell_wall){
			printf("X ");
			/*X is wall*/
		}
		else if(maze[a][b]==cell_free){
			printf("- ");
			/*- is free cell*/
		}
		else if(maze[a][b]==cell_p1){
			printf("1 ");
			/*1 is first player*/
		}
		else if(maze[a][b]==cell_p2){
			printf("2 ");
			/*2 is second player*/
		}
		else if(maze[a][b]==cell_target){
			printf("T ");
			/*T is target cell*/
		}
		b++;
		print(maze);
	}



}

int k=0,l=0;
/*this function helps to find place of player 1*/
void current_location1(cell_type maze[][8], int *x, int *y){
	
	if(l==8){
		k++;
		l=0;
		current_location1(maze, x, y);
	}
	else if(k==8){
		l++;
		k=0;
		current_location1(maze, x, y);
	}
	else{
		if(maze[k][l]==cell_p1){
			*x = k;
			*y = l;
			return;
		}
		else{
			l++;
			current_location1(maze, x, y);
		}
	}
}

int f=0,g=0;
/*this function helps to find place of player 2*/
void current_location2(cell_type maze[][8], int *x, int *y){
	
	if(g==8){
		f++;
		g=0;
		current_location2(maze, x, y);
	}
	else if(f==8){
		g++;
		f=0;
		current_location2(maze, x, y);
	}
	else{
		if(maze[f][g]==cell_p2){
			*x = f;
			*y = g;
			return;
		}
		else{
			g++;
			current_location2(maze, x, y);
		}
	}
}

/*this function helps to check winning condition*/
int game_over(cell_type maze[][8],int *r, int *c){
	
	int i,j,x=0;
	
	i=*r;
	j=*c;
	
	/*if one of player can reached the target cell it returns 1*/
	if(maze[i][j]==cell_target) x=1;
	else x=0;
	return x;	

}

/*function for move down*/
void m_down(cell_type maze[][8],int *r, int *c){
	int i,j,temp;
	i=*r;
	j=*c;
	
	/*if next cell is wall*/
	if(maze[i+1][j]==cell_wall){
	printf("INVALID MOVE! TRY AGAIN!\n");
	}
	
	/*if next cell is target*/
	else if(maze[i+1][j]==cell_target){
					
		printf("YOU WON!!!!!!!!!!!\n");
	}
	else{
		/*changing cells*/
		temp=maze[i][j];
		maze[i][j]=maze[i+1][j];
		maze[i+1][j]=temp;
			
	}
	

}

/*function for move up*/
void m_up(cell_type maze[][8],int *r, int *c){
	int i,j,temp;
	i=*r;
	j=*c;
	
	/*if next cell is wall*/
	if(maze[i-1][j]==cell_wall){
	printf("INVALID MOVE! TRY AGAIN!\n");
	}
	
	/*if next cell is target*/
	else if(maze[i-1][j]==cell_target){		
			
		printf("YOU WON!!!!!!!!!!!\n");
		temp=maze[i][j];
		maze[i][j]=maze[i-1][j];
		maze[i-1][j]=temp;
	}
	else{
		/*changing cells*/
		temp=maze[i][j];
		maze[i][j]=maze[i-1][j];
		maze[i-1][j]=temp;		
	
	}

}

/*function for move left*/
void m_left(cell_type maze[][8],int *r, int *c){
	
	int i,j,temp;
	
	i=*r;
	j=*c;
	
	/*if next cell is wall*/
	if(maze[i][j-1]==cell_wall){
	printf("INVALID MOVE! TRY AGAIN!\n");
	}
	/*if next cell is target*/
	else if(maze[i][j-1]==cell_target){
			
		printf("YOU WON!!!!!!!!!!!\n");
	}
	else{
		/*changing cells*/
		temp=maze[i][j];
		maze[i][j]=maze[i][j-1];
		maze[i][j-1]=temp;
		
	}
}

/*function for move right*/
void m_right(cell_type maze[][8],int *r, int *c){
	
	int i,j,temp;
	i=*r;
	j=*c;
	
	/*if next cell is wall*/
	if(maze[i][j+1]==cell_wall){
	printf("INVALID MOVE! TRY AGAIN!\n");
	}
	/*if next cell is target*/
	else if(maze[i][j+1]==cell_target){
				
		printf("YOU WON!!!!!!!!!!!\n");
	}
	else{
		/*changing cells*/
		temp=maze[i][j];
		maze[i][j]=maze[i][j+1];
		maze[i][j+1]=temp;
	
	}

}


/*main function of maze algorithm*/
int maze_move(cell_type maze[][8], cell_type player, move_type move)
{
	int play;
	int direction;
	int r,c,i,j;
	
	
	printf("enter player(1 or 2)(0-to finish game):");
	scanf("%d",&play);
	
	/*learning player who is making move next*/
	if(play==1) player=cell_p1;
	else if(play==2) player=cell_p2;
	else if(play==0) return 0;
	
	printf("enter move direction(down-0 up-1 left-2 right-3):");
	scanf("%d",&direction);
	
	/*learning move direction*/
	if(direction==0) move=move_down;
	else if(direction==1) move=move_up;
	else if(direction==2) move=move_left;
	else if(direction==3) move=move_right;
	
	/*learning place of players*/
	if(player==cell_p1) current_location1(maze,&r,&c);
	else if(player==cell_p2) current_location2(maze,&r,&c);
	
	/*switch for move functions*/
	switch(move){
		case move_down: m_down(maze,&r,&c); break;
		case move_up: m_up(maze,&r,&c); break;
		case move_left: m_left(maze,&r,&c); break;
		case move_right: m_right(maze,&r,&c); break;	 
	
	}
	print(maze);
	
	/*checking win condition*/
	if(game_over(maze,&r,&c)==0) maze_move(maze,0,0);
	else if(game_over(maze,&r,&c)==1) return 0;
		
	
}







































