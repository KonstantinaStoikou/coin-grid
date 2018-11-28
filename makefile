all: robot

robot: solve.c
	gcc -g solve.c robot_functions.c -o robot

robot_functions: robot_functions.c
	gcc -g robot_functions.c -o robot_functions

clean:
	rm -f robot robot_functions
