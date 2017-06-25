/*
 Name: Hai Dang Hoang
 Email: goldsea5191@gmail.com
 Maze solver
*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

void draw_maze(char **, int, int);
void wall_follower (char **, int, int , int , int, int, int);
bool recursiveSolve(char **, int , int, int, int, int, int, bool **);
int main (int argc, char *argv[])
{
  if(argc == 1)
   printf ("MISSING INPUT file! Please includes maze.txt file \n");
  else if (argc > 2)
   printf ("TOO MANY INPUT! \n");
  else
  {
      FILE *ifp;

      int row, col;             // Row and Col from maze
      int start_row, start_col; // Position start point
      int end_row, end_col;     // Position end point
      // Reading the file
      ifp = fopen (argv[1],"r");
      // Error file
      if (ifp == NULL)
      {
        fprintf(stderr,"Can't open input file ! \n");
        return -1;
      }
      // Read the three lines from input file (ignore the comma)
        fscanf(ifp, "%d %*[,] %d", &col,&row);
        fscanf(ifp, "%d %*[,] %d", &start_col,&start_row);
        fscanf(ifp, "%d %*[,] %d", &end_col,&end_row);
      // Create Dynamically allocating multidimensional array
      char **array;
      array = malloc(row * sizeof(int *));
      if (array == NULL)
      {
          fprintf(stderr," out of memory \n");
          return -1;
      }
      for (int i = 0;i< row; i++)
      {
          array[i] = malloc(col * sizeof(int));
          if(array[i]== NULL)
          {
              fprintf(stderr," out of memory \n");
              return -1;
          }
      }
      // Store maze into dynamic array.
      char temp;
      fscanf(ifp,"%c", &temp);
      int i = 0, j = 0, count = 0;
      while(fscanf(ifp,"%c%*[,\t\n]", &temp)!= EOF)
      {
         array[i][j] = temp;
         j++;
         if(j == col)
         {
           j = 0;
           i++;
         }
      }
      draw_maze(array,row,col);
      // Algorithm wall follower
      wall_follower(array,start_row,start_col,end_row,end_col,row,col);
      printf("------------------------------------------------- \n");
      printf("OUTPUT: \n");
      draw_maze(array,row,col);
      // Close the file
      fclose (ifp);
  }
  return 0;
}

// Function draw the maze
void draw_maze(char **maze, int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j< col; j++)
      printf("%c",maze[i][j]);
    printf("\n");
  }
}

/* Function Wall Follower Algorithm
   Return -1 --> Error
   Return 0 --> Sucesscul wall follower algorithm
*/
void wall_follower (char **maze, int start_row, int start_col, int end_row, int end_col,int row, int col)
{
  maze[start_row][start_col] = 'W';
  bool **wasHere;
  wasHere = malloc(row * sizeof(int *));
  for (int i = 0;i< row; i++)
      wasHere[i] = malloc(col * sizeof(int));


          // Using to check correct path
  // Sets boolean arrays to default values
  for (int i = 0; i < row; i++)
    for (int j = 0; j< col; j++)
      wasHere[i][j] = false;

  bool check = recursiveSolve(maze,start_row, start_col, end_row, end_col,row,col,wasHere);
  // Will leave it with a boolean array (correctPath)
  // with the path indicated by true values.
  // If check is false, there is no solution to the maze.
  maze[end_row][end_col] = 'W';
}

// Function Recursion
bool recursiveSolve(char **maze, int x, int y, int end_row, int end_col,int row, int col,bool **wasHere)
{

  if ((x== end_row)&&(y== end_col)) // if it reached the end
    return true;
  if ((maze[x][y]=='X')|| wasHere[x][y])
    return false;
  wasHere[x][y] = true; // if it is on a wall or already were here
  if(x != 0)  // Checks if not on left edge
    if(recursiveSolve(maze,x-1,y,end_row,end_col,row,col,wasHere)) // Recalls method one to the left
    {
      maze[x][y] = 'W'; // Sets that path value to true
      return true;
    }
  if (x!= row -1)   // Checks if not on right edge
    if(recursiveSolve(maze,x+1,y,end_row,end_col,row,col,wasHere)) // Recalls method one to the right
    {
      maze[x][y] = 'W';
      return true;
    }
  if (y!=0)         // Checks if not on top edge
    if(recursiveSolve(maze,x,y-1,end_row,end_col,row,col,wasHere)) // Recalls method one up
    {
      maze[x][y] = 'W';
      return true;
    }
    if (y!= col -1) // Checks if not on bottom edge
      if(recursiveSolve(maze,x,y+1,end_row,end_col,row,col,wasHere)) // Recalls method one down
      {
        maze[x][y] = 'W';
        return true;
      }
  return false;
}

// Algorithm reference : https://en.wikipedia.org/wiki/Maze_solving_algorithm
