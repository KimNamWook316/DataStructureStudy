#include "Maze.h"

int main() {
	Maze maze;
	maze.Load("./Data/map.txt");
	maze.Print();
	maze.SearchExit();
	maze.Print();
	return 0;
}