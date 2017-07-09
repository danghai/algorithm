# Maze Solver

Design and develop a maze solving application. We use recursive algorithm to solve the maze. The simple recursive algorithm can tell one how to get to the end. The algorithm will be given a starting X and Y value. If the X and Y values are not on a wall, the method will call itself with all adjacent X and Y values, making sure that it did not already use those X and Y values before. If the X and Y values are those of the end location, it will save all the previous instances of the method as the correct path.

1.  Maze Representation 
A maze will be represented as a 2-dimensional array of characters of any dimension. The code use dynamic memory. The maze will be provided in a text file also specifying the maze entry and exit coordinates within the array. 

The first line of the maze file will contain the number of rows and columns of the maze as a comma separated value. The first value will be number of columns (X-axis) and the second value will be the number of rows (Y-value).

The second line in the file will contain the X,Y coordinate within the array that specifies the entry to the maze. The maze traversal algorithm should use this coordinate as starting point.

2. Program Output
After finding the path between the entry and the exit point, program prints to the console the structure of the maze showing the path between the entry and the exit. We will use ASCII characters to draw the maze on the screen. 

Below is an example of a possible sample output for the solution of a simple maze in which X represents a Wall, 0 represents a Walking tile not part of the solution and W represents the solution: 
```
XXXXXWXXXXXXXXXXXXXXXXXXXXXXXXXX
XX0XXWXXXXXX0000X0XXX00WWWWWWWWX
XX000WWWWW000XX00000XXXWXXXX0XWX
XXXXXXXXXWXX0XXXX0XXXXXWXXXX0XWX
XXXXWWWWWWXX0XX0XXX0000WWWWXXXWX
XXXXWXXXXXX00000XX00XX0XXXWXXXWX
XX00WWWXXXXXXX0XXXXXXXXXWWWXXXWW
XXX0XXWXX0XXXXXXXXX0XXWWWXXXXXXX
XX00XXWXX00X000XXXXWWWWXXXXXXXXX
XXXXX0WWW0XX0XXXXXXWXX0000XXXXXX
XXXXXXXXWXXX00XX000WXXXX0XX00XXX
XXXXXX00WWWWWXXXXXXWXXXX0XX0XXXX
XXXXXXXXXXXXWXXXXXXWXXXX0000XXXX
XXXXXXXXXXWWWXX0XXXWXXXXX0XXXXXX
XXXXXXXXXXWXXXXWWWWWXXX0000000XX
XXXXXXXXXXWXXWWWXXXXX0XXXX0XX00X
XXXXXXXXXXWWWWXXXXXXX000000XXX0X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
```
3. Makefile

Run program:
```
make
./maze maze2.txt
```
