#include <queue>
#include "Location2D.h"

using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{ '1','1','1','1','1','1', },
	{ 'e','0','1','0','0','1', },
	{ '1','0','0','0','1','1', },
	{ '1','0','1','0','1','1', },
	{ '1','0','1','0','0','x', },
	{ '1','1','1','1','1','1', },
};

bool isValidLocation(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
};

int main() {
	queue<Location2D> queue;
	Location2D pos(1, 0);
	queue.push(pos);

	while (!queue.empty()) {
		map[pos.row][pos.col] = '.';
		pos = queue.front();
		queue.pop();

		if ('x' == map[pos.row][pos.col]) break;

		if (isValidLocation(pos.row - 1, pos.col)) {
			queue.push(Location2D(pos.row - 1, pos.col));
		}
		if (isValidLocation(pos.row + 1, pos.col)) {
			queue.push(Location2D(pos.row + 1, pos.col));
		}
		if (isValidLocation(pos.row, pos.col - 1)) {
			queue.push(Location2D(pos.row, pos.col - 1));
		}
		if (isValidLocation(pos.row, pos.col + 1)) {
			queue.push(Location2D(pos.row, pos.col + 1));
		}
	};

	if ('x' == map[pos.row][pos.col]) {
		printf("escaped\n");
	}	else {
		printf("fail\n");
	}
	
	return 0;
}