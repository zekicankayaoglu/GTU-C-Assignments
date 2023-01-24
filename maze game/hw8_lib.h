
typedef enum { cell_wall,cell_free,cell_target,cell_p1,cell_p2
}cell_type;

typedef enum { move_down,move_up,move_left,move_right
}move_type;

void clean_file(char* infile, char * outfile, char* words_to_delete[1], int number_of_words);


int maze_move(cell_type maze[][8], cell_type player, move_type move);

void print(cell_type maze[][8]);/*this function helps to print maze at the beginning*/


void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n);
