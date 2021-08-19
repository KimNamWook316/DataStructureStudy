#pragma once

class LocationNode;

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
	bool isValidLoc(const int& r, const int& c);
	void bfsSearch();
	void dfsSearch();
	
	int mWidth;
	int mHeight;
	int** mMap;

	LocationNode* mEntryLoc;
	LocationNode* mExitLoc;
};

