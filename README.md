## A C program that finds recursively the best path to collect maximum possible coins.
### Pathfinding function
You can change the function by which the program finds the path, by changing the defined identifier in robot_functions.h (default is MATRREC).  
**Pathfinding identifiers:**  
PUREREC = pure recursive  
MATRREC = matrix recursion  
ITERDP = iterative dynamic programming  
  
*PUREREC only outputs number of coins collected, not the path*
### Calling the program
The grid can be given either as a text file by running the program as: 
``` 
$ ./robot < grid.txt
```
or by giving the grid after calling the program. The size of the grid must first be defined 
and then the grid must be given, by symbolizing C as cells with coins and . as empty cells:
``` 
$ ./robot < grid.txt
3 4
C..C
.C..
CC.C
```
### Output 
The program will output the found path and for each cell visited it will show if it had a cell or not, its coordinates and how many coins were collected until there, and finally the total number of coins collected.  
e.g.  
```
Path is: C(1,1)/1 --> .(1,2)/1 --> C(2,2)/2 --> C(3,2)/3 --> .(3,3)/3 --> C(3,4)/4 --> Picked up 4 coins
```    
*coin or empty*__(__*coordinates*__)/__*coins until that cell*
