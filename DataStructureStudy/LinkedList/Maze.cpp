#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Maze.h"

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
		delete[] mMap[i];
	}
	delete[] mMap;
}

void Maze::Load(const char* fName) {
	if (mMap) {
		Reset();
	}

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, fName, "rt");
	if (0 == err) {
		char buff[40];
		int nLine = 0;;
		while (!feof(fp)) {
			fgets(buff, sizeof(buff), fp);
			if (0 == nLine) {
				char* context = nullptr;
				char* tok = strtok_s(buff, " ", &context);
				mWidth = atoi(tok);
				mHeight = atoi(context);

				printf("%d\n", mWidth);
				printf("%d\n", mHeight);
			}

			++nLine;
		}

		fclose(fp);
	} else {
		printf("Failed to load map data...\n");
		exit(1);
	}
}

void Maze::Print() {
	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			switch (mMap[i][j]) {
			case 0:
				printf("¡á");
				break;
			case 1:
				printf("  ");
				break;
			case 5:
				printf("¡Û");
				break;
			case 9:
				printf("¡Ý");
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
}
