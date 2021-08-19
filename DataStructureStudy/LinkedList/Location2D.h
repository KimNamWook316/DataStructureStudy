#ifndef __LOCATION2D_H__
#define __LOCATION2D_H__
class Location2D {
public:
	explicit Location2D(const int& r = 0, const int& c = 0) { mRow = r; mCol = c; }
	bool IsNeighbor(const Location2D& p) {
		return (p.mRow == mRow && (p.mCol == mCol - 1 || p.mCol == mCol + 1) ||
			(p.mCol == mCol) && (p.mRow == mRow - 1 || p.mRow == mRow + 1));
	}
	bool operator == (const Location2D& p) { return mRow == p.mRow && mCol == p.mCol; }
	
	int GetRow() { return mRow; }
	int GetCol() { return mCol; }

protected:
	int mRow, mCol;
};
#endif