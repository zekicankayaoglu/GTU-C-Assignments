#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct*/
typedef struct Movie{
	double budget;
	int genre;
	char *name;
	double score;
	int year;
}Movie;

/*this function helps to find number of lines in the file*/
void count_lines(int *counter){
	FILE *file = fopen("Movies.txt", "r");
	int sum = 0;
	char ch;
	
	if(file != NULL){
		for(ch = getc(file); ch != EOF; ch = getc(file)){
			if(ch=='\n') sum += 1;
		}
	}
	fclose(file);
	*counter = sum;
}

/*this function helps to edit data in the file*/
void read_txt(Movie *movies, char genres[30][30], int* counter, int* genre_num){
	 
	 FILE *fp = fopen("Movies.txt", "r");
	 char *b,*ptr;
	 char line[200];
	 int i, j, n=0, gen_num=0,a=0;
	 int gen=-1,len;
	 
	 	
	 	while(fgets(line, sizeof(line), fp) != NULL){ 
	 		if(a!=0){
	 		
			b = strtok(line, ",");
	 		movies[n].budget = strtod(b, &ptr);
	 		for(i=0;i<4;i++){
	 			b = strtok(NULL, ",");
	 			if(i==0){
	 				for(j=0;j<gen_num;j++){
	 					if(strcmp(b, genres[j]) == 0){
	 						gen = j;
	 						break;
	 					}
	 				}
	 				
	 				if(gen==-1){
	 					strcpy(genres[gen_num],b);
	 					movies[n].genre = gen_num;
	 					gen_num++;
	 				}
	 				
	 				else{
	 					movies[n].genre = gen;
	 					gen=-1;
	 				}
	 			}
	 			
	 			if(i==1){
	 				len = strlen(b) + 1;
	 				movies[n].name = (char*)malloc(len);
	 				strcpy(movies[n].name, b);
	 			}
	 			
	 			if(i==2){
	 				movies[n].score = strtod(b, &ptr);
	 			}
	 			
	 			if(i==3){
	 				movies[n].year = (int)strtod(b, &ptr);
	 			}
	 		}
	 		
			for(i=0;i<n;i++){
				if(strcmp(movies[n].name,movies[i].name)==0){
					movies[i].budget = movies[n].budget;
					movies[i].genre = movies[n].genre;
					movies[i].name = movies[n].name;
					movies[i].score = movies[n].score;
					movies[i].year = movies[n].year;
					
					n--;
				}
			}
	 		n++;
	 		}
	 		a++;
	 	}
	 	*counter = n;
	 	*genre_num= gen_num;
	 	fclose(fp);
	 
	 
	
	
	
}

/*this function is second program of the menu*/
void list_of_genres(Movie *movies,char genres[30][30],int* count, int genre_amount){
	
	int i;
	
	for(i=0;i<genre_amount;i++){
	
		printf("%s\n",genres[i]);
		count++;
	}	

}

/*this function is third program of the menu*/
void movie_year(Movie *movies, int new_count){
	
	int year,select,i;
	
	/*it takes a year and asks until or since*/
	printf("Enter a year:");
	scanf("%d",&year);
	printf("Until(0) or Since(1) %d:",year);
	scanf("%d",&select);
	/*according to select it gives the films until or since the year*/
	if(select==0){
		for(i=0;i<new_count;i++){
		if(movies[i].year<year)
			printf("%s\n",movies[i].name);
	}
	
	}
	else if(select==1){
		for(i=0;i<new_count;i++){
		if(movies[i].year>year)
			printf("%s\n",movies[i].name);
	}
	}	

}


/*this function is fourth program of the menu*/
void movie_score(Movie *movies, int new_count){
	
	int select,i;
	float score;
	/*it takes a score from user*/
	printf("Enter a score:");
	scanf("%f",&score);
	printf("Until(0) or Since(1) %.2f:",score);
	scanf("%d",&select);
	
	/*according to select it gives the films until or since the year*/
	if(select==0){
		for(i=0;i<new_count;i++){
		if(movies[i].score<score)
			printf("%s\n",movies[i].name);
	}
	
	}
	else if(select==1){
		for(i=0;i<new_count;i++){
		if(movies[i].score>score)
			printf("%s\n",movies[i].name);
	}
	
	}
	
	
	

}

/*this function is fifth program of the menu*/
void info_movie(Movie *movies,char genres[30][30], int new_count){
	
	char temp[30];
	int i;
	/*it takes a movie name*/
	printf("Enter a movie name:");
	fflush(stdin);
	scanf(" %[^\n]%*c",temp);
	
	/*then it finds all informations about this movie*/
	for(i=0;i<new_count;i++){
		if(strcmp(movies[i].name,temp)==0){
			printf("Budget: %.0lf\n",movies[i].budget);
			printf("Genre: %s\n",genres[movies[i].genre]);
			printf("Name: %s\n",movies[i].name);
			printf("Score: %.1lf\n",movies[i].score);
			printf("Year: %d\n",movies[i].year);
		}
	}

}

/*average score function*/
void average_score(Movie *movies,int new_count){

	double sum=0,avg=0;
	int i;
	/*it takes all scores*/
	for(i=1;i<=new_count;i++){
		sum+=movies[i].score;
		
	}
	/*then divides by the total number of movies*/
	avg=sum/(new_count-1);

	printf("Average score is: %lf\n",avg);
}


/*this function helps to find numbers of genres*/
void genre_movie(Movie *movies,char genres[30][30],int new_count, int genre_amount){
	
	int i,j;
	int x[genre_amount];
	
	for(i=0;i<genre_amount;i++){
		x[i]=0;
	
	}
	/*finds all movies in genres and it increases 1*/
	for(j=0;j<new_count;j++){
		for(i=0;i<genre_amount;i++){
			if(strcmp(genres[movies[j].genre],genres[i])==0)
			x[i]++;
			}
	}
	/*prints numbers of genres*/
	for(i=0;i<genre_amount;i++){
		printf("%-10s ==>  %-10d\n",genres[i],x[i]);
	
	}
	
}

/*single selection for budget*/
void single_budget(Movie *movies, int new_count,char genres[30][30]){

	int value;
	int a,b,j,i;
	
	printf("Enter value:");
	scanf("%d",&value);
	printf("%d. Movie\n\n ",value);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].budget>movies[b].budget)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	
	printf("%-12.0lf  %-12s  %-30s  %.1lf  %-12d\n",movies[value].budget,genres[movies[value].genre],movies[value].name,movies[value].score,movies[value].year);

}

/*multiple selection for budget*/
void multiple_budget(Movie *movies, int new_count,char genres[30][30]){

	int start,end;
	int a,b,j,i;
	
	printf("Enter start value:");
	scanf("%d",&start);
	printf("Enter end value:");
	scanf("%d",&end);
	printf("==Movies between %d and %d,sorted by budget==\n\n",start,end);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].budget>movies[b].budget)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	for(i=start;i<=end;i++){
		printf("%-12.0lf  %-12s  %-85s  %.1lf  %-12d\n",movies[i].budget,genres[movies[i].genre],movies[i].name,movies[i].score,movies[i].year);
	}
}

/*single selection for genre*/
void single_genre(Movie *movies, int new_count,char genres[30][30]){

	int value;
	int a,b,j,i;
	
	printf("Enter value:");
	scanf("%d",&value);
	printf("%d. Movie\n\n",value);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].genre>movies[b].genre)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	
	printf("%-12.0lf  %-12s  %-30s  %.1lf  %-12d\n",movies[value].budget,genres[movies[value].genre],movies[value].name,movies[value].score,movies[value].year);

}

/*multiple selection for genre*/
void multiple_genre(Movie *movies, int new_count,char genres[30][30]){

	int start,end;
	int a,b,j,i;
	
	printf("Enter start value:");
	scanf("%d",&start);
	printf("Enter end value:");
	scanf("%d",&end);
	printf("==Movies between %d and %d,sorted by genre==\n\n",start,end);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].genre>movies[b].genre)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	for(i=start;i<=end;i++){
		printf("%-12.0lf  %-12s  %-85s  %.1lf  %-12d\n",movies[i].budget,genres[movies[i].genre],movies[i].name,movies[i].score,movies[i].year);
	}
}

/*single selection for score*/
void single_score(Movie *movies, int new_count,char genres[30][30]){

	int value;
	int a,b,j,i;
	
	printf("Enter value:");
	scanf("%d",&value);
	printf("%d. Movie\n\n",value);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].score>movies[b].score)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	
	printf("%-12.0lf  %-12s  %-30s  %.1lf  %-12d\n",movies[value].budget,genres[movies[value].genre],movies[value].name,movies[value].score,movies[value].year);


}

/*multiple selection for score*/
void multiple_score(Movie *movies, int new_count,char genres[30][30]){

	int start,end;
	int a,b,j,i;
	
	printf("Enter start value:");
	scanf("%d",&start);
	printf("Enter end value:");
	scanf("%d",&end);
	printf("==Movies between %d and %d,sorted by score==\n\n",start,end);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].score>movies[b].score)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	for(i=start;i<=end;i++){
		printf("%-12.0lf  %-12s  %-85s  %.1lf  %-12d\n",movies[i].budget,genres[movies[i].genre],movies[i].name,movies[i].score,movies[i].year);
	}
}

/*single selection for year*/
void single_year(Movie *movies, int new_count,char genres[30][30]){

	int value;
	int a,b,j,i;
	
	printf("Enter value:");
	scanf("%d",&value);
	printf("%d. Movie\n\n",value);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].year>movies[b].year)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	
	printf("%-12.0lf  %-12s  %-30s  %.1lf  %-12d\n",movies[value].budget,genres[movies[value].genre],movies[value].name,movies[value].score,movies[value].year);


}

/*multiple selection for year*/
void multiple_year(Movie *movies, int new_count,char genres[30][30]){

	int start,end;
	int a,b,j,i;
	
	printf("Enter start value:");
	scanf("%d",&start);
	printf("Enter end value:");
	scanf("%d",&end);
	printf("==Movies between %d and %d,sorted by year==\n\n",start,end);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(movies[a].year>movies[b].year)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	for(i=start;i<=end;i++){
		printf("%-12.0lf  %-12s  %-85s  %.1lf  %-12d\n",movies[i].budget,genres[movies[i].genre],movies[i].name,movies[i].score,movies[i].year);
	}
}

/*single selection for name*/
void single_name(Movie *movies, int new_count,char genres[30][30]){

	int value;
	int a,b,j,i;
	
	printf("Enter value:");
	scanf("%d",&value);
	printf("%d. Movie\n\n",value);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(strcmp(movies[a].name,movies[b].name)>0)
			{
				X=movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	
	printf("%-12.0lf  %-12s  %-30s  %.1lf  %-12d\n",movies[value].budget,genres[movies[value].genre],movies[value].name,movies[value].score,movies[value].year);


}

/*multiple selection for name*/
void multiple_name(Movie *movies, int new_count,char genres[30][30]){

	int start,end;
	int a,b,j,i;
	
	printf("Enter start value:");
	scanf("%d",&start);
	printf("Enter end value:");
	scanf("%d",&end);
	printf("==Movies between %d and %d,sorted by name==\n\n",start,end);
	
	Movie X;
	for(a=0;a<new_count;a++)
	{
		for(b=a+1;b<new_count;b++)
		{
			if(strcmp(movies[a].name,movies[b].name)>0)
			{
				X = movies[a];
				movies[a]=movies[b];
				movies[b]=X;
			}
		}
	}
	for(i=start;i<=end;i++){
		printf("%-12.0lf  %-12s  %-85s  %.1lf  %-12d\n",movies[i].budget,genres[movies[i].genre],movies[i].name,movies[i].score,movies[i].year);
	}
}

/*main function*/
int main(){
	
	int op,operation,line_count;
	int select=0;
	char genres[30][30]; /*to contain which number belongs to which genre.*/
	int new_count,genre,genre_count;
	
	Movie *movies;
	count_lines(&line_count); /*Line count*/
	movies = (Movie *) calloc(line_count, sizeof(Movie));	
	read_txt(movies, genres, &new_count,&genre);
	
	/*prints menu*/
	while(operation!=8){
		printf("1. List of the Sorted Data\n");
		printf("2. List of the Genres\n");
		printf("3. List of the Movie Through the Years\n");
		printf("4. List of the Movie Through the Scores\n");
		printf("5. All Informations of a Single Movie\n");
		printf("6. Average of the IMDB Scores\n");
		printf("7. Frequence of the Genres\n");
		printf("8. Exit\n\n");
		printf("Please Select an operation: ");
		scanf("%d", &operation);
		printf("\n");
		
		/*switch case for calling functions according to operation*/
		switch(operation){
			case 1:
					printf("1. Budget\n");
					printf("2. Genre\n");
					printf("3. Name\n");
					printf("4. Score\n");
					printf("5. Year\n");
					
					op=0;
					
					printf("\nPlease select an operation:");
					scanf("%d", &op);
					if(op<1 || op>5) printf("TRY AGAIN!!!");
					else{
					
					
					printf("\n1. Single Selection\n");
					printf("\n2. Multiple Selection\n");
					
					
					printf("\nPlease select an operation:");
					scanf("%d", &select);
					if(select<1 || select>2) printf("TRY AGAIN!!!");
					else{
					/*calling functions acccording to selection*/
					if(op==1 && select==1) single_budget(movies,new_count,genres);
					else if(op==1 && select==2) multiple_budget(movies,new_count,genres);
					else if(op==2 && select==1) single_genre(movies,new_count,genres);
					else if(op==2 && select==2) multiple_genre(movies,new_count,genres);
					else if(op==3 && select==1) single_name(movies,new_count,genres);
					else if(op==3 && select==2) multiple_name(movies,new_count,genres);
					else if(op==4 && select==1) single_score(movies,new_count,genres);
					else if(op==4 && select==2) multiple_score(movies,new_count,genres);
					else if(op==5 && select==1) single_year(movies,new_count,genres);
					else if(op==5 && select==2) multiple_year(movies,new_count,genres);
						}
						}
					break;
			
			case 2: list_of_genres(movies,genres,&genre_count,genre);
				break;
			
			case 3: movie_year(movies,new_count);
				break;
			
			case 4: movie_score(movies,new_count);
				break;
			
			case 5: info_movie(movies,genres,new_count);
				break;
			
			case 6: average_score(movies,new_count);
				break;
			
			case 7: genre_movie(movies,genres,new_count,genre);
				break;
			
			/*if input is 8*/
			case 8:
				printf("\nExiting the program...\n");
				break;
			
			default:
				printf("TRY AGAIN!!!\n\n");
				break;
		}
		printf("\n");
	}
	free(movies);
	
	return 0;
}









