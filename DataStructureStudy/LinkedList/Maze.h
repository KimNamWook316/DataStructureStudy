#pragma once
#include "Location2D.h"
class Maze {
public:
	explicit Maze();
	~Maze();

	void Init(const int& w, const int& h);
	void Reset();
	void Load(const char* fName);
	void Print();
	void SearchExit();

private:
	int mWidth;
	int mHeight;
	int** mMap;
	Location2D mExitLoc;
};

