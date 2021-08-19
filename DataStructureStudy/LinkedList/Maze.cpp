#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Maze.h"
#include "LocationStack.h"
#include "define.h"

Maze::Maze() {
	Init(0, 0);
}

Maze::~Maze() {
	Reset();
}

void Maze::Init(const int& w, const int& h) {
	mWidth = w;
	mHeight = h;
	mMap = new int* [mHeight];
	for (int i = 0; i < mHeight; ++i) {
		mMap[i] = new int[mWidth];
	}
}

void Maze::Reset() {
	for (int i = 0; i < mHeight; ++i) {
		SAFE_DELETE(mMap[i]);
	}
	SAFE_DELETE_ARR(mMap);
	SAFE_DELETE(mEntryLoc);
	SAFE_DELETE(mExitLoc);
}

void Maze::Load(const char* fName) {
	if (mMap) {
		Reset();
	}

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, fName, "rt");
	if (0 == err) {
		char buff[41];
		int nLine = 0;;
		while (!feof(fp)) {
			fgets(buff, sizeof(buff), fp);
			char* context = nullptr;
			char* tok = strtok_s(buff, " ", &context);
			if (0 == nLine) {
				int w = atoi(tok);
				int h = atoi(context);
				Init(w, h);
			} else {
				for (int i = 0; i < mWidth; ++i) {
					int element = -1;
					if (0 == i) {
						element = atoi(tok);
						mMap[nLine - 1][i] = element;
					} else {
						tok = strtok_s(nullptr, " ", &context);
						element = atoi(tok);
						mMap[nLine - 1][i] = element;
					}
					// entryPos
					if (5 == element) {
						mEntryLoc = new LocationNode(nLine - 1, i);
					}
					// exitPos
					if (9 == element) {
						mExitLoc = new LocationNode(nLine - 1, i);
					}
				}
			}
			++nLine;
		}
		fclose(fp);
	} else {
		printf("Failed to read map data...\n");
		exit(1);
	}
}

void Maze::Print() {
	printf("전체 미로의 크기 = %d x %d\n", mWidth, mHeight);
	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			switch (mMap[i][j]) {
			case 0:
				printf("■");
				break;
			case 1:
				printf("  ");
				break;
			case 2:
				printf("☆");
				break;
			case 5:
				printf("○");
				break;
			case 9:
				printf("◎");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
}

void Maze::SearchExit() {
	dfsSearch();
}

bool Maze::isValidLoc(const int& r, const int& c) {
	if (r < 0 || r > mHeight - 1 || c < 0 || c > mWidth - 1) return false;
	return (1 == mMap[r][c]) || (9 == mMap[r][c]);
}

void Maze::bfsSearch() {

}

void Maze::dfsSearch() {
	LocationStack stack;
	LocationNode* curLoc = new LocationNode(mEntryLoc->GetRow(), mEntryLoc->GetCol());
	stack.Push(curLoc);
	
	while (!stack.IsEmpty()) {
		curLoc = stack.Pop(); 

		if (9 == mMap[curLoc->GetRow()][curLoc->GetCol()]) {
			break;
		}
		
		if (isValidLoc(curLoc->GetRow() - 1, curLoc->GetCol())) {
			LocationNode* pos = new LocationNode(curLoc->GetRow() - 1, curLoc->GetCol());
			stack.Push(pos);
		}
		if (isValidLoc(curLoc->GetRow() + 1, curLoc->GetCol())) {
			LocationNode* pos = new LocationNode(curLoc->GetRow() + 1, curLoc->GetCol());
			stack.Push(pos);
		}
		if (isValidLoc(curLoc->GetRow(), curLoc->GetCol() - 1)) {
			LocationNode* pos = new LocationNode(curLoc->GetRow(), curLoc->GetCol() - 1);
			stack.Push(pos);
		}
		if (isValidLoc(curLoc->GetRow(), curLoc->GetCol() + 1)) {
			LocationNode* pos = new LocationNode(curLoc->GetRow(), curLoc->GetCol() + 1);
			stack.Push(pos);
		}		
		
		mMap[curLoc->GetRow()][curLoc->GetCol()] = 2;

		SAFE_DELETE(curLoc);
	}
}
