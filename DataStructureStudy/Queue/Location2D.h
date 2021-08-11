#ifndef __LOCATION2D_H__
#define __LOCATION2D_H__
class Location2D {
public:
	explicit Location2D(const int& r = 0, const int& c = 0) { row = r; col = c; }
	bool IsNeighbor(const Location2D& p) {
		return (p.row == row && (p.col == col - 1 || p.col == col + 1) ||
			(p.col == col) && (p.row == row - 1 || p.row == row + 1 ));
	}
	bool operator == (const Location2D& p) { return row == p.row && col == p.col; }
	int row, col;
};
#endif