#include <stdio.h>
#include "hw8_lib.h"

void test_maze_move ()
{
	/*first state of maze*/
	cell_type maze[8][8]={
	{cell_wall,cell_wall,cell_wall,cell_wall,cell_wall,cell_wall,cell_target,cell_wall},
	{cell_wall,cell_free,cell_free,cell_free,cell_wall,cell_free,cell_free,cell_wall},
	{cell_wall,cell_free,cell_wall,cell_free,cell_wall,cell_free,cell_wall,cell_wall},
	{cell_wall,cell_free,cell_wall,cell_free,cell_wall,cell_free,cell_free,cell_wall},
	{cell_wall,cell_free,cell_wall,cell_p1,cell_wall,cell_wall,cell_free,cell_wall},
	{cell_wall,cell_free,cell_wall,cell_wall,cell_free,cell_wall,cell_free,cell_wall},
	{cell_wall,cell_p2,cell_free,cell_free,cell_free,cell_free,cell_free,cell_wall},
	{cell_wall,cell_wall,cell_wall,cell_wall,cell_wall,cell_wall,cell_wall,cell_wall},
	};
	
	
	move_type move;
	cell_type player;	
	print(maze);/*printing first state of maze*/
	maze_move(maze,0,0);
}

int main(void) {

	test_maze_move ();
	return (0);
} 
