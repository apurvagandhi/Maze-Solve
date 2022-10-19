/*  File Name: solveMaze.cc
	Name: Apurva Gandhi
	Class: CSCI 132 - 01
	Assignment: 5
	Professor: Saba Kadady
	Date: 03/18/2019
	Program to draw a random maze and solve it.
	From a given position on the maze, the function will move to an adjacent square, try to solve the maze,
	then move back to the original space. It will continue by moving to another adjacent
	square, until it finds a solution or until all adjacent squares have been tried without success.
	this program will mark a path as it takes each successive move.
	Finally, it will print out the successful path to solve the maze for a given dimention. 
*/

#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

/* Pre: None
   Post: Solves the randomly chosen maze by calling solve function
   which recursively calls it self and finds the solution to the maze.
*/
int main()
{
	int width, height;
	char answer;

	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') 
	{
		cout << "Enter number for width of maze: ";
		cin >> width;
		cout << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();

		if (!solve(myMaze, 0, 0))
		{
			cout << "Couldn't solve this maze!" << endl;
		}//if maze NOT solved
		
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
		cout << answer << endl;
	} // while solving another maze

	return 0;
} //end main program

/* Pre:None
   Post:Solve the maze from position x, y.If a solution is found, 
   print it out and return a value of true.If no solution is found, return false.
*/
bool solve(Maze &theMaze, int x, int y) 
{
	//Recursively solve theMaze from position x, y
	if (theMaze.get_position(x, y) == 2)
	{
		theMaze.print_maze();
			return true;
	}
	if (theMaze.get_position(x, y) == 1)
	{
		return false;
	}
	if (theMaze.get_position(x, y) == 0)
	{
		theMaze.set_position(x, y, 1);
		if (!isWallAbove(theMaze, x, y))
		{
			if (solve(theMaze, x, y - 1))
				return true;
		}
		if (!isWallBelow(theMaze, x, y))
		{
			if (solve(theMaze, x, y + 1))
				return true;
		}
		if (!isWalltoRight(theMaze, x, y))
		{
			if (solve(theMaze, x + 1, y))
				return true;
		}
		if (!isWalltoLeft(theMaze, x, y))
		{
			if (solve(theMaze, x - 1, y))
				return true;
		}
		theMaze.set_position(x, y, 0);
		return false;
	}
} //end solve

/* Pre:None
   Post:Return true if there is a wall above maze position x, y; return false otherwise.
*/
bool isWallAbove(Maze &theMaze, int x, int y)
{
	return theMaze.is_horizontal_wall(x, y);
} //end isWallAbove

/* Pre:None
   Post:Return true if there is a wall below maze position x, y; return false otherwise.
*/
bool isWallBelow(Maze &theMaze, int x, int y)
{

	return theMaze.is_horizontal_wall(x, y+1);
} //end isWallBelow

/* Pre:None
   Post:Return true if there is a wall to the left of the maze; return false otherwise.
*/
bool isWalltoLeft(Maze &theMaze, int x, int y)
{

	return theMaze.is_vertical_wall(x, y);
} //end isWalltoLeft

/* Pre:None
   Post:Return true if there is a wall to the right of the maze; return false otherwise.
*/
bool isWalltoRight(Maze &theMaze, int x, int y) 
{

	return theMaze.is_vertical_wall(x+1	, y);
} //end isWalltoRight
